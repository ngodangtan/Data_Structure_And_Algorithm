//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

const int SIZE = 5;

// Bước 1: Định nghĩa cấu trúc Node
struct Node {
  float data;
  Node* pNext;
};

// Bước 2: Cấp phát động, khởi tạo Node
Node* initNode(float value)
{
  Node *p = new Node;
  (*p).data = value;
  p->pNext = NULL;
  return p;
}

struct HashTable {
  struct Bucket{
    Node* pHead;
    Node* pTail;
  };
  Bucket buckets[SIZE];
};

void initHashTable(HashTable& h) {
  for (int i = 0; i < SIZE; i++) {
    h.buckets[i].pHead = NULL;
    h.buckets[i].pTail = NULL;
  }
}

int main() {
  return 0;
}
