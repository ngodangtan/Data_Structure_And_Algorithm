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

// Viết hàm thêm sinh viên vào đầu danh sách
void addHead(List &l, Node *p) {
  if (l.pHead == NULL) {
    l.pHead = p;
    l.pTail = p;
  } else {
    p->pNext = l.pHead;
    l.pHead = p;
  }
}

// Viết hàm thêm sinh viên vào cuối danh sách
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
  SinhVien sv9 = {131, "Nguyen Van L", 9.7, ""};

  addHead(dsSV, initNode(sv1));
  addHead(dsSV, initNode(sv2));
  addHead(dsSV, initNode(sv3));
  addHead(dsSV, initNode(sv4));
  addHead(dsSV, initNode(sv5));
  addHead(dsSV, initNode(sv6));
  addHead(dsSV, initNode(sv7));
  addHead(dsSV, initNode(sv8));
  addTail(dsSV, initNode(sv9));
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

/* Cau 9. Viet ham tìm điểm trung bình cao nhất
Input:
+ List dsSV => ds ban dau
Output:
+ return float điểm trung bình cao nhất
 */

float timDTBCaoNhat(List l) {
  float maxDTB = 0;
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    if(p->data.diemTB > maxDTB) {
      maxDTB = p->data.diemTB;
    }
  }
  return maxDTB;
}

/* Cau 10. Viet ham tìm sv theo mã sinh viên
Input:
+ List dsSV => ds ban dau
Output:
+ return SinhVien theo mã sinh viên truyền vào
 */

SinhVien timSVTheoMaSV(List l, int maSV) {
  SinhVien result;
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    if(p->data.maSV == maSV) {
      result = p->data;
    }
  }
  return result;
}

/* Cau 11. Viet ham tìm list sv có điểm TB cao nhất
Có thể có nhiều sv bằng điểm TB cao nhất
Input:
+ List dsSV => ds ban dau
Output:
+ return List => ds SinhVien có điểm TB cao nhất
 */

List timListSVCoDTBMax(List l) {
  float maxDTB = timDTBCaoNhat(l);
  List result;
  initList(result);
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    if(p->data.diemTB == maxDTB) {
      SinhVien sv = p->data;
      addHead(result, initNode(sv));
    }
  }
  return result;
}

/* Ham tìm điểm TB thấp nhất
Input:
+ List dsSV => ds ban dau
Output:
+ return float
 */

float timDTBThapNhat(List l) {
  float maxDTB = l.pHead->data.diemTB;
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    if(p->data.diemTB < maxDTB) {
      maxDTB = p->data.diemTB;
    }
  }
  return maxDTB;
}

List timListSVDTBThapNhat(List l) {
  float minDTB = timDTBThapNhat(l);
  List result;
  initList(result);
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    if(p->data.diemTB == minDTB) {
      SinhVien sv = p->data;
      addHead(result, initNode(sv));
    }
  }
  return result;
}


int main() {
  cout << "Cau 1-> 5. Khoi tao ds sv và add head, tail sinh viên " << endl;
  List dsSV;
  initList(dsSV);
  cout << "Test: Cau 6. Khoi tao ds sv: " << endl;
  initDataListSV(dsSV);
  cout << "Test: Cau 7. In danh sach sv" << endl;
  printListSV(dsSV);
  cout << "Test: Cau 8 . Cap nhat xep loai: " << endl;
  capNhatXL(dsSV);
  printListSV(dsSV);
  cout << "Test: Cau 9 . điểm trung bình cao nhất: " << timDTBCaoNhat(dsSV) << endl;
  cout << endl;
  cout << "Test: Cau 10 . Tìm Sinh viên có mã sv 125: " << endl;
  SinhVien svTim = timSVTheoMaSV(dsSV, 125);
  inSV(svTim);
  cout << endl;
  cout << "Test: Cau 11 . Tìm list sv có điểm TB cao nhất: " << endl;
  List dsDVMaxDTB = timListSVCoDTBMax(dsSV);
  printListSV(dsDVMaxDTB);
  cout << endl;
  cout << "Test: Cau 12 . Tìm list sv có điểm TB thấp nhất: " << endl;
  List dsSVMinDTB = timListSVDTBThapNhat(dsSV);
  printListSV(dsSVMinDTB);
  return 0;
}