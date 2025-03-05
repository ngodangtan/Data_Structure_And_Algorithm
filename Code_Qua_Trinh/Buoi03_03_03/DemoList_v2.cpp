//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

// Buoc 01: Tạo cấu trúc Node
struct Node {
    int data;
    Node *pNext; // lưu trữ địa chỉ của Node phía sau
};

// Bước 2: Khởi tạo Node để lưu giá trị cần lưu.
Node *initNode(int value) {
    Node *p = new Node;
    p->data = value;
    p->pNext = NULL; // chứa lưu trữ địa chỉ Node tiếp theo, set = NULL
    return p;
}

// Bước 3: Tạo cấu trúc danh sách
struct List {
    Node *pHead;
    Node *pTail;
};

// Bước 4: Khởi tạo danh sách
void initList(List &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

void addHead(List &l, Node *p) {
    if (l.pHead == NULL) {
        l.pHead = p;
        l.pTail = p;
    } else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void addTail(List &l, Node *p) {
    if (l.pHead == NULL) {
        l.pHead = p;
        l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void printListWhile(List l) {
    if (l.pHead == NULL) {
        cout << "List rong" << endl;
        return;
    }
    Node *p = l.pHead;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->pNext;
    }
    cout << endl << endl;
}

void printListFor(List l) {
    if (l.pHead == NULL) {
        cout << "List rong" << endl;
        return;
    }
    for (Node *p = l.pHead; p != NULL; p = p->pNext) {
        cout << p->data << " ";
    }
    cout << endl << endl;
}

/* Yêu cầu: Viết hàm tìm kiếm một giá trị có trong List hay không ?
Input:
+ l: List
+ value: int
Output:
+  return bool
+
 */
bool timGiaTri(List l, int value) {
    for (Node *p = l.pHead; p != NULL; p = p->pNext) {
        if (p->data == value) {
            return true;
        }
    }
    return false;
}

/* Yêu cầu: Viết hàm đếm giá trị chẵn có trong List ?
Input:
+ l: List
Output:
+  return int
 */
int demGiaTri(List l) {
    int dem = 0;
    for (Node *p = l.pHead; p != NULL; p = p->pNext) {
        if (p->data % 2 == 0) {
            dem++;
        }
    }
    return dem;
}

/* Yêu cầu: Viết hàm tinh tong gia tri co trong danh sach ?
Input:
+ l: List l
Output:
+  return tong
 */

int tinhTong(List l) {
    int t = 0;
    for (Node *p = l.pHead; p != NULL; p = p->pNext) {
        t += p->data;
    }
    return t;
}

/* Yêu cầu: Viết hàm tim gia tri max ?
Input:
+ l: List l
Output:
+  return int // Gia tri max
 */
int timMax(List l) {
    int m = l.pHead->data;
    for (Node *p = l.pHead->pNext; p != NULL; p = p->pNext) {
        if (p->data > m) {
            m = p->data;
        }
    }
    return m;
}

/* Yêu cầu: Viết hàm xoa Node dau tien trong List ?
Input:
+ l: List& l
Output:
+  return bool
+ x: int&
*/
bool pop(List &l) {
    if (l.pHead == NULL) {
        return false;
    }

    Node *p = l.pHead; // 1
    l.pHead = l.pHead->pNext; // 2
    delete p; //3
    if (l.pHead == NULL) {
        l.pTail = NULL;
    }

    return true;
}

int main() {
    Node *p1 = initNode(10);
    Node *p2 = initNode(79);
    Node *p3 = initNode(39);

    List l;
    initList(l); //Danh sách rỗng

    addHead(l, p1);
    addHead(l, p2);

    addTail(l, p3);
    printListFor(l);
    printListWhile(l);
    cout << "Test: Tim(10)_(1): " << timGiaTri(l, 10) << endl;
    cout << "Test: Tim(29)_(0): " << timGiaTri(l, 29) << endl;

    cout << "Test: Tinh Tong: " << tinhTong(l) << endl;
    cout << endl;
    cout << "Test: Max = " << timMax(l) << endl;

    pop(l);
    printListFor(l);
    printListWhile(l);

    pop(l);
    printListFor(l);
    printListWhile(l);

    pop(l);
    printListFor(l);
    printListWhile(l);

    pop(l);
    printListFor(l);
    printListWhile(l);
    return 0;
}
