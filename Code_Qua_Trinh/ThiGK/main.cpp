//
// Created by Ngo Dang Tan on 28/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
#include <time.h>
using namespace std;

// Ngô Đăng Tân
// MSSV: 24210173@ms.uit.edu.vn
// 24210173 \% 3 = 2 => De 1

struct Node {
  double data;
  Node* pLeft;
  Node* pRight;
};

struct StackNode {
  Node* data;
  StackNode* next;
};

struct Stack {
  StackNode* top;
};

// Hàm khởi tạo Stack
void initStack(Stack& s) {
  s.top = NULL;
}

/* Hàm kiểm tra Stack có rỗng hay không
Input: Stack s
Output: return bool
 */
bool isEmpty(Stack s) {
  return s.top == NULL;
}

// Hàm thêm gía trị top vào stack
void push(Stack& s, Node* p) {
  StackNode* temp = new StackNode;
  temp->data = p;
  temp->next = s.top;
  s.top = temp;
}

// Hàm loại bỏ giá trị top trong stack
Node* pop(Stack& s) {
  if (isEmpty(s))
    return NULL;
  StackNode* temp = s.top;
  Node* result = temp->data;
  s.top = temp->next;
  delete temp;
  return result;
}

/* Hàm lấy giá trị top trong stack
 */
Node* peek(Stack s) {
  if (isEmpty(s))
    return NULL;
  return s.top->data;
}

struct Tree {
  Node* root;
};

// Khởi tạo Tree
void initTree(Tree& t) {
  t.root = NULL;
}

/* Hàm khởi tạo Node
 Input: double value
 Output: return Node
 */
Node* initNode(double value) {
  Node* p = new Node;
  p->data = value;
  p->pLeft = p->pRight = NULL;
  return p;
}

/* Câu 1: Hàm chèn Node vào Tree
 Input: Tree& t, double value
 Output: return int
 */
int insertNode(Tree& t, double value) {
  Node* pNew = initNode(value);
  if (!t.root) {
    t.root = pNew;
    return 1;
  }

  Node* current = t.root;
  Node* parent = NULL;

  while (current != NULL) {
    parent = current;
    if (value < current->data)
      current = current->pLeft;
    else if (value > current->data)
      current = current->pRight;
    else {
      delete pNew; // Gia tri trung, bo qua
      return -1;
    }
  }

  if (value < parent->data)
    parent->pLeft = pNew;
  else
    parent->pRight = pNew;

  return 1;
}

// Câu 2: Hàm khởi tạo dữ liệu cho mảng
void initArray(double arr[], int& n) {
  n = 10;
  double temp[10] = {50.1, 70.1, 60.2, 30.4, 70.7, 90.5, 70.6, 40.5, 10.5, 90.5};
  for (int i = 0; i < n; i++) {
    arr[i] = temp[i];
  }
}

// Câu 3: In các giá trị tăng dần trong Tree
void inOrderLNR(Tree t) {
  Stack s;
  initStack(s);
  Node* current = t.root;

  while (current != NULL || !isEmpty(s)) {
    while (current != NULL) {
      push(s,current);
      current = current->pLeft;
    }

    current = peek(s);
    pop(s);

    cout << current->data << " ";
    current = current->pRight;
  }
  cout << endl;
}

/* Câu 4: Tìm kiếm giá trị X trong Tree
 Input: Tree t, double x
 Output: reutrn int (-1 tim thấy, 1 không tìm thấy)
 */
int searchNode(Tree t, double x) {
  Node* p = t.root;
  while (p != NULL) {
    if (p->data == x)
      return 1;
    if (x < p->data)
      p = p->pLeft;
    else
      p = p->pRight;
  }
  return -1;
}

/* Câu 5: Tính tổng các Node lá
 Input: Tree t
 Output: return double sum
 */
double sumLeafNodes(Tree t) {
  if (!t.root)
    return 0;

  double sum = 0;
  stack<Node*> s;
  s.push(t.root);

  while (!s.empty()) {
    Node* p = s.top();
    s.pop();

    if (!p->pLeft && !p->pRight) {
      sum += p->data;
    }
    if (p->pRight) s.push(p->pRight);
    if (p->pLeft) s.push(p->pLeft);
  }
  return sum;
}

/* Câu 6 Đếm các Node chỉ có 1 nhánh con
 Input: Node* p
 Output: return int
 */
int countOneChildNodes(Node* p) {
  if (!p)
    return 0;
  int count = 0;
  if ((p->pLeft == nullptr && p->pRight != NULL) || (p->pLeft != NULL && p->pRight == NULL))
    count++;
  count += countOneChildNodes(p->pLeft);
  count += countOneChildNodes(p->pRight);
  return count;
}

// Câu 7: Viết hàm tìm giá trị lớn nhất và nhỏ nhất trong cây
void findMinMax(Tree t, double& minValue, double& maxValue) {
  Node* pMin = t.root;
  while (pMin && pMin->pLeft != NULL)
    pMin = pMin->pLeft;
  minValue = pMin ? pMin->data : -1;

  Node* pMax = t.root;
  while (pMax && pMax->pRight != NULL)
    pMax = pMax->pRight;
  maxValue = pMax ? pMax->data : -1;
}

/* Câu 8: Hàm tính trung bình các Node
 Input: Tree t
 Output: return double
 */
double avgNodes(Tree t) {
  if (!t.root)
    return 0;

  double sum = 0;
  int count = 0;
  Stack s;
  initStack(s);
  push(s,t.root);

  while (!isEmpty(s)) {
    Node* p = peek(s);
    pop(s);
    sum += p->data;
    count++;

    if (p->pRight)
      push(s,p->pRight);
    if (p->pLeft)
      push(s,p->pLeft);
  }
  return (count != 0) ? (sum / count) : 0;
}

/* Câu 9: Hàm tạo cây mới sao chép từ root cũ
 Input: Node* root
 return Node
 */
Node* copyTree(Node* root) {
  if (!root)
    return NULL;

  Node* newRoot = initNode(root->data);
  newRoot->pLeft = copyTree(root->pLeft);
  newRoot->pRight = copyTree(root->pRight);
  return newRoot;
}

// Hàm Tao 2 cay moi tu trái và phải
void createTwoTrees(Tree original, Tree& treeLeft, Tree& treeRight) {
  initTree(treeLeft);
  initTree(treeRight);

  if (!original.root)
    return;

  treeLeft.root = copyTree(original.root->pLeft);
  treeRight.root = copyTree(original.root->pRight);
}

int main() {
  Tree t;
  initTree(t);

  double arr[10];
  int n = 0;
  initArray(arr, n);

  // Chen vao cay t1 va t2
  for (int i = 0; i < n; i++) {
    insertNode(t, arr[i]);
  }
  cout << "Test Câu 2: Đã Khởi Tạo Cây" << endl;
  cout << "=====================================" << endl;
  cout << "Test Câu 3: In cay theo thu tu tang dan: " << endl;
  inOrderLNR(t);
  cout << "=====================================" << endl;
  cout << "Test Câu 4: Tìm giá trị X trong Tree" << endl;

  cout << "Tim 60.2 trong cây: " << (searchNode(t, 60.2) == 1 ? "Tìm thấy" : "Không tìm thấy") << endl;
  cout << "Tim 11 trong cây: " << (searchNode(t, 11) == 1 ? "Tìm thấy" : "Không tìm thấy") << endl;
  cout << "=====================================" << endl;
  cout << "Test Câu 5: Tổng cac node lá cây: " << sumLeafNodes(t) << endl;
  cout << "=====================================" << endl;
  cout << "Test Câu 6: Số Node chỉ có 1 nhánh trong cây: " << countOneChildNodes(t.root) << endl;
  cout << "=====================================" << endl;
  double minVal, maxVal;
  findMinMax(t, minVal, maxVal);
  cout << "Test Câu 7:" << endl;
  cout << "Gia tri nho nhat: " << minVal << " va lon nhat: " << maxVal << endl;
  cout << "=====================================" << endl;
  cout << "Test Câu 8: Giá trị TB của các Node: " << avgNodes(t) << endl;
  cout << "=====================================" << endl;
  cout << "Test Câu 9" << endl;
  Tree leftTree, rightTree;
  createTwoTrees(t, leftTree, rightTree);

  cout << "pLeft cua t: ";
  inOrderLNR(leftTree);

  cout << "pRight cua t: ";
  inOrderLNR(rightTree);

  return 0;
}