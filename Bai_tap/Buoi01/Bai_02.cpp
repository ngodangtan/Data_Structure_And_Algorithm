//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

/* Hàm tạo mảng
Input: double arr, size mảng
 */
void createMang(double* &arr, int &size) {
  size = 10;
  arr = new double[size] {0.8, 5.6, 9.1, 7.3, 10, 5.9, 7.2, 9.3, 8.0, 8.7};
}

/* Hàm in mảng
Input: double arr, size mảng
 */
void printMang(double* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  int n = 0; //kích thước mảng
  double* arr = new double[n];
  cout << "---------Bai 01---------" << endl;
  cout << "Câu 1: Tạo mảng số thực" << endl;
  createMang(arr, n);
  cout << "Câu 2: In mảng số thực" << endl;
  printMang(arr,n);
  return 0;
}
