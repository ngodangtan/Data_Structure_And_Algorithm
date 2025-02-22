//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

/* Hàm tạo mảng
Input: double arr, size mảng
 */
void createMang(double* &arr, int &size) {
  size = 10;
  arr = new double[size] {0.8, 5.6, 9.1, 7.3, 10, 5.9, 7.2, 9.3, 8.0, 8.7};
}

bool kiemTraSoCP(int n)
{
  // Buoc 1:
  if (n <= 0)
    return false;
  // Buoc 2: (i=0)^2 , 1,2,3,4..     == n
  for (int i = 0; i * i <= n; i++)
  {
    if (i *i == n)
      return true;
  }
  return false;
}

/*
Viet ham kiem tra so n co phai la so chinh nguyen to
Input:
+ n: int
Output:
+ bool => return True(so CP), False (ko false)
*/

bool kiemTraSoNT(int n)
{
  // Buoc 1
  if (n <= 1)
    return false;
  // Buoc 2: 2 -----> n-1
  for (int i = 2; i * i <= n - 1; i++)
  {
    if (n % i == 0)
      return false;
  }

  return true;
}

/* Hàm in mảng
Input: double arr, size mảng
 */
void printMang(double* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}

void printKetQuaCoChinhPhuongVaNguyenTo(double* arr, int size) {
  bool isHaveSoCP = false;
  bool isHaveNT = false;
  for (int i = 0; i < size; i++) {
    if (kiemTraSoNT(arr[i])) {
      isHaveNT = true;
    }

    if (kiemTraSoCP(arr[i])) {
      isHaveSoCP = true;
    }
  }
  if (isHaveNT) {
    cout << "Mảng có số nguyên tố" << endl;
  }

  if (isHaveSoCP) {
    cout << "Mảng có số chính phương" << endl;
  }
}

/* Hàm kiểm tra toàn bộ value phải số dương hay không
Input: double arr, size mảng
Output: return bool true là all số dương
false là có chứa số âm
 */
bool isMangToanBoSoDuong(double* arr, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] < 0) {
      return false;
    }
  }
  return true;
}

// Ý tưởng kiểm tra mảng đối xứng
//	1.	Duyệt từ đầu đến giữa mảng (i = 0 → size/2).
//	2.	So sánh phần tử đầu (arr[i]) với phần tử cuối đối xứng (arr[size - 1 - i]).
//	3.	Nếu tất cả cặp phần tử đều giống nhau, mảng đối xứng. Nếu có một cặp khác nhau, mảng không đối xứng.
/* Hàm kiểm tra mảng có đối xứng hay không
Input: double arr, int size
Output: bool value
true là mảng đối xứng, false không phải
 */
bool isMangDoiXung(double* arr, int size) {
  for (int i = 0; i < size/2; i++) {
    if (arr[i]!= arr[size-1-i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n = 0; //kích thước mảng
  double* arr = new double[n];
  cout << "---------Bai 01---------" << endl;
  cout << "Câu 1: Tạo mảng số thực" << endl;
  createMang(arr, n);

  cout << "Câu 2: In mảng số thực" << endl;
  printMang(arr,n);

  cout << "Câu 3: Kiểm tra mạng có phải toàn bộ số dương không" << endl;
  if (isMangToanBoSoDuong(arr, n)) {
    cout << "Mảng toàn bộ value là số dương" << endl;
  } else {
    cout << "Mảng có chứa số âm" << endl;
  }

  cout << "Câu 6: Kiểm tra mảng có phải là mảng đối xứng hay không" << endl;
  if (isMangDoiXung(arr, n)) {
    cout << "Mảng của bạn là mảng đối xứng" << endl;
  } else {
    cout << "Mảng của bạn không phải mảng đối xứng" << endl;
  }

  cout << "Câu 7: Kiểm tra mảng có chưa số nguyên tố, số chính phương hay không" << endl;
  printKetQuaCoChinhPhuongVaNguyenTo(arr, n);

  delete arr;
  arr = nullptr;
  return 0;
}
