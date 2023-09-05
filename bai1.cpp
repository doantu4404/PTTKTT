#include <iostream>
using namespace std;
void doi_tien(int tien) { 
    int dong_xu[4] = {5000, 2000, 1000, 500}; 
    int soluong[4] = {0}; 
    for (int i = 0; i < 4; i++) { 
        if (tien >= dong_xu[i]) { 
            soluong[i] = tien / dong_xu[i]; 
            tien = tien % dong_xu[i];
        }
}
cout << "So luong dong xu can doi: " << endl;
for (int i = 0; i < 4; i++) { 
    if (soluong[i] > 0) { 
        cout << soluong[i] << " dong xu " << dong_xu[i] << endl;
        } 
    }
}
int main() { 
    int tien; 
    cout << "Nhap so tien can doi: ";
    cin >> tien; 
    doi_tien(tien); 
return 0;
}