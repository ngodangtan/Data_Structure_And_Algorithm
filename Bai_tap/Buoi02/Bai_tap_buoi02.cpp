//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

struct Node {
  float value;
  Node* pNext;
};

struct List {
  Node* pHead;
  Node* pTail;
};

/* Hàm khởi tạo Node
Input: truyền vào float value
Output: return Node
 */
Node* initNode(float value) {
  Node* newNode = new Node();
  newNode->value = value;
  newNode->pNext = NULL;
  return newNode;
}

/* Hàm init List
 */
void initList(List& l) {
  l.pHead = NULL;
  l.pTail = NULL;
}

/* Câu 3: Viết hàm chèn Node vào đầu danh sách
Input: List, Node cần chèn
 */
void addHead(List& l, Node* p) {
  if (l.pHead == NULL) {
    l.pHead = p;
    l.pTail = p;
  } else {
    p->pNext = l.pHead;
    l.pHead = p;
  }
}

/* Câu 4: Viết hàm chèn Node vào cuối danh sách
Input: List, Node cần chèn
 */
void addTail(List& l, Node* p) {
  if (l.pHead == NULL) {
    l.pHead = p;
    l.pTail = p;
  } else {
    l.pTail->pNext = p;
    l.pTail = p;
  }
}

/* Câu 6: Hàm in giá trị danh sách đã thêm
Input: List
 */
void printListWhile(List l) {
  Node* p = l.pHead;
  while (p != NULL) {
    cout << p->value << " ";
    p = p->pNext;
  }
  cout << endl << endl;
}

/* Yêu cầu: Viết hàm tìm kiếm một giá trị có trong List hay không ?
Input:
+ l: List
+ value: int
Output:
+  return bool
+
 */
bool timGiaTri(List l, int value) {
  for (Node* p = l.pHead; p != NULL; p = p->pNext) {
    if (p->value == value) {
      return true;
    }
  }
  return false;
}

/* Yêu cầu: Viết hàm đếm giá trị nguyên chẵn có trong List ?
Input:
+ l: List
Output:
+  return int
 */
int demGiaTriNguyenChan(List l) {
  int result = 0;
  for (Node* p = l.pHead; p != NULL; p = p->pNext) {
    int value = p->value; // ép về số nguyên
    if (value % 2 == 0) {
      result += 1;
    }
  }

  return result;
}

/* Hàm revertList đảo ngược
Ý tưởng: Sử dụng kĩ thuật 3 con trỏ
	prev (trỏ đến phần tử trước đó)
  current (trỏ đến phần tử hiện tại)
  next (lưu phần tử kế tiếp để không bị mất liên kết)

 */
void revertList(List& l) {
  Node* prev = NULL;
  Node* current = l.pHead;
  Node* next = NULL;

  while (current != NULL) {
    next = current->pNext; // Lưu node tiếp theo
    current->pNext = prev; // Đảo ngược liên kết: node hiện tại trỏ về node trước đó
    prev = current;        // Di chuyển prev lên vị trí hiện tại
    current = next;        // Di chuyển current lên vị trí tiếp theo
  }

  // Hoán đổi lại head and tail của List
  l.pTail = l.pHead;
  l.pHead = prev;
}

/* Hàm tìm value node kế cuối
Ý tưởng: revert list, node kết cuối là pHead->pNext
 */
float timValueNodeKeCuoi(List l) {
  revertList(l);
  return l.pHead->pNext->value;
}

int main() {
  // Cau so 1 Xay dung cau truc Node
  Node* node1 = initNode(1.0);
  Node* node2 = initNode(2.3);
  Node* node3 = initNode(3.4);
  Node* node4 = initNode(4.5);

  List list;
  initList(list);

  cout << "Test Câu 3 Chèn node vào đầu danh sách" << endl;
  addHead(list, node3);
  addHead(list, node2);
  addHead(list, node1);
  cout << "Test Câu 4 Chèn Node vào cuối danh sách" << endl;
  addTail(list, node4);

  cout << "Test Câu 6 In Giá trị danh sách đã nhập" << endl;
  printListWhile(list);

  cout << "Test bài tập thêm in giá trị chẵn trong danh sách: " << endl;
  cout << demGiaTriNguyenChan(list) << endl;

  cout << "Test tim node ke cuoi: " << timValueNodeKeCuoi(list) << endl;

  return 0;
}