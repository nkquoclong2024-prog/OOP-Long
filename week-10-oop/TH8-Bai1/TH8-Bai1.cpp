#include "Quanli.h"
int main() {
    Quanli tmp;
    int luachon;

    do {
        cout << "\n================= MENU QUAN LY NHAN VIEN =================";
        cout << "\n1. Nhap danh sach nhan vien";
        cout << "\n2. Xuat danh sach nhan vien";
        cout << "\n3. Tinh tong luong cong ty phai tra cho nhan vien";
        cout << "\n4. Tim nhan vien san xuat co luong thap nhat";
        cout << "\n5. Tim nhan vien van phong lon tuoi nhat";
        cout << "\n0. Thoat chuong trinh";
        cout << "\n==========================================================";
        cout << "\nNhap lua chon cua ban: ";
        cin >> luachon;

        switch (luachon) {
            case 1:
                cout << "\n--- 1. NHAP DANH SACH NHAN VIEN ---\n";
                tmp.Nhap();
                break;
            case 2:
                cout << "\n--- 2. XUAT DANH SACH NHAN VIEN ---\n";
                tmp.xuat();
                break;
            case 3:
                cout << "\n--- 3. TONG LUONG CONG TY PHAI TRA ---\n";
                cout << "-> Tong tien luong: " << fixed << setprecision(0) << tmp.Tong_Luong_CT_Tra_Cho_NV() << " VND\n";
                break;
            case 4:
                cout << "\n--- 4. NHAN VIEN SAN XUAT CO LUONG THAP NHAT ---\n";
                tmp.NVSX_Luong_min();
                break;
            case 5:
                cout << "\n--- 5. NHAN VIEN VAN PHONG LON TUOI NHAT ---\n";
                tmp.NVVP_Tuoi_max();
                break;
            case 0:
                cout << "\nThoat chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "\nLua chon khong hop le. Vui long nhap lai tu 0 den 5!\n";
                break;
        }
    } while (luachon != 0);

    return 0;
}