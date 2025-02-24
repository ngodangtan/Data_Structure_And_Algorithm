//
// Created by Felix Ngo on 17/2/25.
//

#include <iostream>
using namespace std;

struct NhanVien {
  int maNV;
  string hoTen;
  float luongCB;
  int soNg;
  float luongHT;
};



int main() {
  NhanVien arrNV[100];
  int sl = 0;

  // Cau 1
  initArrNV(arrNV, sl);

  // Cau 2
  printArrNV(arrNV, sl);

  // Cau 3
  tinhLuongArrNV(arrNV, sl);
  printArrNV(arrNV, sl);
  return 0;
}