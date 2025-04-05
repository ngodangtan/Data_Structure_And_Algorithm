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

  if(p->data < pLoca->data) {
    pLoca->pLeft = p;
  } else if (p->data > pLoca->data) {
    pLoca->pRight = p;
  }
}

void addValue(Tree& tree, int value) {
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
/* 3. Tim Gia Tri
Input:
  + Tree t;
  + int value
Output:
  + return bool
 */
bool timGiaTri(Tree t, int value) {
  Node* p = t.pRoot;
  while (p != NULL) {
    if (p->data == value) {
      return true;
    }

    if (value < p->data) {
      p = p->pLeft;
    } else if (value > p->data) {
      p = p->pRight;
    }
  }
  return false;
}

int initDataTree(Tree& t) {
  Node* p1 = initNode(50);
  Node* p2 = initNode(26);
  Node* p3 = initNode(73);
  Node* p4 = initNode(66);
  Node* p5 = initNode(88);
  Node* p6 = initNode(61);

  addNode(t , p1);
  addNode(t , p2);
  addNode(t , p3);
  addNode(t , p4);
  addNode(t , p5);
  addNode(t , p6);

  addValue(t, 30);
  return 7;
}

/* 4. Viet ham tinh tong cac gia tri trong cay
Input:
  + Tree t;
Output:
  + return tong
 */

int tong(Tree t) {
  int tg = 0;
  stack<Node*> s;
  Node* p = t.pRoot;
  while (p!=NULL || s.empty() == false) {
    while (p != NULL) {
      s.push(p);
      p = p->pLeft;
    }
    p = s.top();
    s.pop();

    tg = tg + p->data;

    p = p->pRight;
  }
  return tg;
}

/* 5. In Node la

 */

void LNR_La(Tree t) {
  stack<Node*> s;
  Node* p = t.pRoot;
  while (p!=NULL || s.empty() == false) {
    while (p != NULL) {
      s.push(p);
      p = p->pLeft;
    }
    p = s.top();
    s.pop();
    if (p->pLeft == NULL && p->pRight == NULL) {
      cout << p->data << " ";
    }
    p = p->pRight;
  }
}

/* 3. Tim Gia Tri
Input:
  + Tree t;
  + int value
Output:
  + return bool
 */

int main() {
  Tree t;
  initTree(t);
  cout << "Test: 1. Tao du lieu cho cay: " << endl;
  int soLuong = initDataTree(t);
  cout << "\t+ Ket qua: " << soLuong << " gia tri" << endl;

  cout << "Test 2: In cay" << endl;
  LNR(t);

  cout << "\nTest 3: Tim kiem" << endl;
  cout << "\t+ Ket qua tim 10(0) = " << timGiaTri(t, 10) << endl;
  cout << "\t+ Ket qua tim 66(1) = " << timGiaTri(t, 66) << endl;

  cout << "\nTest 4: Ket qua tinh tong " << tong(t) << endl;
  cout << "\nTest 5: Test in la :" << endl;
  LNR_La(t);
  cout << "\nTest: :" << endl;
  cout << "\nTest: :" << endl;
  return 0;
}