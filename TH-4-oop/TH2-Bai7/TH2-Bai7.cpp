#include"ThuVien.h"
int main(){
    ThuVien nt;
    nt.Nhap();
    nt.Xuat();
    string k;
    cout<<"Nhap nha xuat ban can tim\n";
    cin.ignore();
    getline(cin,k);
    nt.XuatSachCuaNhaXuatBan(k);
    return 0;
}