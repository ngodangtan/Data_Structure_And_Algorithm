//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
using namespace std;

/* Hàm làm tròn 2 chữ số sau dau thap phan.
Input:
+ double n
Output:
+ return int value
Exp: n = 12.33329 => 12.33
n = 12.339 => 12.34
 */
double lamTron2ChuSo(double num) {
    return (int) (num * 100 + 0.5) / 100.0;
}

/* Hàm in mang.
Input:
+ double arr, size array
 */
void printArray(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "; ";
    }
    cout << endl;
}

/* Hàm in các phần tử chẵn có trong mảng
 Lưu ý: chẵn-lẻ dựa vào giá trị nguyên của số thực
Input:
+ double arr, size array
 */
void printEvenValue(double arr[], int size) {
    cout << "Các phần tử chẵn có trong mảng" << endl;
    for (int i = 0; i < size; i++) {
        if ((int)arr[i] % 2 == 0) {
            cout << arr[i] << "; ";
        }
    }
}

/* Hàm in các phần tử âm có trong mảng
Input:
+ double arr, size array
 */
void printSoAmTrongMang(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            cout << arr[i] << "; ";
        }
    }
}

void printPhanTuTrongKhoang(double arr[], int size, double x, double y) {
    bool isNotTrongKhoang = true;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= x && arr[i] <= y) {
            cout << arr[i] << "; ";
            isNotTrongKhoang = false;
        }
    }

    if (isNotTrongKhoang == true) {
        cout << "Không có giá trị nào trong khoảng " << x << ", " << y << endl;
    }
}

/* Hàm đảo ngược (reversed) mảng hiện tại
 Input: arr, size, arr sẽ bị đảo ngược
 công thức đảo ngược mảng: arr[i] = arr[size-1-i]
 */
void daoNguocMang(double arr[], int size, double arrReversed[]) {
    for (int i = 0; i < size; i++) {
        arrReversed[i] = arr[size-1-i];
    }
}

/* Hàm tính tổng giá trị có trong mảng.
Input:
+ double array, int size
Output:
+ return double sum tong giá trị trong mảng
 */
double sumArr(double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return  lamTron2ChuSo(sum);
}

/* Hàm tính tổng và tích giá trị có trong mảng.
Input:
+ double array, int size
 */
void tichVaTongTrongMang(double arr[], int size, double &tich, double &tong) {
    tich = 1;
    tong = 0;
    for (int i = 0; i < size; i++) {
        tich *= arr[i];
        tong += arr[i];
    }
}

/* Hàm đếm số lần xuất hiện giá trị x bất kỳ.
Input:
+ double array, int size, gia tri cần đếm số lần xuất hiện x
Output:
+ return int số lần xuất hiện
 */
int soLanXuatHien(double arr[], int size, double x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
}

/* Hàm tìm phần tử nhỏ nhất trong mảng.
Input:
+ double array, int size, double minValue
 */
void phanTuNhoNhatTrongMang(double arr[], int size, double &minValue) {
    if (size == 0) {
        cout << "Mảng không có giá trị nào" << endl;
    }

    minValue = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
}

/* Hàm đếm số lượng phần tử trong đoạn [x,y]
 Input: double arr[], size mảng, đoạn x,y
 Output: int value số lượng phần tử
 */
int demSoLuongPhanTuTrongKhoang(double arr[], int size, double x, double y) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >=x && arr[i] <= y) {
            count++;
        }
    }
    return  count;
}

/* Tạo giá trị ngẫu nhiên a[i] (số thực, 2 chữ số sau dấu chấm) thuộc khoảng (-268; 339). Số lượng (n) thuộc đoạn [10; 20].
Công thức: giá trị ngẫu nhiên = rand()%(max-min) + min
Input:
+ array float a[] (), int n
Note ly thuyet
parameter a[] default is pass by reference (ko can &)
=> Điều này có nghĩa là nếu thay đổi giá trị của arr[i] trong function, nó cũng sẽ thay đổi trong main().
int &n khai báo truyền dạng tham chiếu reference
Output:
+ new array
 */

void autoArr(double a[], int &n) {
    n = 10 + rand() % 11;
    for (int i = 0; i < n; i++) {
        double randomValue = -268 + rand() % 607;
        a[i] = lamTron2ChuSo(randomValue);
    }
}


int main() {
    double a[20], arrReversed[20];
    int n = 0;
    double kqTich,kqTong,giaTriCanTim,minValue;

    //---Bai 01----
    cout << "---------Bai 01---------" << endl;
    cout << "Cau 1: Tao mang ngau nhien mang" << endl;
    autoArr(a, n);

    cout << "Cau 2: In mang vua tao" << endl;
    printArray(a,n);

    cout << "Cau 3: Tinh tong gia tri trong mang" << endl;
    cout << sumArr(a,n) << endl;

    cout << "Cau 4: Tinh tich gia tri trong mang" << endl;
    tichVaTongTrongMang(a,n,kqTich,kqTong);
    cout << "Ket qua tich: " << lamTron2ChuSo(kqTich) << endl;
    cout << "Ket qua tong: " << lamTron2ChuSo(kqTong) << endl;

    cout << "Cau 5: Dem gia tri x bat ky" << endl;
    cout << "Vui long nhap gia tri x bat ky: " << endl;
    cin >> giaTriCanTim;
    cout << "Số lần xuất hiện gía trị x trong mang là: " << soLanXuatHien(a,n,giaTriCanTim) << " lần" << endl;

    cout << "Cau 6: In phần tử chẵn có trong mảng (chẵn-lẻ dựa vào giá trị nguyên của số thực)" << endl;
    printEvenValue(a,n);

    cout << "Câu 7 : Tìm phần tử nhỏ nhất trong mảng" << endl;
    phanTuNhoNhatTrongMang(a,n,minValue);

    cout << "Câu 8: Tạo một mảng đảo ngược" << endl;
    daoNguocMang(a,n,arrReversed);
    printArray(arrReversed,n);

    cout << "Câu 9: In các số âm trong mảng" << endl;
    printSoAmTrongMang(a,n);
    cout << endl;

    cout << "Câu 10: Số lượng phần tử các giá trị trong đoạn [x,y]" << endl;
    cout << demSoLuongPhanTuTrongKhoang(a,n,2,10) << endl;

    cout << "Câu 11: In giá trị trong mảng thuộc đoạn [x,y]" << endl;
    printPhanTuTrongKhoang(a,n,2,10);
    return 0;
}
