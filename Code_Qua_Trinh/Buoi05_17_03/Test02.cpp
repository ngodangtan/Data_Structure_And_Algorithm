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
/* Câu 1. Hàm chèn node chứa sinh viên vào cuối
Input:
+ List& l
+ Node* p
Output:
+ List l
+ bool
 */
void addTail(List &l, Node *p) {
  if (l.pHead == NULL) {
    l.pHead = p;
    l.pTail = p;
  } else {
    l.pTail->pNext = p;
    l.pTail = p;
  }
}

// Cau 2: Viet ham in danh sach sinh vien
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

/* Câu 3. Viết hàm tìm sinh viên
Input:
+ List l
+ int maSV
Output:
+ return Node*
 */

Node* timSVTheoMaSV(List l, int maSV) {

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

  SinhVien sv1 = {123, "Nguyen Van A", 9.1, ""};
  SinhVien sv2 = {124, "Nguyen Van B", 8.8, ""};
  SinhVien sv3 = {125, "Nguyen Van C", 9.1, ""};
  SinhVien sv4 = {126, "Nguyen Van D", 2.1, ""};
  SinhVien sv5 = {127, "Nguyen Van F", 9.7, ""};
  SinhVien sv6 = {128, "Nguyen Van G", 4.1, ""};
  SinhVien sv7 = {129, "Nguyen Van H", 8.3, ""};
  SinhVien sv8 = {130, "Nguyen Van K", 7.9, ""};
  cout << "Test: Câu 1. Thêm sinh viên vào danh sách:" << endl;
  addTail(dsSV, initNode(sv1));
  addTail(dsSV, initNode(sv2));
  addTail(dsSV, initNode(sv3));

  cout << "\n\nTest: Cau 2. In danh sach sv" << endl;
  printListSV(dsSV);

  cout << "\n\nTest: Cau 3. Tim sinh vien theo maSV:" << endl;
  cout << "\+ Tim sv(123): " << timSVTheoMaSV(dsSV, 123) << endl;

  cout << "Test: Cau 8 . Cap nhat xep loai: " << endl;
  capNhatXL(dsSV);
  printListSV(dsSV);
  return 0;
}