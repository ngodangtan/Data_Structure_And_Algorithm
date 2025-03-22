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
};

// Bước 2: Khởi tạo Node hay cấp phát động Node để lưu gía trị
Node* initNode(int value) {
  Node* p = new Node;
  p->data = value;
  p->pNext = NULL;
  return p;
}

// Bước 3: Định nghĩa Stack
struct Stack {
  Node* pTop;
};

// Bước 4: Khởi tạo Stack
void initStack(Stack& s) {
  s.pTop = NULL;
}

void push(Stack& s, Node* p) {
  if (s.pTop == NULL) {
    s.pTop = p;
  } else {
    p->pNext = s.pTop;
    s.pTop = p;
  }
}

void printStack(Stack s) {
  cout << "Stack = Top<<  ";
  for (Node* p = s.pTop; p != NULL; p = p->pNext) {
    cout << p->data << "   ";
  }
  cout << ">>" << endl;
}

int main() {
  Node* p1 = initNode(10);
  Node* p2 = initNode(79);
  Node* p3 = initNode(39);

  Stack stackA,stackB,stackC;
  initStack(stackA);

  push(stackA,p1);
  push(stackA,p2);
  push(stackA,p3);
  printStack(stackA);

  return 0;
}