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
    long luongCB;
    int soNgayLam;
    long luongHangThang;
};

/* Hàm tự động tăng kích thước mảng và append giá trị mới
 Input: Mảng cần tăng và thêm giá trị, kích thước mảng, giá trị sẽ thêm vào
 */
void append(NhanVien*& arr, int& size, NhanVien value) {
    // Tạo mảng mới với kích thước lớn hơn
    NhanVien* newArr = new NhanVien[size + 1];

    // Sao chép dữ liệu từ mảng cũ sang mảng mới
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    // Thêm phần tử mới vào cuối mảng
    newArr[size] = value;

    // Giải phóng bộ nhớ của mảng cũ
    delete[] arr;

    // Trỏ arr sang mảng mới
    arr = newArr;

    // Tăng kích thước mảng
    size++;
}


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

void printNV(NhanVien nv) {
    cout << "MA NV: " <<nv.maNV << endl;
    cout << "Ho Ten: " << nv.hoTen << endl;
    cout << "Luong CB: " << nv.luongCB << endl;
    cout << "So Ngay Lam: " <<nv.soNgayLam << endl;
    cout << "Luong HT: " << nv.luongHangThang << endl;
    cout << endl;
}

/* Hàm in danh sách Nhân viên
Input: mảng nhân viên, kích thước
 */
void printDanhSachNV(NhanVien* arrNV, int size) {
    for (int i = 0; i < size; i++) {
        cout <<i<<" -----------------" << endl;
        printNV(arrNV[i]);
    }
}



/* Hàm tính tổng lương NV
Input: mảng nhân viên, kích thước mảng
Output: tongLuongNV trong công ty
 */
long tongLuongNVCongTy(NhanVien* arrNV, int size) {
    long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arrNV[i].luongHangThang;
    }
    return sum;
}

/* Hàm tính tổng lương cua NV < 5000000
Input: mảng nhân viên, kích thước mảng
Output: tongLuongNV trong công ty
 */
long tongLuongNVNhoHon5Tr(NhanVien* arrNV, int size) {
    long sum = 0;
    for (int i = 0; i < size; i++) {
        if (arrNV[i].luongHangThang < 5000000) {
            sum += arrNV[i].luongHangThang;
        }
    }
    return sum;
}

NhanVien* timNVTheoMaNV(NhanVien* arrNV, int size, string maNV) {
    NhanVien* result = NULL;
    for (int i = 0; i < size; i++) {
        if (arrNV[i].maNV == maNV) {
            result = &arrNV[i];
            return result;
        }
    }
}

/* Hàm tìm lương HT nhỏ nhất trong danh sách nhân viên
 */
long luongHTMinTrongDanhSachNV(NhanVien* arrNV, int size) {
    long minLuongHT = arrNV[0].luongHangThang;
    for (int i = 0; i < size; i++) {
        if (arrNV[i].luongHangThang < minLuongHT) {
            minLuongHT = arrNV[i].luongHangThang;
        }
    }
    return minLuongHT;
}

/* Hàm tìm lương CB lớn nhất trong danh sách nhân viên
 */
long luongCBMaxTrongDanhSachNV(NhanVien* arrNV, int size) {
    long maxLuongCB = arrNV[0].luongCB;
    for (int i = 0; i < size; i++) {
        if (arrNV[i].luongCB > maxLuongCB) {
            maxLuongCB = arrNV[i].luongCB;
        }
    }
    return maxLuongCB;
}

/* Hàm xuất list nhân viên lương hàng tháng bằng nhau thấp nhất
 */
void xuatNVLuongHTThapNhat(NhanVien* arrNV, int size) {
    long minLuongHT = luongHTMinTrongDanhSachNV(arrNV, size);
    int sizeArrNVMinLuong = 0;
    NhanVien* arrNVMinLuong = new NhanVien[size];
    for (int i = 0; i < size; i++) {
        if (arrNV[i].luongHangThang == minLuongHT) {
            append(arrNVMinLuong, sizeArrNVMinLuong, arrNV[i]);
        }
    }

    for (int i = 0; i < size; i++) {
        if (arrNVMinLuong[i].maNV != "") {
            printNV(arrNVMinLuong[i]);
        }
    }
}

void xuatNVLuongCBCaoNhat(NhanVien* arrNV, int size) {
    long maxLuongCB = luongCBMaxTrongDanhSachNV(arrNV, size);
    int sizeArrNVMaxLuongCB = 0;
    NhanVien* arrNVMaxLuongCB = new NhanVien[size];
    for (int i = 0; i < size; i++) {
        if (arrNV[i].luongCB == maxLuongCB) {
            append(arrNVMaxLuongCB, sizeArrNVMaxLuongCB, arrNV[i]);
        }
    }

    for (int i = 0; i < size; i++) {
        if (arrNVMaxLuongCB[i].maNV != "") {
            printNV(arrNVMaxLuongCB[i]);
        }
    }
}


int main() {
    srand(time(0));
    int size = 10;
    NhanVien *arrNV = new NhanVien[size];
    taoDanhSachNV(arrNV,size);
    printDanhSachNV(arrNV, size);

    cout << "Tổng lương toàn bộ NV trong công ty" << endl;
    cout << tongLuongNVCongTy(arrNV, size) << endl;

    cout << "Tổng lương toàn bộ NV trong công ty < 5000000" << endl;
    cout << tongLuongNVNhoHon5Tr(arrNV, size) << endl;

    cout << "Tìm nhân viên theo mã 0009" << endl;
    NhanVien* nv = timNVTheoMaNV(arrNV,size,"0009");
    if (nv != NULL) {
        cout << "Tìm có nhân viên: " << nv->hoTen << endl;
        cout << "Mã nhân viên: " << nv->maNV << endl;
    } else {
        cout << "Ko co"<< endl;
    }

    cout << endl;
    cout << "Tìm các nhân viên có lương hàng tháng thấp nhất" << endl;
    xuatNVLuongHTThapNhat(arrNV, size);

    cout << endl;
    cout << "Tìm các nhân viên có lương CB tháng cao nhất" << endl;
    xuatNVLuongCBCaoNhat(arrNV, size);

    // delete[] arrNV;
    // delete nv;
    // arrNV = NULL;
    // nv = NULL;
    return 0;
}
