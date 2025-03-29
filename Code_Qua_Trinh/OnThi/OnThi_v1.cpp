//
//  main.cpp
//  TestC++
//
//  Created by Felix Ngo on 29/3/25.
//

#include <iostream>

struct Node {
    int data;
    Node* pNext;
};

struct List {
    Node* pHead;
    Node* pTail;
};

Node* initNode(int value) {
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}

void initList(List& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

void addHead(List& l, Node* p) {
    if(l.pTail == NULL) {
        l.pHead = p;
        l.pTail = p;
    } else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void addTail(List& l, Node* p) {
    if(l.pTail == NULL) {
        l.pHead = p;
        l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void printListFor(List l) {
    for(Node* p = l.pHead; p != NULL; p = p->pNext) {
        std::cout << p->data << std::endl;
    }
}

void printLishWhile(List l) {
    Node* p = l.pHead;
    while (p != NULL) {
        std::cout << p->data << std::endl;
        p = p->pNext;
    }
}

int countList(List l) {
    Node* p = l.pHead;
    int count = 1;
    while (p->pNext != NULL) {
        p = p->pNext;
        count ++;
    }
    return count;
}

int countListRecursively(Node* pHead) {
    if(pHead == NULL)
        return 0;
    return 1 + countListRecursively(pHead->pNext);
}

bool findValueInList(List l, int findValue) {
    for(Node* p = l.pHead; p != NULL; p = p->pNext) {
        if(p->data == findValue)
            return true;
    }
    return false;
}

void printNode(Node* p) {
    std::cout << p->data << std::endl;
}

Node* findNodeNearTail(List l) {
    // Nếu danh sách rỗng hoặc chỉ có 1 phần tử thì không có node kế cuối
    if (l.pHead == NULL || l.pHead->pNext == NULL) {
        return NULL;
    }

    Node* p = l.pHead;
    while (p->pNext->pNext != NULL) {
        p = p->pNext;
    }
    return p;
}

void removeHead(List& l) {
    Node* p = l.pHead;
    l.pHead = p->pNext;
    delete p;
}

// insertNode at position
void insetNodeAtPosition(List& l, int position, Node* p) {
    // Trường hợp chèn đầu danh sách hoặc danh sách đang rỗng
    if (position <= 1 || l.pHead == NULL) {
        addHead(l, p);
        return;
    }

    // Duyệt tới node ở vị trí (position - 1)
    Node* current = l.pHead;
    int index = 1;

    while (current != NULL && index < position - 1) {
        current = current->pNext;
        index++;
    }

    // Nếu vị trí chèn vượt quá độ dài danh sách, thêm vào cuối
    if (current == NULL || current == l.pTail) {
        addTail(l, p);
    } else {
        p->pNext = current->pNext;
        current->pNext = p;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    List l;
    initList(l);
    Node* p1 = initNode(10);
    Node* p2 = initNode(20);
    Node* p3 = initNode(30);
    Node* p4 = initNode(40);
    Node* p5 = initNode(50);

    addHead(l, p1);
    addHead(l, p2);
    addHead(l, p3);
    addHead(l, p4);
    addTail(l, p5);
    printLishWhile(l); // 40 30 20 10 50
    std::cout << "Node near tail" << std::endl;
    Node *nodeNearTail = findNodeNearTail(l);
    printNode(nodeNearTail);
    std::cout << "Remove head node" << std::endl;
    removeHead(l);
    printLishWhile(l);
    std::cout << "Insert Node at position 2" << std::endl;
    Node* p6 = initNode(60);
    insetNodeAtPosition(l, 2, p6);
    printLishWhile(l);

    std::cout << "Insert Node at position 3" << std::endl;
    Node* p7 = initNode(70);
    insetNodeAtPosition(l, 3, p7);
    printLishWhile(l);

    std::cout << "Số lượng item trong list là " << countList(l) << std::endl;
    std::cout << "Số lượng item trong list là (phương pháp đệ quy) " << countListRecursively(l.pHead) << std::endl;
    return 0;
}
