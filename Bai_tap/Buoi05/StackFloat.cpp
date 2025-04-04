//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

// Khai báo cấu trúc Node
// Bước 1: Tạo cấu trúc Node
struct Node {
  float data;
  Node *pNext;
};

// Bước 2: Khởi tạo Node hay cấp phát động Node để lưu gía trị
Node* initNode(float value) {
  Node* p = new Node;
  p->data = value;
  p->pNext = NULL;
  return p;
}

// Bước 3: Định nghĩa Stack
struct Stack {
  Node* pTop;
  int size;
  int maxSize;
};

// Bước 4: Khởi tạo Stack
void initStack(Stack& s) {
  s.pTop = NULL;
}

/* Hàm kiểm tra stack có empty hay không
Input: Stack s
Output: bool value
 */
bool isEmptyStack(Stack s) {
  return s.pTop == NULL ? true : false;
}

/* Hàm kiểm tra stack có đầy hay không
Input: Stack s
Output: bool value
 */
bool isFullStack(Stack s) {
  return s.size > s.maxSize ? true : false;
}

// Hàm thêm một Node vào stack
void push(Stack& s, Node* p) {
  if (s.pTop == NULL) {
    s.pTop = p;
  } else {
    p->pNext = s.pTop;
    s.pTop = p;
  }
  s.size++;
}

// Hàm in toàn bộ giá trị trong stack
void printStack(Stack s) {
  cout << "Stack = Top<<  ";
  for (Node* p = s.pTop; p != NULL; p = p->pNext) {
    cout << p->data << "   ";
  }
  cout << ">>" << endl;
}

// Hàm loạ bỏ Node top khỏi stack
void pop(Stack& s) {
  if (s.pTop == NULL) {
    return;
  }

  Node* p = s.pTop;
  s.pTop = s.pTop->pNext;
  s.size--;
  delete p;
}

/* Hàm trả về giá trị top của stack
Input: Stack s
Output: return float
 */
float getTopValue(Stack s) {
  if (s.pTop != NULL) {
    return s.pTop->data;
  }
}

int main() {
  Node* p1 = initNode(65.4);
  Node* p2 = initNode(33.4);
  Node* p3 = initNode(11.3);
  Node* p4 = initNode(20.3);

  Stack s;
  initStack(s);

  push(s,p1);
  push(s,p2);
  push(s,p3);
  push(s,p4);
  printStack(s);

  cout << "\n\nTest lấy value TOP: " << getTopValue(s) << endl;

  return 0;
}