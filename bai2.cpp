#include <iostream>
#include <algorithm>
using namespace std;
struct MatHang {
    int trongLuong;
    float giaTri;
};
bool cmp(MatHang a, MatHang b) {
    return (a.giaTri/a.trongLuong > b.giaTri/b.trongLuong);
}
float phanSoCaiTui(MatHang a[], int n, int M) {
    sort(a, a+n, cmp); // sắp xếp mảng mặt hàng theo giá trị trọng lượng giảm dần 
    int w = 0; // trọng lượng của mặt hàng trong cái túi 
    float v = 0; // giá trị của mặt hàng trong cái túi
    for(int i = 0; i < n; i++) {
        if(w + a[i].trongLuong <= M) { // kiểm tra có thể chứa được mặt hàng không
            w += a[i].trongLuong; // cộng trọng lượng mặt hàng vào túi
            v += a[i].giaTri; // cộng giá trị mặt hàng vào túi
        }
        else { // nếu không thì chọn mặt hàng khác
            int pw = M - w; // trọng lượng còn trống trong cái túi
            v += (a[i].giaTri/a[i].trongLuong) * pw; // cộng giá trị của phần mặt hàng còn trống
            break; // kết thúc thuật toán
        }
    }
    return v;
}
int main() { 
    MatHang a[] = {{18, 25}, {15, 24}, {10, 25}}; 
    int n = sizeof(a)/sizeof(a[0]);
    int M = 20; // trọng lượng tối đa của cái túi 
    float result = phanSoCaiTui(a, n, M);
    cout << "Tong gia tri cua mat hang trong cai tui la: " << result << endl; 
    return 0;
}
