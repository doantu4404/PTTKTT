#include <iostream>
using namespace std;

// Hàm chia mảng thành 2 phần, trả về chỉ số của phần tử chốt
int partition(int arr[], int start, int end)
{
    int pivot = arr[start]; // Chọn phần tử chốt là phần tử đầu tiên trong mảng

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Đặt phần tử chốt vào vị trí đúng của nó
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

// Hàm sắp xếp nhanh
void quickSort(int arr[], int start, int end)
{
    // Trường hợp cơ bản, nếu mảng chỉ có 0 hoặc 1 phần tử thì không cần sắp xếp
    if (start >= end)
        return;

    // Chia mảng thành 2 phần và lấy chỉ số của phần tử chốt
    int p = partition(arr, start, end);

    // Sắp xếp phần trái của phần tử chốt
    quickSort(arr, start, p - 1);

    // Sắp xếp phần phải của phần tử chốt
    quickSort(arr, p + 1, end);
}

int main()
{
    int n;
    cout << "Nhập số lượng phần tử trong mảng: ";
    cin >> n;

    int arr[n];
    cout << "Nhập các phần tử của mảng: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Gọi hàm sắp xếp nhanh
    quickSort(arr, 0, n - 1);

    cout << "Mảng sau khi sắp xếp: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
