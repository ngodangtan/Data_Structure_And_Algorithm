//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

struct SinhVien {
  int maSV;
  string hoTen;
  float diemMH;
};

void inSV(SinhVien sv) {
  cout << "Thong tin sv: " << endl;
  cout << "\t + Ma sv : "  << sv.maSV << endl;
  cout << "\t + Ho Ten : "  << sv.hoTen << endl;
  cout << "\t + Diem TB: "  << sv.diemMH << endl;
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
bool addTail(List &l, Node *p) {
  bool isSuccess = false;
  if (l.pHead == NULL) {
    l.pHead = p;
    l.pTail = p;
    isSuccess = true;
  } else {
    l.pTail->pNext = p;
    l.pTail = p;
    isSuccess = true;
  }
  return isSuccess;
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
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    if (maSV == p->data.maSV) {
      return p;
    }
  }
  return NULL;
}

/* Câu 4: Viết hàm đếm sinh viên có điểm môn học dưới trung bình
Input: List dsSV
Output: return List => ds SV có DTB thấp nhất, có thê có nhiều sv bằng điểm nhau
 */
int demSVCoDiemMonHocDuoiTB(List l) {
  int dem = 0;
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    if(p->data.diemMH < 5) {
      dem++;
    }
  }
  return dem;
}

/* Câu 5: Viết hàm tính điểm trung bình của cả lớp
Input: List dsSV
Output: return float
 */
float diemTBCaLop(List l) {
  float diemTB = 0;
  int sl;
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    sl++;
    diemTB += p->data.diemMH;
  }

  return diemTB/sl;
}

/* Câu 6: Viết hàm tìm sv đầu tiên có ĐTB cao nhất
Input: List sv
Output: return Node
 */
Node* svFirstMaxDiemMH(List l) {
  float diemMaxMH = 0;
  Node *result = NULL;
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    if (p->data.diemMH > diemMaxMH) {
      diemMaxMH = p->data.diemMH;
    }
  }

  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    if (p->data.diemMH == diemMaxMH) {
      result = p;
      break;
    }
  }

  return result;
}

/* Câu 7: Viết hàm trả về các mã sv có điểm MH > 8
Input: List sv
Output: return List
 */
List timListSVDMHTrenTam(List l) {
  List result;
  initList(result);
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    if(p->data.diemMH > 8.0) {
      SinhVien sv = p->data;
      addHead(result, initNode(sv));
    }
  }
  return result;
}

/* Câu 8: Viết hàm cập nhật điểm môn học theo mã SV
Input: List sv
 */
void updateDiemMHByMSV(List& l, int maSV, float newDiemMH) {
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    if (maSV == p->data.maSV) {
      p->data.diemMH = newDiemMH;
      break;
    }
  }
}

/* Câu 9: Viết hàm sao chép toàn bộ sinh viên sang một danh sách mới
   Input: List sv (danh sách ban đầu)
   Output: List (danh sách mới chứa các sinh viên đã sao chép) */
List copyListSV(List l) {
  // Khởi tạo danh sách mới rỗng
  List newList;
  initList(newList);

  // Duyệt qua danh sách ban đầu và sao chép từng node
  for (Node *p = l.pHead; p != NULL; p = p->pNext) {
    // Tạo node mới với dữ liệu của node hiện tại
    Node* newNode = initNode(p->data);
    // Thêm node mới vào cuối danh sách mới
    addTail(newList, newNode);
  }
  return newList;
}

int main() {
  List dsSV;
  initList(dsSV);

  cout << "Test: Câu 10. Tạo dữ liệu sinh viên:" << endl;
  SinhVien sv1 = {123, "Nguyen Van A", 9.1};
  SinhVien sv2 = {124, "Nguyen Van B", 8.8};
  SinhVien sv3 = {125, "Nguyen Van C", 9.1};
  SinhVien sv4 = {126, "Nguyen Van D", 2.1};
  SinhVien sv5 = {127, "Nguyen Van F", 9.7};
  SinhVien sv6 = {128, "Nguyen Van G", 4.1};
  SinhVien sv7 = {129, "Nguyen Van H", 8.3};
  SinhVien sv8 = {130, "Nguyen Van K", 7.9};
  cout << "Test: Câu 1. Thêm sinh viên vào danh sách:" << endl;
  if (!addTail(dsSV, initNode(sv1))) {
    cout << "Thêm node thất bại sv1" << endl;
  }

  if (!addTail(dsSV, initNode(sv2))) {
    cout << "Thêm node thất bại sv2" << endl;
  }

  if (!addTail(dsSV, initNode(sv3))) {
    cout << "Thêm node thất bại sv3" << endl;
  }
  if (!addTail(dsSV, initNode(sv4))) {
    cout << "Thêm node thất bại sv4" << endl;
  }

  if (!addTail(dsSV, initNode(sv5))) {
    cout << "Thêm node thất bại sv5" << endl;
  }

  if (!addTail(dsSV, initNode(sv6))) {
    cout << "Thêm node thất bại sv6" << endl;
  }

  if (!addTail(dsSV, initNode(sv7))) {
    cout << "Thêm node thất bại sv7" << endl;
  }

  if (!addTail(dsSV, initNode(sv8))) {
    cout << "Thêm node thất bại sv8" << endl;
  }

  cout << "\n\nTest: Cau 2. In danh sach sv" << endl;
  printListSV(dsSV);

  cout << "\n\nTest: Cau 3. Tim sinh vien theo maSV:" << endl;
  cout << "\+ Tim sv(123): " << timSVTheoMaSV(dsSV, 123) << endl;

  cout << "\n\nTest: Cau 4. Đếm SV có điểm môn học dưới trung bình: " << demSVCoDiemMonHocDuoiTB(dsSV) << endl;

  cout << "\n\nTest: Cau 5. Điểm trung bình cua cả lớp: " << diemTBCaLop(dsSV) << endl;

  cout << "\n\nTest: Cau 6. SV đầu tiên có điểm MH cao nhat: " << svFirstMaxDiemMH(dsSV)->data.hoTen << endl;

  cout << "\n\nTest: Cau 7. List SV có điểm MH > 8: " << endl;
  List dsSVMaxAbove8;
  initList(dsSVMaxAbove8);
  dsSVMaxAbove8 = timListSVDMHTrenTam(dsSV);
  printListSV(dsSVMaxAbove8);

  cout << "\n\nTest: Câu 8. Update điểm MH them mã SV: điểm MH: 6 MSV: 128" << endl;
  updateDiemMHByMSV(dsSV,128,6.0);
  cout << "\n\nTest: Câu 8. Update điểm MH them mã SV: điểm MH: 4 MSV: 123" << endl;
  updateDiemMHByMSV(dsSV,123,4.0);
  cout << "Ds sv sau khi update diem MH" << endl;
  printListSV(dsSV);

  cout << "\n\nTest: Câu 9 sao chép dsSV qua một List mới" << endl;
  List listCopy = copyListSV(dsSV);
  cout << "\n\nTest: Câu 9 List mới sau khi sao ché[" << endl;
  printListSV(listCopy);
  return 0;
}