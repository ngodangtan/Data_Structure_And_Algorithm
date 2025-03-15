//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

// Bước 1: Tạo cấu trúc Node
struct Node {
    int data;
    Node *pNext;
    Node *pPrev;
};

// Bước 2: Cấp phát động Node dùng để lưu data
Node* initNode(int value) {
    Node* p = new Node;
    if (p==NULL) {
        return NULL;
    }

    p->data = value;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}
// Bước 3: Tạo cấu trúc liên kết đôi
struct Queue {
    Node* pFront;
    Node* pRear;
};

// Bước 4: Khởi tạo List
// Câu 1: Viết hàm khởi tạo Queue
void initQueue(Queue& q) {
    q.pFront = q.pRear = NULL;
}

// Câu 3: Viết hàm đưa một phần tử vào Queue
void EnQueue(Queue &q, Node *p) {
    if (q.pFront == NULL) {
        q.pFront = p;
        q.pRear = p;
    } else {
        q.pRear->pNext = p;
        q.pRear = p;
    }
}

// Câu 4: Viết hàm lấy một phần tử ra khỏi queue
bool DeQueue(Queue &q) {
    if (q.pFront == NULL) {
        return false;
    }

    Node *p = q.pFront; // 1
    q.pFront = q.pFront->pNext; // 2
    delete p; //3
    if (q.pFront == NULL) {
        q.pRear = NULL;
    }

    return true;
}

void printQueue(Queue q) {
    cout << "Queue q = front <<   ";
    for (Node *p = q.pFront; p != NULL; p = p->pNext) {
        cout << p->data << "    ";
    }
    cout << ">" << endl << endl;
}

/* Câu 2 Viết hàm kiểm tra Queue có rỗng hay không
Input: Queue q
Output: return true queue rỗng,
                false queue không rỗng
 */
bool isEmptyQueue(Queue q) {
  for (Node *p = q.pFront; p != NULL; p = p->pNext) {
    return false;
  }
  return true;
}

int main() {
    Queue q;
    // Câu 1: Khởi tạo Queue
    initQueue(q);
    cout << "Test câu 2: Queue có rỗng hay không: " << isEmptyQueue(q) << " (1) queue rỗng" << endl;

    EnQueue(q, initNode(10));
    EnQueue(q, initNode(20));
    EnQueue(q, initNode(30));
    printQueue(q);
    cout << "Test câu 2: Queue có rỗng hay không: " << isEmptyQueue(q) << " (0) queue khong rỗng" << endl;
    DeQueue(q);
    printQueue(q);
    return 0;
}