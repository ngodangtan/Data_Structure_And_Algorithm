//
// Created by Ngo Dang Tan on 21/4/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
#include <time.h>
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

double calTime(int a[], int n, int loai) {
    if (loai == 1) {
        clock_t s = clock();
        selectionSort(a, n);
        clock_t e = clock();
        return (double)(e - s)/CLOCKS_PER_SEC;
    } else if (loai == 2) {
        clock_t s = clock();
        //insertionSort(a, n);
        clock_t e = clock();
        return (double)(e - s)/CLOCKS_PER_SEC;
    }
}

void initDataArr100k(int a[], int& n) {
    n = 100000;
    for (int i = 0; i < n; i++) {
        a[i] = rand() + (rand()%1000)/1000;
    }
}

void printArr(float a[], int& n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

const int N = 1e6;
int a[N];
int main() {
    srand(123);
    float a[N];
    int n = 0;

    initDataArr100k(a,n);
    printArr(a,n);

    return 0;
}