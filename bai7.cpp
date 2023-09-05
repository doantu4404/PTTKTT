#include <iostream>
#include <vector>

using namespace std;

int countPartitions(int n, int maxValue) {
    // Trường hợp cơ bản: n = 0, chỉ có một cách phân tích là không có số nào
    if (n == 0) {
        return 1;
    }

    int count = 0;
    for (int i = 1; i <= maxValue && i <= n; i++) {
        // Đệ quy để tìm cách phân tích số n - i với giới hạn giá trị i
        count += countPartitions(n - i, i);
    }

    return count;
}

int main() {
    int n;
    cout << "Nhap vao so nguyen n: ";
    cin >> n;

    int totalCount = countPartitions(n, n);
    cout << "So cach phan tich " << n << " thanh tong cua day cac so nguyen duong la: " << totalCount << endl;

    return 0;
}
