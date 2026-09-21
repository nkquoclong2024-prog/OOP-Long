#include "QuanLi.h"
int main() {
    QuanLi t;
    int luaChon;

    do {
        cout << "\n===================== MENU QUAN LY SINH VIEN =====================";
        cout << "\n1.  Nhap danh sach sinh vien";
        cout << "\n2.  Xuat danh sach sinh vien";
        cout << "\n3.  Liet ke cac SVCQ co DRL la 100";
        cout << "\n4.  Dem so luong SVLT khong nghi buoi nao";
        cout << "\n5.  Tinh tong hoc bong cap cho cac SV";
        cout << "\n6.  Tinh DTB cua cac SVCQ duoc cap hoc bong";
        cout << "\n7.  Kiem tra truong co SVLT co DTB >= 9 (va khong nghi buoi nao)";
        cout << "\n8.  Tim cac SVCQ co DTB cao nhat";
        cout << "\n9.  Sap xep danh sach SV tang dan theo ma so";
        cout << "\n10. Them 1 SV moi";
        cout << "\n11. Xoa 1 SV theo ma so";
        cout << "\n12. Tim kiem SV";
        cout << "\n0.  Thoat chuong trinh";
        cout << "\n==================================================================";
        cout << "\nNhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "\n--- 1. NHAP DANH SACH SINH VIEN ---\n";
                t.Nhap();
                break;
            case 2:
                cout << "\n--- 2. XUAT DANH SACH SINH VIEN ---\n";
                t.Xuat();
                break;
            case 3:
                cout << "\n--- 3. LIET KE SVCQ CO DRL = 100 ---\n";
                t.LietKeSVCQ_DRL100();
                break;
            case 4:
                cout << "\n--- 4. DEM SO LUONG SVLT KHONG NGHI ---\n";
                t.DemSVLT_KhongNghi();
                break;
            case 5:
                cout << "\n--- 5. TONG HOC BONG ---\n";
                t.Tong_HB();
                break;
            case 6:
                cout << "\n--- 6. DIEM TRUNG BINH SVCQ CO HOC BONG ---\n";
                t.DTB_SVCQ_CoHB();
                break;
            case 7:
                cout << "\n--- 7. KIEM TRA SVLT XUAT SAC ---\n";
                if (t.SVLT_DTB_LonHon9()) {
                    cout << "-> Truong CO sinh vien lien thong dat yeu cau (DTB >= 9).\n";
                } else {
                    cout << "-> Truong KHONG CO sinh vien lien thong dat yeu cau.\n";
                }
                break;
            case 8:
                cout << "\n--- 8. SVCQ CO DTB CAO NHAT ---\n";
                t.SVCQ_DTB_CaoNhat();
                break;
            case 9:
                cout << "\n--- 9. SAP XEP TANG DAN THEO MA SO ---\n";
                t.SapXep_Tang_Dan_Theo_MS();
                cout << "-> Da sap xep thanh cong! (Chon chuc nang so 2 de xem lai danh sach)\n";
                break;
            case 10:
                cout << "\n--- 10. THEM SINH VIEN MOI ---\n";
                t.Them_1_SV_Moi();
                break;
            case 11:
                cout << "\n--- 11. XOA SINH VIEN ---\n";
                t.Xoa_SV();
                break;
            case 12:
                cout << "\n--- 12. TIM KIEM SINH VIEN ---\n";
                t.TimKiemSV();
                break;
            case 0:
                cout << "\nThoat chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "\nLua chon khong hop le. Vui long nhap lai tu 0 den 12!\n";
        }
    } while (luaChon != 0);

    return 0;
}