#include <stdio.h>

int dem_cach_phan_tich(int n, int max_so) {
    // Trường hợp cơ bản: nếu n = 0, tức đã tìm được một cách phân tích
    if (n == 0) {
        return 1;
    }

    int count = 0;

    // Liệt kê tất cả các số từ 1 đến max_so để thử thêm vào tổng
    for (int i = 1; i <= max_so; i++) {
        // Đảm bảo i không lớn hơn n
        if (i <= n) {
            // Đệ quy tìm số cách phân tích của n - i với max_so là i (giới hạn số lượng phần tử trong dãy phân tích)
            count += dem_cach_phan_tich(n - i, i);
        }
    }

    return count;
}

int main() {
    int n;
    printf("Nhap so n: ");
    scanf("%d", &n);

    int count = dem_cach_phan_tich(n, n);
    printf("So cach phan tich so %d la: %d\n", n, count);

    return 0;
}