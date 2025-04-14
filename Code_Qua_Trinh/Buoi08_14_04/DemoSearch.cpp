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

bool linearSearch(int* a, int n) {

}

int main() {
  int a[] = {10, 9, 5 , 6, 7, 8, 4};
  int n = 6;
  printArr(a, n);
  return 0;
}