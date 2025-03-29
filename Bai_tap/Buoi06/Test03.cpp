//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

const int SIZE = 9;

// Bước 1: Định nghĩa cấu trúc Node
struct Node {
  int data;
  Node* pNext;
};

// Bước 2: Cấp phát động, khởi tạo Node
Node* initNode(int value)
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

/* Câu 1:  Viết hàm băm theo phương pháp chia
Input: int value
Output: int
 */
int hashFunc(int value) {
  int valueInt = value;
  return valueInt % SIZE;
}

// Hàm thêm giá trị float vào bẳng băm
// Input: HashTable& h
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

// Hàm khởi tạo bảng băm
// Input: HashTable&
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

// Hàm in bảng băm
// Input: HashTable
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

/* Câu 4: Hàm kiểm tra bảng băm rỗng hay không ?
 Input: HashTable h
 Output: bool
 */
bool isEmpty(HashTable h) {
  for (int i = 0; i < SIZE; i++) {
    if (h.buckets[i].pHead != NULL) {
      return false;
    }
  }
  return true;
}

/* Câu 6: Đếm các giá trị lưu trữ trong bảng băm
Input: HashTable h
Output: return int
 */
int countValues(HashTable h) {
  int count = 0;
  for (int i = 0; i < SIZE; i++) {
    for (Node* p = h.buckets[i].pHead; p != NULL; p = p->pNext) {
      count++;
    }
  }
  return count;
}

/* Câu 7: Viết hàm tìm giá trị có trong bảng băm
Input:
+ h: HashTable
+ value: int
Output:
+ bool: return
 */
bool timGiaTri(HashTable h, float value) {
  int viTri = hashFunc(value);
  for(Node* p = h.buckets[viTri].pHead; p != NULL; p = p->pNext) {
    if(p->data == value) {
      return true;
    }
  }
  return false;
}

int main() {
  cout << "Test câu 1,2,3,4: Khởi tạo giá trị cho bảng băm" << endl;
  HashTable h, emptyHash;
  initHashTable(h);
  initHashTable((emptyHash));
  initDataForHT(h);
  printHashTable(h);

  cout << "\nTest Câu 5: Kiểm tra bảng băm có rỗng hay không: h(0) " << isEmpty(h) << endl;
  cout << "Test Câu 5: Kiểm tra bảng băm có rỗng hay không: emptyHash(1) " << isEmpty(h) << endl;

  cout << "\nTest Câu 6: Đếm các giá trị có trong bảng băm: " << countValues(h) << endl;
  cout << "\nTest Câu 7: Tìm giá trị trong bảng băm: 905(1) = "<< timGiaTri(h,967) << endl;
  cout << "Test Câu 7: Tìm giá trị trong bảng băm: -2(0) = "<< timGiaTri(h,-2) << endl;
  return 0;
}