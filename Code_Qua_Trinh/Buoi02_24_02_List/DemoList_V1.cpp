//
// Created by Felix Ngo on 24/2/25.
//

#include <iostream>
using namespace std;

// Buoc 01: Tạo cấu trúc Node
struct Node {
  int data;
  Node *pNext; // lưu trữ địa chỉ của Node phía sau
};

// Bước 2: Khởi tạo Node để lưu giá trị cần lưu.
Node* initNode(int value) {
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

void addHead(List& l, Node* p) {
  if (l.pHead == NULL) {
    l.pHead = p;
    l.pTail = p;
  } else {
    p->pNext = l.pHead;
    l.pHead = p;
  }
}

void addTail(List& l, Node* p) {
  if (l.pHead == NULL) {
    l.pHead = p;
    l.pTail = p;
  } else {
    l.pTail->pNext = p;
    l.pTail = p;
  }
}

void printList(List l) {
  for (Node* p = l.pHead; p != NULL; p = p->pNext) {
    cout << p->data << " ";
  }
    cout << endl << endl;
}

int main() {
  Node* p1 = initNode(10);
  Node* p2 = initNode(79);
  Node* p3 = initNode(39);

  List l;
  initList(l); //Danh sách rỗng

  addHead(l,p1);
  addHead(l,p2);

  addTail(l,p3);
  printList(l);

//  Node* p = new Node;
//  p->data = 10;
//  p->pNext = NULL; // chưa lưu trữ địa chỉ Node tiếp theo, set = NULL
//
//  Node* p1 = new Node;
//  p1->data = 79;
//  p1->pNext = NULL;

  return 0;
}