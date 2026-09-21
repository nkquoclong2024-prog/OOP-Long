#ifndef N_quanli
#define N_quanli
#include"Nhanvien.h"
#include"Sanxuat.h"
#include"Vanphong.h"
class Quanli
{
    private:
        nhanvien**NV;
        int slnv;
    public:
        ~Quanli(){
            for(int i = 0;i<slnv;i++){
                delete NV[i];
            }
            delete[] NV;
            NV = nullptr;
        }
        Quanli(int slnv = 0): slnv(slnv){}
        void Nhap(){
            int loai;
            cout<<"nhap so luong nhan vien\n";
            cin>>slnv;
            NV = new nhanvien*[slnv];
            for(int i = 0;i<slnv;i++){
                cout<<"nhap cac loai nhan vien (1: san xuat - 2: van phong)\n";
                cin>>loai;
                while(loai<1 || loai>2){
                    cout<<"nhap lai chi 1 va 2\n";
                    cin>>loai;
                }
                if(loai==1){
                    NV[i] = new Sanxuat;
                    NV[i]->Nhap();
                } else{
                    NV[i] = new vanphong;
                    NV[i]->Nhap();
                }
            }
        }
        double Tong_Luong_CT_Tra_Cho_NV(){
            double tong = 0;
            for(int i = 0;i<slnv;i++){
                tong+=NV[i]->luong();
            }
            return tong;
        }
        void NVSX_Luong_min(){
            int t = -1;
            for(int i = 0;i<slnv;i++){
                 if(NV[i]->loainhanvien()=="san xuat"){
                    if(t==-1) t = i;
                    else if(NV[i]->luong()<NV[t]->luong()) t = i;
                }
            }
            if(t!=-1){
                cout<<"nhan vien san xuat co luong thap nhat la: \n";
                NV[t]->Xuat();
            } else cout<<"khong co nhan vien san xuat nao\n";
        }
        void NVVP_Tuoi_max(){
            int tvp = -1;
            for(int i = 0;i<slnv;i++){
                    if(NV[i]->loainhanvien()=="van phong"){
                    if(tvp == -1) tvp=i;
                    else{
                        if(NV[i]->Gety()<NV[tvp]->Gety()) tvp = i;
                        else if(NV[i]->Gety()==NV[tvp]->Gety()){
                            if(NV[i]->Getm()<NV[tvp]->Getm()) tvp = i;
                            else if(NV[i]->Getm()==NV[tvp]->Getm()){
                                if(NV[i]->Getd()<NV[tvp]->Getd()) tvp = i;
                            }
                        }
                    }
                }
            }
            if(tvp!=-1){
                cout<<"nhan vien van phong co tuoi cao nha la: \n";
                NV[tvp]->Xuat();
            } else cout<<"khong co nhan vien van phong nao\n";
        }
        void xuat(){
            double tong = 0;
            
            cout<<"danh sach cac nhan vien\n";
            for(int i = 0;i<slnv;i++){
                cout<<"nhan vien thu: "<<i+1<<endl;
                NV[i]->Xuat();
                tong +=NV[i]->luong();
            }
        }
};
#endif