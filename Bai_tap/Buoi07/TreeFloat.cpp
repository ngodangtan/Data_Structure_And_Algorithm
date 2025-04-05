//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
#include <stack>
#include <ctime>
using namespace std;

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

void addValue(Tree& tree, float value) {
  Node* p = initNode(value);
  addNode(tree, p);
}

void LNR(Tree t) {
  stack<Node*> s;
  Node* p = t.pRoot;
  while (p!=NULL || s.empty() == false) {
    while (p != NULL) {
      s.push(p);
      p = p->pLeft;
    }
    p = s.top();
    s.pop();
    cout << p->data << " ";
    p = p->pRight;
  }
}

void NLR(Tree t) {
  stack<Node*> s;
  Node* p = t.pRoot;
  
  while (p != NULL || !s.empty()) {
    while (p != NULL) {
      cout << p->data << " ";  // In ra giá trị node gốc trước
      s.push(p);
      p = p->pLeft;
    }
    
    p = s.top();
    s.pop();
    p = p->pRight;
  }
}

void LRN(Tree t) {
  stack<Node*> s;
  Node* p = t.pRoot;
  Node* lastVisited = NULL;
  
  while (p != NULL || !s.empty()) {
    while (p != NULL) {
      s.push(p);
      p = p->pLeft;
    }
    
    p = s.top();
    if (p->pRight == NULL || p->pRight == lastVisited) {
      cout << p->data << " ";  // In ra giá trị node sau khi đã duyệt cả hai cây con
      s.pop();
      lastVisited = p;
      p = NULL;
    } else {
      p = p->pRight;
    }
  }
}

/* 2. Hàm khởi tạo data cho Tree
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
  srand(time(0));
  Tree t;
  initTree(t);
  cout << "Test: 1. Tao du lieu cho cay: " << endl;
  initDataTree(t);

  cout << "Test 2: In cay theo LNR (In-order): " << endl;
  LNR(t);
  cout << endl;

  cout << "Test 3: In cay theo NLR (Pre-order): " << endl;
  NLR(t);
  cout << endl;

  cout << "Test 4: In cay theo LRN (Post-order): " << endl;
  LRN(t);
  cout << endl;
  
  return 0;
}