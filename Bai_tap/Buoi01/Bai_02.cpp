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
    cout << arr[i] << "; ";
  }
}

/* Hàm in kết quả mảng có số cp or số nguyên tố hay không
Input: double arr, size mảng
 */
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

/* Hàm in vị trí value trong mảng
Input: double arr, size mảng, value giá trị cần tìm
Output: return index value, tìm không thấy trả về -1
 */
int viTriValueCanTimTrongMang(double* arr, int size, double value) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) {
      return i;
    }
  }
  return -1;
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

/* Hàm tạo mảng số nguyên tố
 Input: double arr, size kích thước, mảng arrSoNguyenTo
 */
void createArrSoNguyenTo(double* arr, int size, double* arrSoNguyenTo) {
  for (int i = 0; i < size; i++) {
    if (kiemTraSoNT(arr[i])) {
      arrSoNguyenTo[i] = arr[i];
    }
  }
}

/* Hàm tạo mảng số chính phương
 Input: double arr, size kích thước, mảng arrSoCP
 */
void createArrSoChinhPhuong(double* arr, int size, double* arrSoCP) {
  for (int i = 0; i < size; i++) {
    if (kiemTraSoCP(arr[i])) {
      arrSoCP[i] = arr[i];
    }
  }
}

/* Hàm tạo mảng số âm
 Input: double arr, size kích thước, mảng arrSoAm
 */
void createArrSoAm(double* arr, int size, double* arrSoAm) {
  for (int i = 0; i < size; i++) {
    if (arr[i]<0) {
      arrSoAm[i] = arr[i];
    }
  }
}

/* Hàm tạo mảng số dương
 Input: double arr, size kích thước, mảng arrSoDuong
 */
void createArrSoDuong(double* arr, int size, double* arrSoDuong) {
  for (int i = 0; i < size; i++) {
    if (arr[i]>=0) {
      arrSoDuong[i] = arr[i];
    }
  }
}

/* Hàm tính tổng phần tử trong mảng
 Input: double arr, size kích thước
 Output: return sum
 */
double tinhTongArrTrongMang(double* arr, int size) {
  double sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

/* Hàm đảo ngược mảng
Ý tưởng
  1.	Duyệt từ đầu đến giữa mảng (i = 0 → size/2).
  2.	Lưu giá trị arr[i] vào biến temp.
  3.	Gán giá trị arr[size - 1 - i] vào arr[i].
  4.	Gán temp vào arr[size - 1 - i].
  5.	Tiếp tục lặp cho đến khi đạt trung tâm mảng.

Công thức hoán đổi:
tempArr[i] = arr[i]
arr[i] = arr[size - 1 - i]
arr[size - 1 - i] = tempArr[i]
 */
void daoNguocMang(double* &arr, int size) {
  double tempArr[size];
  for (int i = 0; i < size/2; i++) {
    tempArr[i] = arr[i];
    arr[i] = arr[size-i-1];
    arr[size-i-1] = tempArr[i];
  }
}

int main() {
  int n = 0; //kích thước mảng
  double* arr = new double[n];
  cout << "---------Bai 01---------" << endl;
  cout << "Câu 1: Đã tạo mảng số thực" << endl;
  createMang(arr, n);
  cout << endl;

  cout << "Câu 2: In mảng số thực" << endl;
  printMang(arr,n);
  cout << endl;
  cout << endl;

  cout << "Câu 3: Kiểm tra mạng có phải toàn bộ số dương không" << endl;
  if (isMangToanBoSoDuong(arr, n)) {
    cout << "-> Mảng toàn bộ value là số dương" << endl;
  } else {
    cout << "-> Mảng có chứa số âm" << endl;
  }
  cout << endl;

  cout << "Câu 6: Kiểm tra mảng có phải là mảng đối xứng hay không" << endl;
  if (isMangDoiXung(arr, n)) {
    cout << "-> Mảng của bạn là mảng đối xứng" << endl;
  } else {
    cout << "-> Mảng của bạn không phải mảng đối xứng" << endl;
  }
  cout << endl;

  cout << "Câu 7: Kiểm tra mảng có chưa số nguyên tố, số chính phương hay không" << endl;
  printKetQuaCoChinhPhuongVaNguyenTo(arr, n);
  cout << endl;

  cout << "Câu 8: Tìm giá trị bất kỳ trong mảng" << endl;
  int viTriValue = viTriValueCanTimTrongMang(arr,n,7.3);
  if (viTriValue != -1) {
    cout << "-> Vị trí value cần tìm là: " << viTriValue << endl;
  } else {
    cout << "-> Khong tim thay"<< endl;
  }
  cout << endl;

  cout << "Câu 9: Tìm các số nguyên tố trong mảng" << endl;
  double* arrSoNT = new double[n];

  createArrSoNguyenTo(arr,n,arrSoNT);
  printMang(arrSoNT,n);
  delete arrSoNT;
  arrSoNT = NULL;
  cout << endl;
  cout << endl;

  cout << "Câu 10: Tìm các số chính phương" << endl;
  double* arrSoCP = new double[n];
  createArrSoChinhPhuong(arr,n,arrSoCP);
  printMang(arrSoCP,n);
  delete arrSoCP;
  arrSoCP = NULL;
  cout << endl;
  cout << endl;

  cout << "Câu 11: Tìm các số am trong mang" << endl;
  double* arrSoAM = new double[n];
  createArrSoAm(arr,n,arrSoAM);
  printMang(arrSoAM,n);
  delete arrSoAM;
  arrSoAM = NULL;
  cout << endl;
  cout << endl;

  cout << "Câu 12: Tìm các số dương trong mảng" << endl;
  double* arrSoDuong = new double[n];
  createArrSoDuong(arr,n,arrSoDuong);
  printMang(arrSoDuong,n);
  cout << endl;
  cout << "-> Tổng các số dương trong mảng = " << tinhTongArrTrongMang(arrSoDuong,n) << endl;
  delete arrSoDuong;
  arrSoDuong = NULL;
  cout << endl;
  cout << endl;

  cout << "Câu 13: Đảo ngược các phần tử trong mảng" << endl;
  daoNguocMang(arr,n);
  printMang(arr,n);

  delete[] arr;
  arr = NULL;
  return 0;
}
