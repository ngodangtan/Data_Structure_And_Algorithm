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

/* 3. Tim Gia Tri
Input:
  + Tree t;
  + int value
Output:
  + return bool
 */
bool timGiaTri(Tree t, float value) {
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

/* 4. Đếm số node trên cây
Input:
  + Tree t
Output:
  + return int
*/
int demNode(Tree t) {
  stack<Node*> s;
  Node* p = t.pRoot;
  int count = 0;
  
  while (p != NULL || !s.empty()) {
    while (p != NULL) {
      s.push(p);
      p = p->pLeft;
    }
    
    p = s.top();
    s.pop();
    count++;
    p = p->pRight;
  }
  
  return count;
}

/* 5. Đếm số node lá trên Tree
Input:
  + Tree t
Output:
  + return int
*/
int demNodeLa(Tree t) {
  stack<Node*> s;
  Node* p = t.pRoot;
  int count = 0;
  
  while (p != NULL || !s.empty()) {
    while (p != NULL) {
      s.push(p);
      p = p->pLeft;
    }
    
    p = s.top();
    s.pop();
    
    if (p->pLeft == NULL && p->pRight == NULL) {
      count++;
    }
    
    p = p->pRight;
  }
  
  return count;
}

// 6. In ra nhánh của một node
void inNhanhNode(Tree t, float value) {
  stack<Node*> s;
  stack<Node*> path;
  Node* p = t.pRoot;
  bool found = false;
  
  while (p != NULL || !s.empty()) {
    while (p != NULL) {
      s.push(p);
      path.push(p);
      
      if (p->data == value) {
        found = true;
        break;
      }
      
      p = p->pLeft;
    }
    
    if (found) break;
    
    p = s.top();
    s.pop();
    
    if (!path.empty() && path.top() == p) {
      path.pop();
    }
    
    p = p->pRight;
  }
  
  if (found) {
    cout << "Duong di tu goc den node " << value << ": ";
    stack<Node*> temp;
    
    while (!path.empty()) {
      temp.push(path.top());
      path.pop();
    }
    
    while (!temp.empty()) {
      cout << temp.top()->data;
      temp.pop();
      if (!temp.empty()) {
        cout << " -> ";
      }
    }
    cout << endl;
  } else {
    cout << "Khong tim thay node co gia tri " << value << endl;
  }
}

/* Hàm lấy một giá trị ngẫu nhiên có trong Tree
+ Input: Tree t
+Output: return float
 */
float layGiaTriNgauNhien(Tree t) {
  int soNode = demNode(t);
  if (soNode == 0) {
    return 0;
  }

  int viTri = rand() % soNode;
  int dem = 0;
  
  stack<Node*> s;
  Node* p = t.pRoot;
  
  while (p != NULL || !s.empty()) {
    while (p != NULL) {
      s.push(p);
      p = p->pLeft;
    }
    
    p = s.top();
    s.pop();
    
    if (dem == viTri) {
      return p->data;
    }
    
    dem++;
    p = p->pRight;
  }
  
  return 0;
}

int main() {
  srand(time(0));
  Tree t;
  initTree(t);
  cout << "Test: 1. Tao du lieu cho cay: " << endl;
  initDataTree(t);

  cout << "Test 2: In cay theo LNR: " << endl;
  LNR(t);
  cout << endl;

  cout << "Test 3: In cay theo NLR: " << endl;
  NLR(t);
  cout << endl;

  cout << "Test 4: In cay theo LRN: " << endl;
  LRN(t);
  cout << endl;

  cout << "Test 5: Tìm giá trị có trong Tree" << endl;
  cout << "Test tim gia tri 10 = " << timGiaTri(t, 10) << endl;
  cout << "Test tim gia tri 36 = " << timGiaTri(t, 36) << endl;

  cout << endl;
  cout << "Test 6: Đếm số node trên Tree" << endl;
  cout << "Test số lượng node = " << demNode(t) << endl;

  cout << "Test 7: Đếm số node lá trên Tree" << endl;
  cout << "Test số lượng node lá = " << demNodeLa(t) << endl;

  cout << "Test 8: In nhánh của node: " << layGiaTriNgauNhien(t) << endl;
  inNhanhNode(t, layGiaTriNgauNhien(t));

  return 0;
}