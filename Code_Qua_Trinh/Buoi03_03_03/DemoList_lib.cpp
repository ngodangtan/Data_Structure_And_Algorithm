//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include "iostream"
#include "forward_list"
using namespace std;

struct SinhVien {
  int maSV;
  string hoTen;
  float diemTB;
  string xepLoai;
};


int main(){
  forward_list<int> ds;
  ds.push_front(10);
  ds.push_front(20);
  ds.push_front(30);
  ds.push_front(40);
  ds.push_front(50);
  for(int i: ds) {
    cout << i << endl;
  }

  forward_list<SinhVien> dsSV;
  return 0;
}