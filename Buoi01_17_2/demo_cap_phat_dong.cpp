//
// Created by Felix Ngo on 17/2/25.
//

#include <iostream>
using namespace std;

int main() {
    int* p = new int;
    // int* p = new int(78); vua cap phai + khoi tao gia tri
    cout << p << endl;
    cout << "Test 1: " << p << endl;
    *p = 10;
    cout << *p << endl;

    delete p;
    p = NULL;
    cout << "Test 2: " << p << endl;
    cout << *p << endl;

    return 0;
}