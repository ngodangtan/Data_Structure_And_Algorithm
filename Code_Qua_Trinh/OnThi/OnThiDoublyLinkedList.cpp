//
//  main.cpp
//  Test
//
//  Created by Felix Ngo on 8/4/25.
//

#include <iostream>

struct Node {
    int data;
    Node* pPrev;
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
    p->pPrev = NULL;
    return p;
}

void initList(List& list) {
    list.pHead = NULL;
    list.pTail = NULL;
}

void addHead(List& list, Node* p) {
    if(list.pTail == NULL) {
        list.pHead = p;
        list.pTail = p;
    } else {
        p->pNext = list.pHead;
        list.pHead->pPrev = p;
        list.pHead = p;
    }
}

void addTail(List& list, Node* p) {
    if(list.pTail == NULL) {
        list.pHead = p;
        list.pTail = p;
    } else {
        list.pTail->pNext = p;
        p->pPrev = list.pTail;
        list.pTail = p;
    }
}

void insertAtPosition(List& list, int position, Node* p) {
    if (position <= 1 || list.pHead == NULL) {
        addHead(list, p);
        return;
    }

    Node* currNode = list.pHead;
    int index = 1;

    // Di chuyển tới node ở vị trí (position - 1)
    while (currNode != NULL && index < position - 1) {
        currNode = currNode->pNext;
        index++;
    }

    // Nếu currNode là NULL hoặc đang ở cuối danh sách, chèn vào cuối
    if (currNode == NULL || currNode == list.pTail) {
        addTail(list, p);
    } else {
        p->pNext = currNode->pNext;
        if (currNode->pNext != NULL)
            currNode->pNext->pPrev = p;
        currNode->pNext = p;
        p->pPrev = currNode;

        // Nếu vừa chèn sau phần tử cuối thì cập nhật lại pTail
        if (p->pNext == NULL) {
            list.pTail = p;
        }
    }
}

void printListFor(List list) {
    if (list.pHead == NULL) {
        return;
    }

    for(Node* p = list.pHead; p != NULL; p=p->pNext) {
        std::cout << p->data << std::endl;
    }
}

void printWhile(List list) {
    if(list.pHead == NULL) {
        return;
    }
    Node *p = list.pHead;
    while (p!=NULL) {
        std::cout << p->data << std::endl;
        p=p->pNext;
    }
}

void printNguocChieu(List list) {
    if(list.pHead == NULL) {
        return;
    }

    for(Node* p = list.pTail; p != NULL;p=p->pPrev) {
        std::cout << p->data << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    List list;
    initList(list);
    Node* p1 = initNode(10);
    Node* p2 = initNode(20);
    Node* p3 = initNode(30);
    Node* p4 = initNode(50);
    Node* p5 = initNode(40);

    addHead(list, p1);
    addHead(list, p2);
    addTail(list,p3);
    addTail(list,p4);
    printWhile(list);
    std::cout<<"Insert test"<<std::endl;
    insertAtPosition(list, 3, p5);
    printWhile(list);

    return 0;
}
