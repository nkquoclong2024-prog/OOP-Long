#include"QuanLy.h"

int main() {
    QUANLY ql;
    int luaChon;

    do {
        cout << "\n================= MENU QUAN LY GIAO DICH =================";
        cout << "\n1. Nhap danh sach cac giao dich";
        cout << "\n2. Xuat danh sach cac giao dich";
        cout << "\n3. Tinh tong so luong cho tung loai giao dich";
        cout << "\n4. Tinh trung binh thanh tien cua giao dich Chung cu";
        cout << "\n5. Cho biet giao dich Nha pho co tri gia cao nhat";
        cout << "\n6. Xuat danh sach cac giao dich cua thang 12 nam 2024";
        cout << "\n0. Thoat chuong trinh";
        cout << "\n==========================================================";
        cout << "\nNhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "\n--- 1. NHAP DANH SACH GIAO DICH ---\n";
                ql.Nhap();
                break;
            case 2:
                cout << "\n--- 2. XUAT DANH SACH GIAO DICH ---\n";
                ql.Xuat();
                break;
            case 3:
                cout << "\n--- 3. TONG SO LUONG TUNG LOAI ---\n";
                ql.Tong_SL_Tung_Loai();
                break;
            case 4:
                cout << "\n--- 4. TRUNG BINH THANH TIEN CHUNG CU ---\n";
                ql.TB_ThanhTien_GD_TC();
                break;
            case 5:
                cout << "\n--- 5. GIAO DICH NHA PHO GIA CAO NHAT ---\n";
                ql.GiaoDich_TP_CoGiaTriCaoNhat();
                break;
            case 6:
                cout << "\n--- 6. GIAO DICH THANG 12/2024 ---\n";
                ql.DS_GiaoDich_Cua_T12_N2024();
                break;
            case 0:
                cout << "\nThoat chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "\nLua chon khong hop le. Vui long nhap lai (0-6)!\n";
        }
    } while (luaChon != 0);

    return 0;
}