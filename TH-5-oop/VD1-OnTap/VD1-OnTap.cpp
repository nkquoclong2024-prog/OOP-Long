#include "CongVien.h" 
void hienThiMenu() {
    cout << "\n================= MENU QUAN LY CONG VIEN =================";
    cout << "\n1. Nhap danh sach ve vao mang";
    cout << "\n2. Xuat danh sach ve hien tai ra man hinh";
    cout << "\n3. Tinh tong tien ve cong vien thu duoc";
    cout << "\n4. Thong ke so luong ve tung phan";
    cout << "\n----------------------------------------------------------";
    cout << "\n5. Ghi noi dung vao file (Phuong thuc ghi file)";
    cout << "\n6. Doc noi dung tu file ra man hinh (Phuong thuc doc file)";
    cout << "\n7. Ghi thong tin danh sach ve vao file (Ghi file DS doi tuong)";
    cout << "\n8. Doc file va tao danh sach doi tuong (Doc file ra DS doi tuong)";
    cout << "\n0. Thoat chuong trinh";
    cout << "\n==========================================================";
    cout << "\nNhap lua chon cua ban: ";
}

int main() {
    CongVien cv;
    int luaChon;
    string tenFile = "";

    do {
        hienThiMenu();
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                cout << "\n--- NHAP DANH SACH VE ---\n";
                cv.Nhap();
                break;
            case 2:
                cout << "\n--- DANH SACH VE HIEN TAI ---\n";
                cv.Xuat();
                break;
            case 3:
                cout << "\n-> Tong tien ve thu duoc: " << cv.TongTienVe() << " VND\n";
                break;
            case 4:
                cout << "\n-> So luong ve tung phan da ban: " << cv.SoVeTungPhan() << " ve\n";
                break;
            case 5:
                if(tenFile==""){
                    cout << "\nNhap ten file de doc ";
                    cin >> tenFile;
                }
                cv.Writefile(tenFile);
                break;
            case 6:
                if(tenFile==""){
                    cout << "\nNhap ten file de doc ";
                    cin >> tenFile;
                }
                cv.Readfile(tenFile);
                break;
            case 7:
                if(tenFile==""){
                    cout << "\nNhap ten file de doc ";
                    cin >> tenFile;
                }
                cv.WritefileVe(tenFile);
                break;
            case 8:
                if(tenFile==""){
                    cout << "\nNhap ten file de doc ";
                    cin >> tenFile;
                }
                cv.ReadfileVe(tenFile); 
                break;
            case 0:
                cout << "\nDang thoat chuong trinh\n";
                break;
            default:
                cout << "\nLua chon khong hop le! Vui long nhap lai.\n";
                break;
        }
    } while (luaChon != 0);
    return 0;
}