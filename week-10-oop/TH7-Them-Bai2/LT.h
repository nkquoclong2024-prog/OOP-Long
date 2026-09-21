#ifndef N_LT
#define N_LT
#include"Sinhvien.h"
class LT: public sinhvien
{
    private:
        int SBV;
    public:
        ~LT(){
            cout<<"sinh vien lien thong da tot nghiep\n";
        }
        LT(int SBV = 0): SBV(SBV){}
        string PhanLoai(){
            return"LT";
        }
        int GetSBV(){
            return SBV;
        }
        double Hocbong(){
            if(SBV>3) return 0;
            if(dtb>=7&& dtb<8) return 1000000;
            if(dtb>=8 && dtb<9) return 1200000;
            if(dtb>=9) return 1500000;
            return 0;
        }
        void Nhap(){
            sinhvien::Nhap();
            cout<<"nhap so buoi vang\n";
            cin>>SBV;
        }
        void Xuat(){
            sinhvien::Xuat();
            cout<<"\tso buoi vang: "<<SBV<<endl;
        }
};
#endif