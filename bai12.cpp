#include <iostream>
#include <vector>
using namespace std;

// Hàm tìm giá trị lớn nhất có thể đạt được
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    // Tạo bảng lưu giá trị tối đa có thể đạt được
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Xây dựng bảng dp theo phương pháp quy hoạch động
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            // Nếu khối lượng của đồ vật i vượt quá khả năng chứa của túi, không chọn đồ vật này
            if (weights[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            // Nếu khối lượng đồ vật i nhỏ hơn hoặc bằng khả năng chứa của túi, xem xét lựa chọn
            else {
                // So sánh giữa không chọn đồ vật i và chọn đồ vật i
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }
        }
    }

    return dp[n][W]; // Trả về giá trị tối đa có thể đạt được
}

int main() {
    int W; // Khối lượng tối đa của túi
    cout << "Nhập vào khối lượng tối đa của túi: ";
    cin >> W;

    int n;
    cout << "Nhập số lượng loại đồ vật: ";
    cin >> n;
    vector<int> val(n), wt(n);
    cout << "Nhập giá trị và khối lượng của các loại đồ vật:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Đồ vật " << i + 1 << ": ";
        cin >> val[i] >> wt[i];
    }
    cout << "Giá trị lớn nhất có thể đạt được: " << knapsack(W, wt, val, n);
    return 0;
}
