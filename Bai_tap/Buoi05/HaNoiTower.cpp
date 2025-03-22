//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

// Bước 1: Tạo cấu trúc Node
struct Node {
  string data;
  Node *pNext;
};

// Bước 2: Khởi tạo Node hay cấp phát động Node để lưu gía trị
Node* initNode(string value) {
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

// Hàm thêm một Node vào stack
void push(Stack& s, Node* p) {
  p->pNext = s.pTop;
  s.pTop = p;
}

/* Hàm loại bỏ một Node khỏi stack
Input: Stack& s
Output: Node
 */
Node* pop(Stack& s) {
  if (s.pTop == NULL) {
    return NULL;
  }
  Node* temp = s.pTop;
  s.pTop = s.pTop->pNext;
  temp->pNext = NULL;
  return temp;
}

// Hàm print toàn bộ value có trong Stack
void printStack(Stack s) {
  cout << "Stack = Top<<  ";
  for (Node* p = s.pTop; p != NULL; p = p->pNext) {
    cout << p->data << "   ";
  }
  cout << ">>" << endl;
}

/* Hàm xác định size của stack
Input: Stack s
Output: int
 */
int sizeStack(Stack s) {
  int size = 0;
  for (Node* p = s.pTop; p != NULL; p = p->pNext) {
    size++;
  }
  return size;
}

// Hàm di chuyển tháp hà nội
// Sử dụng đệ quy
/*
from_rod: nơi chứa các Node ban đầu,
to_rod: nơi cần chuyển đến,
aux_rod: giúp hỗ trợ quá trình di chuyển mà không vi phạm quy tắc (không được đặt đĩa lớn lên đĩa nhỏ).
 */
void towerOfHanoi(int n, Stack& from_rod, Stack& to_rod, Stack& aux_rod) {
  if (n == 0) {
    return;
  }
  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
  Node* temp = pop(from_rod);  // Lấy node và loại bỏ khỏi stack nguồn, không xóa node
  push(to_rod, temp);          // Chuyển node sang stack đích
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
  Node* p1 = initNode("Đĩa số 1");
  Node* p2 = initNode("Đĩa số 2");
  Node* p3 = initNode("Đĩa số 3");
  Node* p4 = initNode("Đĩa số 4");

  Stack stackA,stackB,stackC;
  initStack(stackA);
  initStack(stackB);
  initStack(stackC);

  push(stackA,p1);
  push(stackA,p2);
  push(stackA,p3);
  push(stackA,p4);
  printStack(stackA);
  cout << "Bắt đầu quá trình di chuyển toàn bộ Node tháp từ Tháp A qua tháp C" << endl;
  towerOfHanoi(sizeStack(stackA), stackA, stackC, stackB);
  cout << "Stack C sau khi move thap: " << endl;
  printStack(stackC);
  cout << "Stack A sau khi move thap: sẽ empty" << endl;
  printStack(stackA);

  return 0;
}