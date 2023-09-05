#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 25; // giả sử chiều rộng của bàn cờ không quá 20
int n, x0, y0, count = 1;
bool visited[MAXN][MAXN];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; // 8 hướng di chuyển của con mã
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool in_board(int x, int y) { 
    return x >= 1 && x <= n && y >= 1 && y <= n;
}
bool move(int x, int y, int count) {
    visited[x][y] = true; 
if (count == n*n) // đã đi đến ô cuối cùng 
    return true; 
for (int i = 0; i < 8; i++) { 
    int x_new = x + dx[i]; 
    int y_new = y + dy[i]; 
    if (in_board(x_new, y_new) && !visited[x_new][y_new]) { 
        if (move(x_new, y_new, count+1)) 
            return true; 
    } 
} 
visited[x][y] = false; 
return false;
}
int main() { 
    cout << "Nhap chieu rong cua ban co: "; 
    cin >> n; 
    cout << "Nhap toa do x0, y0 cua con ma: "; 
    cin >> x0 >> y0; 
    memset(visited, false, sizeof visited); 
    move(x0, y0, 1); // đi tới ô (x0, y0) và đã đi qua 1 ô. 
    // In kết quả: 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) {
            cout << visited[i][j] << " "; 
        } 
        cout << endl; 
    } 
    return 0;
}