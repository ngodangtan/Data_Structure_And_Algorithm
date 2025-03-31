//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

// Bước 1: Định nghĩa cấu trúc Node
struct Node {
  int data;
  Node* pLeft;
  Node* pRight;
};

// Bước 2: Cấp phát động Node để lưu giá trị cần lưu
Node* initNode(int value) {
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

  if(p->data < p->data) {
    pLoca->pLeft = p;
  } else if (p->data > p->data) {
    pLoca->pRight = p;
  }
}

void addValue(Tree& tree, int value) {
  Node* p = initNode(value);
  addNode(tree, p);
}

int main() {

  Node* p1 = initNode(50);
  Node* p2 = initNode(26);
  Node* p3 = initNode(73);
  Node* p4 = initNode(66);
  Node* p5 = initNode(88);
  Node* p6 = initNode(61);

  Tree t;
  initTree(t);

  addNode(t , p1);
  addNode(t , p2);
  addNode(t , p3);
  addNode(t , p4);
  addNode(t , p5);
  addNode(t , p6);

  addValue(t, 30);
  return 0;
}