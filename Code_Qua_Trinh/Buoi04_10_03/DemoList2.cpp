//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

// Bước 1: Tạo cấu trúc Node
struct Node {
  int data;
  Node *pNext;
  Node *pPrev;
};

// Bước 2: Cấp phát động Node dùng để lưu data
Node* initNode(int value) {
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

void printList(List l) {
  cout << "Di tu pHead den pTail: " << endl;
  for (Node* p = l.pHead; p != NULL; p = p->pNext) {
    cout << p->data << " ";
  }
  cout << endl;

  cout << "Di tu pTail ve pHead: " << endl;
  for (Node* p = l.pTail; p != NULL; p = p->pPrev) {
    cout << p->data << " ";
  }
}

int main() {
  // 10 79 39
  Node* p1 = initNode(10);
  Node* p2 = initNode(79);
  Node* p3 = initNode(39);
  Node* p4 = initNode(18);
  Node* p5 = initNode(12);

  List l;
  initList(l);

  pushFront(l, p1);
  pushBack(l, p2);
  pushBack(l, p3);
  pushFront(l, p4);
  pushBack(l, p5);
  printList(l);
  return 0;
}
