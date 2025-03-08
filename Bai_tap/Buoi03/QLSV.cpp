//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

struct SinhVien {
  int maSV;
  string hoTen;
  float diemTB;
  string xepLoai;
};

// Hàm in thông tin sinh viên
void inSV(SinhVien sv) {
  cout << "Thong tin sv: " << endl;
  cout << "\t + Ma sv : "  << sv.maSV << endl;
  cout << "\t + Ho Ten : "  << sv.hoTen << endl;
  cout << "\t + Diem TB: "  << sv.diemTB << endl;
  cout << "\t + Xep loai: "  << sv.xepLoai << endl;
}

// Buoc 01: Tạo cấu trúc Node
struct Node {
  SinhVien data;
  Node *pNext; // lưu trữ địa chỉ của Node phía sau
};

// Bước 2: Khởi tạo Node để lưu giá trị cần lưu.
Node* initNode(SinhVien value) {
  Node* p = new Node;
  p->data = value;
  p->pNext = NULL; // chứa lưu trữ địa chỉ Node tiếp theo, set = NULL
  return p;
}

// Bước 3: Tạo cấu trúc danh sách
struct List {
  Node* pHead;
  Node* pTail;
};

// Bước 4: Khởi tạo danh sách
void initList(List& l) {
  l.pHead = NULL;
  l.pTail = NULL;
}

void addHead(List &l, Node *p) {
  if (l.pHead == NULL) {
    l.pHead = p;
    l.pTail = p;
  } else {
    p->pNext = l.pHead;
    l.pHead = p;
  }
}

void addTail(List &l, Node *p) {
  if (l.pHead == NULL) {
    l.pHead = p;
    l.pTail = p;
  } else {
    l.pTail->pNext = p;
    l.pTail = p;
  }
}

void initDataListSV(List &dsSV)
{
  SinhVien sv1 = {123, "Nguyen Van A", 9.1, ""};
  SinhVien sv2 = {124, "Nguyen Van B", 8.8, ""};
  SinhVien sv3 = {125, "Nguyen Van C", 9.1, ""};
  SinhVien sv4 = {126, "Nguyen Van D", 2.1, ""};
  SinhVien sv5 = {127, "Nguyen Van F", 9.7, ""};
  SinhVien sv6 = {128, "Nguyen Van G", 4.1, ""};
  SinhVien sv7 = {129, "Nguyen Van H", 8.3, ""};
  SinhVien sv8 = {130, "Nguyen Van K", 7.9, ""};

  addHead(dsSV, initNode(sv1));
  addHead(dsSV, initNode(sv2));
  addHead(dsSV, initNode(sv3));
}

// Cau 7: Viet ham in danh sach sinh vien
void printListSV(List l) {
  if (l.pHead == NULL) {
    cout << "List is empty" << endl;
    return;
  }
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    inSV(p->data);
  }
  cout << endl << endl;
}

/* Cau 8. Viet ham cap nhat xep loai hoc luc
Input:
+ List dsSV => ds ban dau
Output:
+ List &dsSV => ds da cap nhat => ref
 */
void capNhatXL(List& l) {
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    if(p->data.diemTB > 9) {
      p->data.xepLoai = "Xuat xac";
    }
  }
}

int main() {
  List dsSV;
  initList(dsSV);
  cout << "Test: Cau 6. Khoi tao ds sv: " << endl;
  initDataListSV(dsSV);
  cout << "Test: Cau 7. In danh sach sv" << endl;
  printListSV(dsSV);
  cout << "Test: Cau 8 . Cap nhat xep loai: " << endl;
  capNhatXL(dsSV);
  printListSV(dsSV);
  return 0;
}