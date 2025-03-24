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

// Bước 5: Định nghĩa cấu trúc bẳng băm
const int SIZE = 5;
struct HashTable {
    // Bước 3: Tạo cấu trúc Bucket
    struct Bucket{
        Node* pHead;
        Node* pTail;
    };
    Bucket buckets[SIZE];
};

// Bước 6: Khởi tạo bẳng băm
void initHashTable(HashTable& h) {
    for (int i = 0; i < SIZE; i++) {
        h.buckets[i].pHead = NULL;
        h.buckets[i].pTail = NULL;
    }
}

void initHashTable(HashTable& h, int Size) {
    for (int i = 0; i < Size; i++) {
        h.buckets[i].pHead = NULL;
        h.buckets[i].pTail = NULL;
    }
}

int hashFunc(int value) {
    return value % SIZE;
}

int hashFunc(Node* node) {
    return (node->data)%SIZE;
}

void add(HashTable& h, int value) {
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

void add(HashTable& h, Node* p) {
    // Bước 1: chọn vị trí bucket
    int viTri = hashFunc(p);
    // Bước 2: add vào bucket
    if(h.buckets[viTri].pHead == NULL) {
        h.buckets[viTri].pHead = p;
        h.buckets[viTri].pTail = p;
    } else {
        h.buckets[viTri].pTail->pNext = p;
        h.buckets[viTri].pTail = p;
    }
}

// Cau 1
void initDataForHT(HashTable& h) {
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

/* 3. Viết hàm tạo dữ liệu cho bảng băm từ mảng một chiều
Input:
+ h: HashTable
+ arr: int[]
+ n: int
Output:
+ h: HT&
+
 */
void initDataFromArray(HashTable& h, int a[], int n) {
  for(int i = 0; i < n; i++) {
    add(h, a[i]);
  }
}
/* Viết hàm tìm giá trị có trong bảng băm
Input:
+ h: HashTable
+ value: int
Output:
+ bool: return
 */
bool timGiaTri(HashTable h, int value) {
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

    // Thử làm cấp phát động size dynamic v3
    HashTable h2;
    initHashTable(h2, 10);
    cout << "Test: 1. Khởi tạo dữ liệu cho hashtable" << endl;
    initDataForHT(h);

    cout << "\nTest: 2 In hash table:" << endl;
    printHashTable(h);
    cout << "\nTest: 3. " << endl;
    int a[] = {78,13,67,12,90};
    int n = 5;
    initDataFromArray(h, a, n);
    printHashTable(h);
    cout << "\nTest: 4. " << endl;
    cout << "\nTest: 5. Tìm giá trị trong bảng băm" << endl;
    cout << "\n + Tìm(67) = 1 = " << timGiaTri(h,67) << endl;
    cout << "\n + Tìm(99) = 0 = " << timGiaTri(h,99) << endl;
    cout << "\nTest: 6. " << endl;
    return 0;
}