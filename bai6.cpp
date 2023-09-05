#include <iostream>
using namespace std;
const int n=8;
int a[n][n]={0}; // Khởi tạo các ô trống bàn cờ
bool check(int row,int col)
{ 
    for(int i=0;i<row;i++) // Kiểm tra hàng 
    if(a[i][col]==1) 
    return false; 
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--) // Kiểm tra đường chéo trái 
    if(a[i][j]==1) 
    return false; 
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++) // Kiểm tra đường chéo phải 
    if(a[i][j]==1) 
    return false;
    return true;}
    void print()
    {
        static int count=0; 
        cout<<"Solution: "<<++count<<endl; 
        for(int i=0;i<n;i++) 
        { 
            for(int j=0;j<n;j++) 
                cout<<a[i][j]<<" "; 
                cout<<endl; 
            }
        }
        void queen(int row)
    { 
        if(row==n) // Nếu đặt đủ 8 quân hậu mà không xung đột với nhau 
        {
print(); 
return; 
} 
for(int col=0;col<n;col++) // Duyệt từng vị trí trên hàng 
{ 
    if(check(row,col)) // Nếu vị trí đó không xung đột với những quân hậu khác 
    { a[row][col]=1; // Thực hiện đặt quân hậu vào vị trí  
    queen(row+1); // Đặt quân hậu tiếp theo 
    a[row][col]=0; // Quay lui trạng thái về trước đó để thử vị trí mới cho quân hậu 
        } 
    }
}
int main()
{ 
    queen(0); // Bắt đầu đặt các quân hậu từ hàng đầu tiên 
    return 0;
}