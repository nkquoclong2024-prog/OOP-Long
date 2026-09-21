#include"TongLuongHat.h"
int main(){
    int chon;
    string tenfile = "";
    TongLuongHat a;
    do{
        cout<<"1: Nhap cac gia tri bang tay\n";
        cout<<"2: Xuat cac gia tri\n";
        cout<<"3: xuat hat dieu tri co kha nang giai phong thuoc lon nhat o gio thu 3\n";
        cout<<"4: xuat ra ma cac hat bi phan huy yeu cau\n";
        cout<<"5: xuat ra file\n";
        cout<<"6: luu tu file\n";
        cout<<"0: huy\n";
        cin>>chon;
        if(chon==1){
            a.Nhap();
        } else if(chon==2){
            a.Xuat();
        } else if(chon==3){
            a.HatCoNangXuatGiaiPhongThuocManhNhatGioThu3();
        } else if(chon==4){
            a.RaSoat();
        } else if(chon==5){
            if(tenfile==""){
                cout<<"nhap ten file\n";
                cin.ignore();
                getline(cin, tenfile);
            }
            a.LuHoSo(tenfile);
        } else if(chon==6){
            if(tenfile==""){
                cout<<"nhap ten file\n";
                cin.ignore();
                getline(cin, tenfile);
            }
            a.Docfile(tenfile);
        }
    } while(chon!=0);
    cout<<"da thoat\n";
    return 0;
}