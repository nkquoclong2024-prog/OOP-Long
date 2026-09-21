#include "QUANLYSOHONG.h"

void hienThiMenu() {
    cout << "\n================= QUAN LY SO HONG =================";
    cout << "\n1. Nhap danh sach so hong (Thu cong)";
    cout << "\n2. Xuat danh sach so hong hien tai";
    cout << "\n3. Xuat thua dat phai dong tien thue nhieu nhat";
    cout << "\n4. Xuat cac thua dat nong nghiep da het han su dung";
    cout << "\n---------------------------------------------------";
    cout << "\n5. Ghi noi dung van ban vao file";
    cout << "\n6. Doc noi dung van ban tu file";
    cout << "\n7. Ghi thong tin danh sach doi tuong vao file";
    cout << "\n8. Doc danh sach doi tuong tu file";
    cout << "\n0. Thoat chuong trinh";
    cout << "\n===================================================";
    cout << "\nNhap lua chon cua ban: ";
}

int main() {
    QUANLYSOHONG ql;
    int luaChon;
    string tenFile = "";

    do {
        hienThiMenu();
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "\n--- NHAP DANH SACH SO HONG ---\n";
                ql.Nhap();
                break;
            case 2:
                cout << "\n--- DANH SACH SO HONG ---\n";
                ql.Xuat();
                break;
            case 3:
                cout << "\n--- THUA DAT DONG THUE NHIEU NHAT ---\n";
                ql.XuatThuaDatDongNhieuThueNhat();
                break;
            case 4:
                cout << "\n--- THUA DAT NONG NGHIEP HET HAN SU DUNG ---\n";
                ql.XuatDatNongNghiepHetHanSuDung();
                break;
            case 5:
                if(tenFile == ""){
                    cout << "\nNhap ten file de ghi (vd: data.txt): ";
                    cin >> tenFile;
                }
                ql.WriteFile(tenFile);
                break;
            case 6:
                if(tenFile == ""){
                    cout << "\nNhap ten file de doc (vd: data.txt): ";
                    cin >> tenFile;
                }
                ql.ReadFile(tenFile);
                break;
            case 7:
                if(tenFile == ""){
                    cout << "\nNhap ten file de luu danh sach (vd: sohong.txt): ";
                    cin >> tenFile;
                }
                ql.WriteFilesohong(tenFile);
                break;
            case 8:
                if(tenFile == ""){
                    cout << "\nNhap ten file can doc danh sach (vd: sohong.txt): ";
                    cin >> tenFile;
                }
                ql.Readfilesohong(tenFile);
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