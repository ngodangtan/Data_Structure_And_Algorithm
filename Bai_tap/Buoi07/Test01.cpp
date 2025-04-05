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
    } else {
      delete p;
      return;
    }
  }

  if(p->data < pLoca->data) {
    pLoca->pLeft = p;
  } else {
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
  int soLuong = rand() % (60 - 50) + 50;
  for (int i = 0; i < soLuong; i++) {
    float value = rand() % (723 - 512) + 512;
    addValue(t, value);
  }
}

// Hàm in LNR
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
    cout << "Data: " << p->data << " | Left: " << p->pLeft << " | Right: " << p->pRight << " | Current: " << p << endl;
    p = p->pRight;
  }
}

// Hàm in NLR
void NLR(Tree t) {
  stack<Node*> s;
  Node* p = t.pRoot;

  while (p != NULL || s.empty() == false) {
    while (p != NULL) {
      cout << "Data: " << p->data << " | Left: " << p->pLeft << " | Right: " << p->pRight << " | Current: " << p << endl;
      s.push(p);
      p = p->pLeft;
    }

    p = s.top();
    s.pop();
    p = p->pRight;
  }
}

// Hàm in LRN
void LRN(Tree t) {
  stack<Node*> s;
  Node* p = t.pRoot;
  Node* lastVisited = NULL;

  while (p != NULL || s.empty() == false) {
    while (p != NULL) {
      s.push(p);
      p = p->pLeft;
    }

    p = s.top();
    if (p->pRight == NULL || p->pRight == lastVisited) {
      cout << "Data: " << p->data << " | Left: " << p->pLeft << " | Right: " << p->pRight << " | Current: " << p << endl;
      s.pop();
      lastVisited = p;
      p = NULL;
    } else {
      p = p->pRight;
    }
  }
}

// Hàm tạo Tree từ mảng n phần tử
void createTreeFromArray(Tree& tree, float arr[], int n) {
  for (int i = 0; i < n; i++) {
    addValue(tree, arr[i]);
  }
}

/* Tìm giá trị có trong Tree
Input:
  + Tree t;
  + float value
Output:
  + return Node* (địa chỉ của Node nếu tìm thấy, NULL nếu không tìm thấy)
 */
Node* timNode(Tree t, float value) {
  Node* p = t.pRoot;
  while (p != NULL) {
    if (p->data == value) {
      return p;
    }

    if (value < p->data) {
      p = p->pLeft;
    } else if (value > p->data) {
      p = p->pRight;
    }
  }
  return NULL;
}

int main() {
  srand(time(0));
  Tree t;
  initTree(t);
  cout << "Test: Tạo dữ liệu cho Tree " << endl;
  
  // Ví dụ sử dụng hàm tạo cây từ mảng
  float arr[] = {10.5, 20.3, 15.7, 8.2, 25.1, 12.4};
  int n = sizeof(arr) / sizeof(arr[0]);
  createTreeFromArray(t, arr, n);
  
  cout << endl;
  cout << "Test 4: In cay theo LNR: " << endl;
  LNR(t);
  cout << endl;

  cout << endl;
  cout << "Test 4: In cay theo NLR: " << endl;
  NLR(t);
  cout << endl;

  cout << endl;
  cout << "Test 4: In cay theo LRN: " << endl;
  LRN(t);
  cout << endl;

  cout << "Test 5: Tìm giá trị " << endl;
  float searchValue = 15.7;
  Node* foundNode = timNode(t, searchValue);
  if (foundNode != NULL) {
    cout << "Tìm thấy giá trị: " << searchValue << " tại địa chỉ: " << foundNode << endl;
  } else {
    cout << "Không tìm thấy giá trị " << searchValue << endl;
  }
  
  return 0;
}