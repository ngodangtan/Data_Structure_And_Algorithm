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

/* Viết hàm băm theo phương pháp chia
Input: int value
Output: int
 */
int hashFunc(float value) {
  int valueInt = (int)value;
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

/* Câu 5: Viết hàm tìm giá trị có trong bảng băm
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

/*
 */
/* Câu 6 Yêu cầu: Viết hàm xoá một giá trị bất kỳ trong bảng băm ?
Input:
+ l: HashTable& l, removeValue: Giá trị muốn xoá
Output:
+  return bool
+ x: HashTable&
*/
bool removeGiaTri(HashTable& h, float removeValue) {
  int viTri = hashFunc(removeValue);
  Node* prev = NULL;
  for (Node* current = h.buckets[viTri].pHead; current != NULL; current = current->pNext) {
    if (current->data == removeValue) {
      // Nếu current là node đầu tiên
      if (prev == NULL) {
        h.buckets[viTri].pHead = current->pNext;
        if (h.buckets[viTri].pHead == NULL) {
          h.buckets[viTri].pTail = NULL;
        }
      } else {
        prev->pNext = current->pNext;
        if (current == h.buckets[viTri].pTail) {
          h.buckets[viTri].pTail = prev;
        }
      }
      delete current;
      return true;
    }
    prev = current;
  }
  return false;
}

/* Câu 7: Viết hàm tính tổng gía trị lẻ trong bảng băm
 Input: HashTable h
 Output: return float
 */
float tongGiaTriLe(HashTable h) {
  float tong = 0;
  for (int i = 0; i < SIZE; i++) {
    for(Node* p = h.buckets[i].pHead; p != NULL; p = p->pNext) {
      if (int(p->data) % 2 != 0) {
        tong += p->data;
      }
    }
  }
  return tong;
}

/* Câu 8: Hàm kiểm tra bảng băm rỗng hay không ?
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

/* Câu 9: Viết hàm xử lý bẳng băm theo một điều kiện bất kỳ.
 -> Hàm đếm số dương trong bảng băm
 Input: HashTable h
 Output: return int số lượng
 */

int demSoDuong(HashTable h) {
  int soLuong = 0;
  for (int i = 0; i < SIZE; i++) {
    for(Node* p = h.buckets[i].pHead; p != NULL; p = p->pNext) {
      if (int(p->data) > 0) {
        soLuong++;
      }
    }
  }
  return soLuong;
}

int main() {
  HashTable h, emptyHash;
  initHashTable(h);
  initHashTable((emptyHash));
  cout << "\nTest câu 1,2: Tạo dữ liệu tự động cho bảng băm" << endl;
  initDataForHT(h);
  cout << "\nTest Câu 4: In bảng băm" << endl;
  printHashTable(h);

  cout << "\nTest câu 5: Tìm giá trị trong bảng băm: 967(1) = "<< timGiaTri(h,967) << endl;


  cout << "\nTest Câu 6: Xoá giá trị trong bảng băm: 880(1) , -1(0)" << endl;
  if (removeGiaTri(h, 880)) {
    cout << "Gia Tri 880 removed thành công" << endl;
  } else {
    cout << "Remove giá trị 880 thất bại" << endl;
  }

  if (removeGiaTri(h, -1)) {
    cout << "Gia Tri -1 removed thành công" << endl;
  } else {
    cout << "Remove giá trị -1 thất bại" << endl;
  }

  printHashTable(h);

  cout << "\nTest Câu 7: Tổng số lẻ trong bảng băm là " << tongGiaTriLe(h) << endl;

  cout << "\nTest Câu 8: Kiểm tra bảng băm có rỗng hay không: h(0) " << isEmpty(h) << endl;
  cout << "\nTest Câu 8: Kiểm tra bảng băm có rỗng hay không: emptyHash(1) " << isEmpty(emptyHash) << endl;
  cout << "\nTest Câu 9: Đếm số dương trong bảng băm: " << demSoDuong(h) << endl;
  return 0;
}
