//
// Created by Ngo Dang Tan on 21/2/25.
// MSSV: 24210173@ms.uit.edu.vn
//

#include <iostream>
#include <string>
using namespace std;

struct NhanVien {
    string maNV;
    string hoTen;
    int luongCB;
    int soNgayLam;
    long luongHangThang;
};

/* Hàm tính lương hàng tháng
 Input: luongCB, so ngay làm
 Output: số tiền lương hàng tháng
 */
long tinhLuongHT(int luongCB, int soNgayLam) {
    int result = luongCB + soNgayLam * 180000;
    if (result > 8000000) {
       double thuong = result * 1.05;
        result += thuong;
    }

    if (luongCB < 5000000) {
        double phuCap = result * 1.1;
        result += phuCap;
    }
    return result;
}

/* Hàm tạo random string
 Input: int n độ dài ký tự sẽ được random
 Output: string chuỗi được random theo độ dài n
 */
string taoRandomString(int n) {
    string result = "";
    for (int i = 0; i < n; i++) {
        char randomChar = 'A' + rand() % 26;
        result += randomChar;
    }
    return result;
}

/* Hàm tạo danh sách NV random
 Input: mangNV
 Output: string chuỗi được random theo độ dài n
 */
void taoDanhSachNV(NhanVien * &arrNV, int size) {
    for (int i = 0; i < size; i++) {
        arrNV[i].maNV = "000" + to_string(i);
        arrNV[i].hoTen = "Nguen Van " + taoRandomString(2);
        arrNV[i].soNgayLam = rand() % 30 + 1;
        if (i%2 == 0) {
            arrNV[i].luongCB = 6000000;
        } else {
            arrNV[i].luongCB = 4000000;
        }
       arrNV[i].luongHangThang = tinhLuongHT(arrNV[i].luongCB, arrNV[i].soNgayLam);
    }
}

/* Hàm in danh sách Nhân viên
Input: mảng nhân viên, kích thước
 */
void printDanhSachNV(NhanVien* arrNV, int size) {
    for (int i = 0; i < size; i++) {
        cout <<i<<" -----------------" << endl;
        cout << "MA NV: " <<arrNV[i].maNV << endl;
        cout << "Ho Ten: " << arrNV[i].hoTen << endl;
        cout << "Luong CB: " << arrNV[i].luongCB << endl;
        cout << "So Ngay Lam: " <<arrNV[i].soNgayLam << endl;
        cout << "Luong HT: " << arrNV[i].luongHangThang << endl;
        cout << endl;
    }
}

/* Hàm tính tổng lương NV
Input: mảng nhân viên, kích thước mảng
Output: tongLuongNV trong công ty
 */
long tongLuongNVCongTy(NhanVien* arrNV, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arrNV[i].luongHangThang;
    }
    return sum;
}

int main() {
    srand(time(0));
    int size = 10;
    NhanVien *arrNV = new NhanVien[size];
    taoDanhSachNV(arrNV,size);
    printDanhSachNV(arrNV, size);

    cout << "Tổng lương toàn bộ NV trong công ty" << endl;
    cout << tongLuongNVCongTy(arrNV, size) << endl;

    delete[] arrNV;
    arrNV = NULL;
    return 0;
}
