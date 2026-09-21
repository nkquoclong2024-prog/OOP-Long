
#include "CongTy.h"
void hienThiMenu() {
    cout << "\n================= MENU QUAN LY CONG TY =================";
    cout << "\n1. Nhap danh sach nhan vien (Thu cong)";
    cout << "\n2. Xuat danh sach nhan vien hien tai";
    cout << "\n3. Liet ke nhan vien co luong thap hon trung binh";
    cout << "\n4. Liet ke nhan vien co muc luong toi thieu (tu nhap)";
    cout << "\n--------------------------------------------------------";
    cout << "\n5. Ghi noi dung van ban vao file";
    cout << "\n6. Doc noi dung van ban tu file";
    cout << "\n7. Ghi thong tin danh sach nhan vien vao file";
    cout << "\n8. Doc danh sach nhan vien tu file";
    cout << "\n0. Thoat chuong trinh";
    cout << "\n========================================================";
    cout << "\nNhap lua chon cua ban: ";
}

int main() {
    CongTy ct;
    int luaChon;
    string tenFile = "";
    double mucLuong;

    do {
        hienThiMenu();
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "\n--- NHAP DANH SACH NHAN VIEN ---\n";
                ct.Nhap();
                break;
            case 2:
                cout << "\n--- DANH SACH NHAN VIEN ---\n";
                ct.Xuat();
                break;
            case 3:
                cout << "\n--- NHAN VIEN CO LUONG DUOI TRUNG BINH ---\n";
                ct.DSNhanVienLuongThapHonTB();
                break;
            case 4:
                cout << "\nNhap muc luong toi thieu can tim: ";
                cin >> mucLuong;
                cout << "\n--- NHAN VIEN CO LUONG >= " << mucLuong << " ---\n";
                ct.DSNhanVienCoMucLuongToiThieuDoNhapLa(mucLuong);
                break;
            case 5:
                if(tenFile==""){
                    cout << "\nNhap ten file de doc ";
                    cin >> tenFile;
                }
                ct.writefile(tenFile);
                break;
            case 6:
                if(tenFile==""){
                    cout << "\nNhap ten file de doc ";
                    cin >> tenFile;
                }
                ct.readfile(tenFile);
                break;
            case 7:
                if(tenFile==""){
                    cout << "\nNhap ten file de doc ";
                    cin >> tenFile;
                }
                ct.writefileds(tenFile);
                break;
            case 8:
                if(tenFile==""){
                    cout << "\nNhap ten file de doc ";
                    cin >> tenFile;
                }
                ct.readfileds(tenFile);
                break;
            case 0:
                cout << "\nDang thoat chuong trinh\n";
                break;
            default:
                cout << "\nLua chon khong hop le! Vui long chon lai.\n";
                break;
        }
    } while (luaChon != 0);

    return 0;
}
