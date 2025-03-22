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

int main() {
  return 0;
}