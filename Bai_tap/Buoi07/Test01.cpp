//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
#include <ctime>
using namespace std;

// Tạo cấu trúc Node và cây
// Bước 1: Định nghĩa cấu trúc Node
struct Node {
  float data;
  Node* pLeft;
  Node* pRight;
};

// Bước 2: Cấp phát động Node để lưu giá trị cần lưu
Node* initNode(float value) {
  Node* p = new Node;
  p->data = value;
  p->pLeft = NULL;
  p->pRight = NULL;
  return p;
}

// Bước 3: Định nghĩa cấu trúc cây
struct Tree {
  Node* pRoot;
};

// Bước 4: Khởi tạo cây
void initTree(Tree& t) {
  t.pRoot = NULL;
}

void addNode(Tree& tree, Node* p) {
  if (tree.pRoot == NULL) {
    tree.pRoot = p;
    return;
  }

  Node* pGoto = tree.pRoot;
  Node* pLoca = NULL;

  while (pGoto != NULL) {
    pLoca = pGoto;
    if (p->data < pLoca->data) {
      pGoto = pGoto->pLeft;
    } else if (p->data > pLoca->data) {
      pGoto = pGoto->pRight;
    }
  }

  if(p->data < pLoca->data) {
    pLoca->pLeft = p;
  } else if (p->data > pLoca->data) {
    pLoca->pRight = p;
  }
}

// Viết hàm nhập giá trị float chuyển sang Node đưa vào Tree
void addValue(Tree& tree, float value) {
  Node* p = initNode(value);
  addNode(tree, p);
}

/* Hàm khởi tạo data cho Tree
Input:
  + Tree& t;
Output:
  + return int
 */

void initDataTree(Tree& t) {
  int soLuong = rand() % (20 - 10) + 10;
  for (int i = 0; i < soLuong; i++) {
    float value = rand() % (68 + 38) - 38;
    addValue(t, value);
  }
}

int main() {
  return 0;
}