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

//4. Viết hàm chén Node vào Tree
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
    cout << p->data << " ";
    p = p->pRight;
  }
}

// Hàm in NLR
void NLR(Tree t) {
  stack<Node*> s;
  Node* p = t.pRoot;
  
  while (p != NULL || s.empty() == false) {
    while (p != NULL) {
      cout << p->data << " ";
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
      cout << p->data << " ";
      s.pop();
      lastVisited = p;
      p = NULL;
    } else {
      p = p->pRight;
    }
  }
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

/* Đếm số node trên cây
Input:
  + Tree t
Output:
  + return int
*/
int demNode(Tree t) {
  stack<Node*> s;
  Node* p = t.pRoot;
  int count = 0;
  
  while (p != NULL || s.empty() == false) {
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

/* Đếm số node lá trên Tree
Input:
  + Tree t
Output:
  + return int
*/
int demNodeLa(Tree t) {
  stack<Node*> s;
  Node* p = t.pRoot;
  int count = 0;
  
  while (p != NULL || s.empty() == false) {
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

// In ra nhánh của một node
void inNhanhNode(Tree t, float value) {
  stack<Node*> s;
  stack<Node*> path;
  Node* p = t.pRoot;
  bool found = false;
  
  while (p != NULL || s.empty() == false) {
    while (p != NULL) {
      s.push(p);
      path.push(p);
      
      if (p->data == value) {
        found = true;
        break;
      }
      
      p = p->pLeft;
    }
    
    if (found) {
      break;
    }

    p = s.top();
    s.pop();
    
    if (!path.empty() && path.top() == p) {
      path.pop();
    }
    
    p = p->pRight;
  }
  
  if (found) {
    cout << "Nhánh của Node " << value << ": ";
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
+ Input:
    Tree t
+Output:
    return float
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
  
  while (p != NULL || s.empty() == false) {
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

/* Hàm đếm số node có giá trị nhỏ hơn X
Input:
  + Tree t
  + float x
Output:
  + return int
*/
int demNodeNhoHonX(Tree t, float x) {
  stack<Node*> s;
  Node* p = t.pRoot;
  int count = 0;
  
  while (p != NULL || s.empty() == false) {
    while (p != NULL) {
      s.push(p);
      p = p->pLeft;
    }
    
    p = s.top();
    s.pop();
    
    if (p->data < x) {
      count++;
    }
    
    p = p->pRight;
  }
  
  return count;
}

/* Hàm tính tổng giá trị các node trong Tree
Input:
  + Tree t
Output:
  + return float
*/
float tinhTongNode(Tree t) {
  stack<Node*> s;
  Node* p = t.pRoot;
  float sum = 0;
  
  while (p != NULL || s.empty() == false) {
    while (p != NULL) {
      s.push(p);
      p = p->pLeft;
    }
    p = s.top();
    s.pop();
    
    sum += p->data;
    
    p = p->pRight;
  }
  
  return sum;
}

/* Hàm tính tổng giá trị các node chẵn trong Tree
Input:
  + Tree t
Output:
  + return float
*/
float tinhTongNodeChan(Tree t) {
  stack<Node*> s;
  Node* p = t.pRoot;
  float sum = 0;
  
  while (p != NULL || s.empty() == false) {
    while (p != NULL) {
      s.push(p);
      p = p->pLeft;
    }
    
    p = s.top();
    s.pop();
    
    if ((int)p->data % 2 == 0) {
      sum += p->data;
    }
    
    p = p->pRight;
  }
  
  return sum;
}

/* Hàm tìm giá trị lớn nhất và nhỏ nhất trong Tree
Input:
  + Tree t
  + float& min
  + float& max
*/
void timMinMax(Tree t, float& min, float& max) {
  if (t.pRoot == NULL) {
    min = max = 0;
    return;
  }

  stack<Node*> s;
  Node* p = t.pRoot;
  
  min = max = p->data;
  
  while (p != NULL || s.empty() == false) {
    while (p != NULL) {
      s.push(p);
      p = p->pLeft;
    }
    
    p = s.top();
    s.pop();
    
    if (p->data < min) {
      min = p->data;
    }
    if (p->data > max) {
      max = p->data;
    }
    
    p = p->pRight;
  }
}

int main() {
  srand(time(0));
  Tree t;
  initTree(t);
  cout << "Test: 1->6 Tao du lieu cho cay: " << endl;
  initDataTree(t);

  cout << endl;
  cout << "Test 7: In cay theo LNR: " << endl;
  LNR(t);
  cout << endl;

  cout << endl;
  cout << "Test 7: In cay theo NLR: " << endl;
  NLR(t);
  cout << endl;

  cout << endl;
  cout << "Test 7: In cay theo LRN: " << endl;
  LRN(t);
  cout << endl;

  cout << endl;
  cout << "Test 8: Tìm giá trị có trong Tree" << endl;
  cout << "Test tim gia tri 10 = " << timGiaTri(t, 10) << endl;
  cout << "Test tim gia tri 36 = " << timGiaTri(t, 36) << endl;
  cout << "Test tim gia tri: " << layGiaTriNgauNhien(t) << " (1) "<< timGiaTri(t, layGiaTriNgauNhien(t)) << endl;

  cout << endl;
  cout << "Test 9: Đếm số node trên Tree" << endl;
  cout << "Test số lượng node = " << demNode(t) << endl;

  cout << endl;
  cout << "Test 10: Đếm số node lá trên Tree" << endl;
  cout << "Test số lượng node lá = " << demNodeLa(t) << endl;

  cout << endl;
  float giaTriRandom11 =  layGiaTriNgauNhien(t);
  cout << "Test 11: In nhánh của node: " << giaTriRandom11 << endl;
  inNhanhNode(t, giaTriRandom11);

  cout << endl;
  cout << "Test 12: Đếm số node nhỏ hơn 0" << endl;
  cout << "So luong node nho hon 0: " << demNodeNhoHonX(t, 0) << endl;

  cout << endl;
  cout << "Test 13: Tính tổng giá trị các node" << endl;
  cout << "Tong gia tri cac node: " << tinhTongNode(t) << endl;

  cout << endl;
  cout << "Test 14: Tính tổng giá trị các node chẵn" << endl;
  cout << "Tong gia tri cac node chan: " << tinhTongNodeChan(t) << endl;

  cout << endl;
  cout << "Test 15: Tìm giá trị lớn nhất và nhỏ nhất" << endl;
  float min, max;
  timMinMax(t, min, max);
  cout << "Gia tri nho nhat: " << min << endl;
  cout << "Gia tri lon nhat: " << max << endl;
  
  return 0;
}