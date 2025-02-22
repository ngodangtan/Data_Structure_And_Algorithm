//
// Created by Tan Ngo on 17/2/25.
//

#include <iostream>
using namespace std;

int main() {
   int x = 10;
   cout << "x = " << *(&x) << endl; // toan tu sao dung truoc dia chi => ra gia tri
   cout << "Dia chi " << &x << endl; // lay dia chi vung nho

   // luu tru dia chi
   int* p = &x; // p la kieu con tro luu tru dia chi cua vung nho, luu y bo * thi thanh kieu int

   int y = 20;
   p = &y;
   cout << "p = " << *p << endl;

   int* p1, p2, p3; // luu y p1 moi la con tro, p2, p3 la kieu int
   int* p4, *p5; // khai bao nhieu con tro
   return 0;
}
