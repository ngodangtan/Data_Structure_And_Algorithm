//
// Created by Ngo Dang Tan on 21/4/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
  int m;
  for (int i = 0; i < n - 1; i++) {
    m = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[m]) {
        m = j;
      }
    }
    if (m!=i) {
      swap(a[m], a[i]);
    }
  }
}

void printArr(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  int a[] = {3,7,1,9,6,8,3,5};
  int n = 8;
  printArr(a, n);
  selectionSort(a,n);
  printArr(a,n);
  return 0;
}