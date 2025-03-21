//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

// Câu 1: Xây dựng cấu trúc dữ liệu SinhVien
struct SinhVien {
    int maSV;
    string hoTen;
    float diemTB;
    string xepLoai;
};

void inSV(SinhVien sv) {
    cout << "[" << sv.maSV << "," << sv.hoTen << "," << sv.diemTB << "," << sv.xepLoai << "]" << endl;
//    cout << "Thong tin sv: " << endl;
//    cout << "\t + Ma sv : "  << sv.maSV << endl;
//    cout << "\t + Ho Ten : "  << sv.hoTen << endl;
//    cout << "\t + Diem TB: "  << sv.diemTB << endl;
//    cout << "\t + Xep loai: "  << sv.xepLoai << endl;
}

// Câu 2: Tạo cấu trúc Node
struct Node {
    SinhVien data;
    Node *pNext;
    Node *pPrev;
};

// Bước 2: Cấp phát động Node dùng để lưu data
Node* initNode(SinhVien value) {
    Node* p = new Node;
    if (p==NULL) {
        return NULL;
    }

    p->data = value;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}

// Câu 2: Tạo cấu trúc liên kết đôi
struct List {
    Node* pHead;
    Node* pTail;
};

// Bước 4: Khởi tạo List
void initList(List& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

// Câu 4: Viết hàm thêm sinh viên vào đầu danh sách
void pushFront(List& l, Node* p) {
    if (l.pHead == NULL) {
        l.pHead = p;
        l.pTail = p;
    } else {
        p->pNext = l.pHead;
        l.pHead->pPrev = p;
        l.pHead = p;
    }
}

// Câu 5: Viết hàm thêm sinh viên vào cuối danh sách
void pushBack(List& l, Node* p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->pNext = p;
        p->pPrev = l.pTail;
        l.pTail = p;
    }
}

// Câu 6: Viết hàm khởi tạo dữ liệu danh sách sinh viên
int initDataListSV(List& dsSV) {
    SinhVien sv1 = {123, "Nguyen Van A", 9.1, ""};
    SinhVien sv2 = {124, "Nguyen Van B", 8.8, ""};
    SinhVien sv3 = {125, "Nguyen Van C", 9.1, ""};
    SinhVien sv4 = {126, "Nguyen Van D", 2.1, ""};
    SinhVien sv5 = {127, "Nguyen Van F", 9.7, ""};
    SinhVien sv6 = {128, "Nguyen Van G", 4.1, ""};
    SinhVien sv7 = {129, "Nguyen Van H", 8.3, ""};
    SinhVien sv8 = {130, "Nguyen Van K", 7.9, ""};

    pushFront(dsSV, initNode(sv1));
    pushFront(dsSV, initNode(sv2));
    pushFront(dsSV, initNode(sv3));
    pushFront(dsSV, initNode(sv4));

    pushBack(dsSV, initNode(sv5));
    pushBack(dsSV, initNode(sv6));
    pushBack(dsSV, initNode(sv7));
    pushBack(dsSV, initNode(sv8));
    return 8;
}

// Cau 7: In ds sv
void printList(List l) {
    cout << "Di tu pHead den pTail: " << endl;
    for (Node* p = l.pHead; p != NULL; p = p->pNext) {
        inSV(p->data);
    }
    cout << endl;

    cout << "Di tu pTail ve pHead: " << endl;
    for (Node* p = l.pTail; p != NULL; p = p->pPrev) {
        inSV(p->data);
    }
}

/* Cau 8. Viet ham cap nhat xep loai hoc luc
Input:
+ List dsSV => ds ban dau
Output:
+ List &dsSV => ds da cap nhat => ref
 */
void capNhatXL(List& l) {
    for (Node *p = l.pHead; p != NULL; p = p->pNext) {
        if(p->data.diemTB >= 8) {
            p->data.xepLoai = "Xuat xac";
        } else if(p->data.diemTB > 6 && p->data.diemTB < 8) {
            p->data.xepLoai = "Kha";
        } else if(p->data.diemTB > 5 && p->data.diemTB < 6) {
          p->data.xepLoai = "Trung Binh";
        } else {
          p->data.xepLoai = "Kem";
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
+ return List => ds SinhVien có điểm TB cao nhất, có thê có nhiều sv bằng điểm nhau
 */

List timListSVCoDTBMax(List l) {
    float maxDTB = timDTBCaoNhat(l);
    List result;
    initList(result);
    for (Node *p = l.pHead; p != NULL; p = p->pNext) {
        if(p->data.diemTB == maxDTB) {
            SinhVien sv = p->data;
            pushFront(result, initNode(sv));
        }
    }
    return result;
}

/* Cau 12: Ham tìm điểm TB thấp nhất
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

/* Hàm trả về List SV có DTB thấp nhất
Input: List dsSV
Output: return List => ds SV có DTB thấp nhất, có thê có nhiều sv bằng điểm nhau
 */
List timListSVDTBThapNhat(List l) {
    float minDTB = timDTBThapNhat(l);
    List result;
    initList(result);
    for (Node *p = l.pHead; p != NULL; p = p->pNext) {
        if(p->data.diemTB == minDTB) {
            SinhVien sv = p->data;
            pushFront(result, initNode(sv));
        }
    }
    return result;
}

int main() {
    List dsSV;
    initList(dsSV);
    cout << "Test: Cau 6. Khoi tao ds sv: " << endl;
    cout << "Ket qua: " << initDataListSV(dsSV) << " sinh vien." << endl;
    cout << "Test: Cau 7. In danh sach sv" << endl;
    printList(dsSV);
    cout << endl;
    cout << "Test: Cau 8 . Cap nhat xep loai: " << endl;
    capNhatXL(dsSV);
    printList(dsSV);

    cout << "Test: Cau 9 . điểm trung bình cao nhất: " << timDTBCaoNhat(dsSV) << endl;
    cout << endl;
    cout << "Test: Cau 10 . Tìm Sinh viên có mã sv 125: " << endl;
    SinhVien svTim = timSVTheoMaSV(dsSV, 125);
    inSV(svTim);
    cout << endl;
    cout << "Test: Cau 11 . Tìm list sv có điểm TB cao nhất: " << endl;
    List dsDVMaxDTB = timListSVCoDTBMax(dsSV);
    printList(dsDVMaxDTB);
    cout << endl;
    cout << "Test: Cau 12 . Tìm list sv có điểm TB thấp nhất: " << endl;
    List dsSVMinDTB = timListSVDTBThapNhat(dsSV);
    printList(dsSVMinDTB);
  return 0;
}
