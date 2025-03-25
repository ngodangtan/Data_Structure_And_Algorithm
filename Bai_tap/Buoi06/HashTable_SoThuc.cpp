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

int hashFunc(float value) {
  int valueInt = (int)value;
  return valueInt % SIZE;
}

void add(HashTable& h, float value) {
  // Bước 1: chọn vị trí bucket
  int viTri = hashFunc(value);
  // Bước 2: add vào bucket
  Node* p = initNode(value);
  if(h.buckets[viTri].pHead == NULL) {
    h.buckets[viTri].pHead = p;
    h.buckets[viTri].pTail = p;
  } else {
    h.buckets[viTri].pTail->pNext = p;
    h.buckets[viTri].pTail = p;
  }
}

void initHashTable(HashTable& h) {
  for (int i = 0; i < SIZE; i++) {
    h.buckets[i].pHead = NULL;
    h.buckets[i].pTail = NULL;
  }
}

// Công thức: giá trị ngẫu nhiên = rand()%(max-min) + min
void initDataForHT(HashTable& h) {
  int soLuong = rand() % (95 - 45) + 450;
  for (int i = 0; i < soLuong; i++) {
    float value = rand() % (988 - 856) + 856;
    add(h, value);
  }
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

/* Viết hàm tìm giá trị có trong bảng băm
Input:
+ h: HashTable
+ value: int
Output:
+ bool: return
 */
bool timGiaTri(HashTable h, float value) {
  // 1. Tìm BK có khả năng chứa giá trị
  int viTri = hashFunc(value);
  // 2. Tìm giá trị xem có trên BK dự tính
  for(Node* p = h.buckets[viTri].pHead; p != NULL; p = p->pNext) {
    if(p->data == value) {
      return true;
    }
  }
  return false;
}

int main() {
  HashTable h;
  initHashTable(h);
  initDataForHT(h);
  printHashTable(h);
  return 0;
}
