//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

// Bước 1: Định nghĩa cấu trúc Node
struct Node {
  int data;
  Node* pNext;
};

// Bước 2: Cấp phát động, khởi tạo Node
Node* initNode(int value)
{
  //return new Node({value, NULL});
  Node *p = new Node;
  //p->data = value;
  (*p).data = value;
  p->pNext = NULL;
  return p;
}

// Bước 3: Tạo cấu trúc Bucket
struct Bucket{
  Node* pHead;
  Node* pTail;
};

// Bước 4: Khởi tạo Bucket
void initBucket(Bucket *bk) {
  bk->pHead = NULL;
  bk->pTail = NULL;
}

// Bước 5: Định nghĩa cấu trúc bẳng băm
const int SIZE = 5;
struct HashTable {
  Bucket buckets[SIZE];
};

// Bước 6: Khởi tạo bẳng băm
void initHashTable(HashTable& h) {
  for (int i = 0; i < SIZE; i++) {
    initBucket(&h.buckets[i]);
  }
}

int hashFunc(int value) {
  return value % SIZE;
}

int hashFunc(Node* node) {
  return (node->data)%SIZE;
}

void addTail(Bucket& bk, Node* p) {
  if(bk.pHead == NULL) {
    bk.pHead = p;
    bk.pTail = p;
  } else {
    bk.pTail->pNext = p;
    bk.pTail = p;
  }
}

void add(HashTable& h, int value) {
  // Bước 1: chọn vị trí bucket
  int viTri = hashFunc(value);
  // Bước 2: add vào bucket
  addTail(h.buckets[viTri], initNode(value));
}

void add(HashTable& h, Node* p) {
  // Bước 1: chọn vị trí bucket
  int viTri = hashFunc(p);
  // Bước 2: add vào bucket
  addTail(h.buckets[viTri], p);
}

void printHashTable(HashTable h) {
  cout << "Hash Table. Size" << SIZE << endl;
  for (int i = 0; i < SIZE; i++) {
    cout << "bucket[" << i << "] = ";
    for(Node* p = h.buckets[i].pHead; p != NULL; p = p->pNext) {
      cout << p->data << "\t";
    }
    cout << endl;
  }
}

int main() {
  HashTable h;
  initHashTable(h);

  add(h, 50);
  add(h, initNode(73));
  add(h, 35);
  add(h, 36);
  add(h, 64);
  add(h, 28);
  add(h, 90);
  add(h, 21);
  add(h, 53);
  add(h, 23);

  printHashTable(h);
  return 0;
}