#ifndef quanlysv_h
#define quanlysv_h
#include"caodang.h"
#include"daihoc.h"
#include"SInhvientotnghiep.h"
class quanly
{
    private:
        sinhvien**SV;
        int slsv;
    public:
        ~quanly(){
            for(int i = 0;i<slsv;i++){
                delete SV[i];
            }
            delete[] SV;
            SV = nullptr;
        }
        quanly(int slsv = 0): slsv(slsv){}
        void nhap(){
            int luachon;
            cout<<"nhap so luong sv\n";
            cin>>slsv;
            SV = new sinhvien*[slsv];
            for(int i = 0;i<slsv;i++){
                cout<<"nhap (1: he cao dang - 2: he dai hoc)\n";
                cin>>luachon;
                while(luachon<1 || luachon>2){
                    cout<<"nhap lai chi 1 hoac 2\n";
                    cin>>luachon;
                }
                if(luachon==1){
                    SV[i]=new caodang;
                    SV[i]->Nhap();
                } else{
                    SV[i] = new sdaihoc;
                    SV[i]->Nhap();
                }
            }
        }
        void DS_SV_DuDK_TotNghiep(){
            int t = 0;
            cout<<"danh sach cac sinh vien tot nghiep\n";
            for(int i = 0;i<slsv;i++){
                if(SV[i]->TOTNGHIEP()){
                    t++;
                    SV[i]->Xuat();
                }
            }
            if(t==0) cout<<"khong co sinh vien nao tot nhiep\n";
        }
        void DS_SV_Ko_DuDK_TotNghiep(){
            int t = 0;
            cout<<"danh sach cac sinh vien khong tot nghiep\n";
            for(int i = 0;i<slsv;i++){
                if(!(SV[i]->TOTNGHIEP())){
                    SV[i]->Xuat();
                    t++;
                }
            }
            if(t==0) cout<<"khong co sinh vien nao khong tot nghiep\n";
        }
        void SV_DH_DTB_MAX(){
            int t = -1;
            for(int i =0;i<slsv;i++){
                if(SV[i]->PHANLOAI()=="dai hoc" && t == -1) t=i;
                else if(SV[i]->PHANLOAI()=="dai hoc" && SV[i]->Gettb()>SV[t]->Gettb()){
                    t=i;
                }
            }
            if(t==-1) cout<<"--khong co sinh vien dai hoc nao\n";
            else{
                cout<<"--sinh vien dai hoc co diem trung binh cao nha la: \n";
                SV[t]->Xuat();
            }
        }
        void xuat(){
            cout<<"--danh sach sv dai hoc va cao dang\n";
            for(int i = 0;i<slsv;i++){
                SV[i]->Xuat();
            }
        }
};
#endif