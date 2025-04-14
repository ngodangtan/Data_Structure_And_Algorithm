//
// Created by Ngo Dang Tan on 14/4/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

void printArr(int* a, int n) {
  for(int i = 0; i < n; i++) {
    //    cout << &a[i] << " : " << a[i] << endl;;
    cout << *(a+i) << endl;
  }
}

bool linearSearch(int* a, int n, int value) {
  for(int i = 0; i < n; i++) {
    if(*(a+i) == value)
      return a+i;
  }
  return NULL;
}

bool linearSearch2(int a[], int n, int value) {
  for(int i = 0; i < n; i++) {
    if(a[i] == value)
      return true;
  }
  return false;
}

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

int* binarySearch2(int *a, int n , int value) {
  int L = 0, R = n -1, M;
  while(L <= R) {
    M = (L + R) / 2;
    if(*(a + M) == value) {
      return a + M;
    }

    if(value < *(a + M)) {
      R = M - 1;
    } else if(value > *(a + M)) {
      L = M+ 1;
    }
  }
  return NULL;
}

int main() {
  int a[] = {10, 9, 5 , 6, 7, 8, 4};
  int n = 6;
  printArr(a, n);
  cout << "Test: Linear Search" << endl;
  cout << "Ket qua tim 8(.): " << linearSearch(a, n, 8) << endl;
  cout << "Ket qua tim 4(.: " << linearSearch(a, n, 4) << endl;

  int b[] = {10, 15, 36 , 58, 62, 97};
  int m = 6;
  printArr(b, m);
  cout << "Test: Binary Search" << endl;
  cout << "Ket qua tim 8(.): " << binarySearch(b, m, 36) << endl;
  cout << "Ket qua tim 4(.: " << binarySearch(b, m, 40) << endl;
  return 0;
}