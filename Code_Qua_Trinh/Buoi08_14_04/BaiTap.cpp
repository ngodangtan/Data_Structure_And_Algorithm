//
// Created by Ngo Dang Tan on 14/4/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
#include <time.h>
using namespace std;

/* Viết hàm nhập giá trị tự động cho mảng, các giá trị thuộc [100;999],
số lượng phần tử thuộc [30;50]
 */
void initDataAuto(int a[], int& n) {
    n = 30 + rand()%21; // [30;50] = 30 + [0;20]
    for (int i = 0; i < n; i++) {
      a[i] = 100 + rand()%900;
    }
}

void printArr(int* a, int n) {
  cout << "Number: " << n << endl;
    for(int i = 0; i < n; i++) {
        //    cout << &a[i] << " : " << a[i] << endl;;
        cout << *(a+i) << endl;
    }
}

int main() {
  srand(time(0));
  int a[50];
  int n = 0;
  initDataAuto(a, n);
  printArr(a, n);
  return 0;
}