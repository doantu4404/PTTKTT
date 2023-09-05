#include <iostream>
#include <vector>
using namespace std;

void findSubsequences(vector<int> &arr, int index, int sum, vector<int> &subsequence, int M) {
    // Nếu tổng hiện tại bằng M
    if (sum == M) {
        // In ra dãy con
        for (int i = 0; i < subsequence.size(); i++)
            cout << subsequence[i] << " ";
        cout << endl;
        return;
    }
    // Nếu tổng hiện tại lớn hơn M hoặc đã duyệt hết mảng
    if (sum > M || index == arr.size())
        return;
    // Không chọn phần tử hiện tại
    findSubsequences(arr, index + 1, sum, subsequence, M);
    // Chọn phần tử hiện tại
    subsequence.push_back(arr[index]);
    findSubsequences(arr, index + 1, sum + arr[index], subsequence, M);
    subsequence.pop_back();
}

int main() {
    vector<int> arr = {7, 1, 4, 3, 5, 6};
    int M = 11;
    vector<int> subsequence;
    findSubsequences(arr, 0, 0, subsequence, M);
    return 0;
}
