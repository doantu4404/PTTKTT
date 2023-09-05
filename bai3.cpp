#include <iostream>
#include <algorithm>
using namespace std;
struct Activity{
    int batdau, hoanthanh;
    };
bool compareActivity(Activity a, Activity b){
return a.hoanthanh < b.hoanthanh;
}
void printMaxActivities(Activity activities[], int n){
// Sắp xếp các hoạt động theo thời gian kết thúc
sort(activities, activities+n, compareActivity);
int i = 0;
cout << "Hoat dong da chon: ";
// Hoạt động đầu tiên luôn được chọn
cout << "(" << activities[i].batdau << ", " << activities[i].hoanthanh << "), ";
// Xem xét tất cả các hoạt động còn lại
    for (int j = 1; j < n; j++){
     // Nếu hoạt động này có thời gian bắt đầu lớn hơn hoặc bằng thời gian kết thúc của hoạt động trước đó
     // hoạt động đã chọn, sau đó chọn nó
        if (activities[j].batdau >= activities[i].hoanthanh){ 
            cout << "(" << activities[j].batdau << ", " << activities[j].hoanthanh << "), "; 
            i = j;
        }
    }
}
int main(){
int n = 9;
Activity activities[] = {
    {1, 3}, {2, 4}, {4, 6}, {3, 8}, {6, 10}, {4, 13}, {10, 14}, {12, 15}, {11, 16}
};
printMaxActivities(activities, n);
return 0;
}