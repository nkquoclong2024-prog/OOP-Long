#include "Quanlysinhvien.h"
int main() {
    quanly t;
    int luachon;

    do {
        cout << "\n================ MENU QUAN LY SINH VIEN ================\n";
        cout << "1. Nhap danh sach sinh vien\n";
        cout << "2. Xuat danh sach sinh vien\n";
        cout << "3. Danh sach sinh vien du dieu kien tot nghiep\n";
        cout << "4. Danh sach sinh vien KHONG du dieu kien tot nghiep\n";
        cout << "5. Sinh vien Dai hoc co DTB cao nhat\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "========================================================\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luachon;

        switch (luachon) {
            case 1:
                cout << "\n--- 1. NHAP DANH SACH SINH VIEN ---\n";
                t.nhap();
                break;
            case 2:
                cout << "\n--- 2. XUAT DANH SACH SINH VIEN ---\n";
                t.xuat();
                break;
            case 3:
                cout << "\n--- 3. SINH VIEN DU DIEU KIEN TOT NGHIEP ---\n";
                t.DS_SV_DuDK_TotNghiep();
                break;
            case 4:
                cout << "\n--- 4. SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP ---\n";
                t.DS_SV_Ko_DuDK_TotNghiep();
                break;
            case 5:
                cout << "\n--- 5. SINH VIEN DAI HOC CO DTB CAO NHAT ---\n";
                t.SV_DH_DTB_MAX();
                break;
            case 0:
                cout << "\nThoat chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "\nLua chon khong hop le. Vui long nhap lai (0-5)!\n";
                break;
        }
    } while (luachon != 0);

    return 0;
}