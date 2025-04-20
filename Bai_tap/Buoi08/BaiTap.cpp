//
// Created by Ngo Dang Tan on 18/04/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
#include <time.h>
using namespace std;

// Ham tao mang tu dong
void initDataAuto(int a[], int& n) {
    n = 30 + rand()%21; // [30;50] = 30 + [0;20]
    for (int i = 0; i < n; i++) {
      a[i] = 100 + rand()%900;
    }
}

// Viet ham in mang
void printArr(int* a, int n) {
  cout << "Number: " << n << endl;
    for(int i = 0; i < n; i++) {
        //    cout << &a[i] << " : " << a[i] << endl;;
        cout << *(a+i) << endl;
    }
}

/* Viet ham tim gia tri trong mang bang tim kiem tuyen tinh
Input: int a[], int n, int value
Output: return bool
 */
bool timValueTheoTuyenTinh(int a[], int n, int value) {
  for (int i = 0; i < n; i++) {
    if(value == a[i]) {
      return true;
    }
  }
  return false;
}

/* Ham tim kiem gia tri theo phuong phap nhi phan
Input: int a[], int n, int value
Output: return bool
 */
bool binarySearch(int a[], int n , int value) {
  int L = 0, R = n -1, M;
  while(L <= R) {
    M = (L + R) / 2;
    if(a[M] == value) {
      return true;
    }

    if(value < a[M]) {
      R = M - 1;
    } else if(value > a[M]) {
      L = M+ 1;
    }
  }
  return false;
}

// Ham sap xep lai mang theo phuong phap selection sort
void selectionSort(int a[], int n)
{
  int m;
  for (int i = 0; i < n-1; i++)
  {
    m = i;
    for (int j = i+1; j < n; j++)
    {
      if (a[j] < a[m])
        m = j;
    }
    if(m != i)
      swap(a[i], a[m]);
  }
}

/* Ham tim kiem noi suy
Input: a[], int n, int value
return bool
 */
bool timKiemNoiSuy(int a[], int n, int value) {
  int low = 0, high = n - 1;

  while (low <= high && value >= a[low] && value <= a[high]) {
    if (a[low] == a[high]) {
      return a[low] == value;
    }

    int pos = low + ((double)(value - a[low]) * (high - low)) / (a[high] - a[low]);

    if (a[pos] == value)
      return true;
    else if (a[pos] < value)
      low = pos + 1;
    else
      high = pos - 1;
  }

  return false;
}

int main() {
  srand(time(0));
  int a[50];
  int n = 0;
  initDataAuto(a, n);
  printArr(a, n);

  cout << "--------------------------------------" << endl;
  cout << "Test tim gia tri theo phuong phap tuyen tinh: a[1] (1): " << timValueTheoTuyenTinh(a, n, a[1]) << endl;
  cout << "Test tim gia tri theo phuong phap tuyen tinh: 1 (0): " << timValueTheoTuyenTinh(a, n, 0) << endl;
  cout << "--------------------------------------" << endl;
  cout << "Test tim gia tri theo phuong phap nhi phan: a[1] (1): " << timValueTheoTuyenTinh(a, n, a[1]) << endl;
  cout << "Test tim gia tri theo phuong phap nhi phan: 1 (0): " << timValueTheoTuyenTinh(a, n, 0) << endl;
  cout << "--------------------------------------" << endl;
  selectionSort(a, n);
  cout << "Test tim gia tri theo phuong phap noi suy: a[1] (1): " << timKiemNoiSuy(a, n, a[1]) << endl;
  cout << "Test tim gia tri theo phuong phap noi suy: 1 (0): " << timKiemNoiSuy(a, n, 0) << endl;
  return 0;
}