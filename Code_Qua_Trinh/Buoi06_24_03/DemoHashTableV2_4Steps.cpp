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

    // Thử làm cấp phát động size dynamic v3
    HashTable h2;
    initHashTable(h2, 10);

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