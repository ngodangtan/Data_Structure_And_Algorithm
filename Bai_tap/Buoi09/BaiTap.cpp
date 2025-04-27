//
// Created by Ngo Dang Tan on 27/04/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
#include <time.h>
using namespace std;

// Viet ham khoi tao mang
void initArray(double a[], int& n) {
  n = 100000;
  for (int i = 0; i < n; i++) {
    a[i] = (double)(rand() % 1000000) / 1000.0;
  }
}

// Viet ham in mang
void printArr(double* a, int n) {
  cout << "Number: " << n << endl;
  for(int i = 0; i < n; i++) {
    //    cout << &a[i] << " : " << a[i] << endl;;
    cout << *(a+i) << endl;
  }
}

// Ham sap xep lai mang theo phuong phap selection sort
void selectionSort(double a[], int n)
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

// Ham Sắp xếp tăng dần bằng Insertion Sort
void insertionSort(double a[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int item = a[i];
    int j;
    for (j = i - 1; j >= 0; j--)
    {
      if (a[j] < item)
        break;

      a[j + 1] = a[j];
    }
    a[j + 1] = item;
  }
}

/* Hàm đo thời gian tính toán của CPU
Input: a[], int n
Output: return double
 */
double sort_time(double a[], int n)
{
  clock_t start, end;
  double cpu_time_used;

  start = clock();

  selectionSort(a, n);

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  return cpu_time_used;
}

int main() {
  srand(time(0));

  const int SIZE = 1000000;
  double a[SIZE];
  int n = 0;

  initArray(a, n);
  cout << "Da khoi tao mang arrayA voi " << n << " phan tu!" << endl;

  printArr(a, n);

  cout << "Dang tinh thoi gian selection sort (tang dan)..." << endl;
  double timeSelection = sort_time(a, n);
  cout << "Selection Sort (tang dan) thuc hien mat: " << timeSelection << " giay" << endl;

  // Cần khởi tạo lại dữ liệu nếu tiếp tục test insertion sort, vì arrayA đã bị thay đổi
  initArray(a, n);

  cout << "Dang tinh thoi gian insertion sort (tang dan)..." << endl;
  double timeInsertion = sort_time(a, n);
  cout << "Insertion Sort (tang dan) thuc hien mat: " << timeInsertion << " giay" << endl;


  return 0;
}