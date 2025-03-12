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
    cout << "[" << sv.maSV << "," << sv.hoTen << "," << sv.diemTB << "," << sv.xepLoai << "]" << endl;
//    cout << "Thong tin sv: " << endl;
//    cout << "\t + Ma sv : "  << sv.maSV << endl;
//    cout << "\t + Ho Ten : "  << sv.hoTen << endl;
//    cout << "\t + Diem TB: "  << sv.diemTB << endl;
//    cout << "\t + Xep loai: "  << sv.xepLoai << endl;
}

// Bước 1: Tạo cấu trúc Node
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

// Bước 3: Tạo cấu trúc liên kết đôi
struct List {
    Node* pHead;
    Node* pTail;
};

// Bước 4: Khởi tạo List
void initList(List& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

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

void pushBack(List& l, Node* p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->pNext = p;
        p->pPrev = l.pTail;
        l.pTail = p;
    }
}

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

int main() {
    List dsSV;
    initList(dsSV);
    cout << "Test: Cau 6. Khoi tao ds sv: " << endl;
    cout << "Ket qua: " << initDataListSV(dsSV) << " sinh vien." << endl;
    cout << "Test: Cau 7. In danh sach sv" << endl;
    printList(dsSV);
  return 0;
}
