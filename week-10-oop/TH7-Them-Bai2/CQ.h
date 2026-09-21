#ifndef N_CQ
#define N_CQ
#include"Sinhvien.h"
class CQ: public sinhvien
{
    private:
        int DRL;
    public:
        ~CQ(){
            cout<<"sinh vien chinh quy da tot nghiep\n";
        }
        CQ(int DRL = 0): DRL(DRL){}
        int GetDRL(){
            return DRL;
        }
        string PhanLoai(){
            return"CQ";
        }
        double Hocbong(){
            if(DRL<85) return 0;
            if(dtb>=7.5 && dtb<8.5) return 1000000;
            if(dtb>=8.5 && dtb<9.5) return 1200000;
            if(dtb>=9.5) return 1500000;
            return 0;
        }
        void Nhap(){
            sinhvien::Nhap();
            cout<<"nhap diem ren luyen\n";
            cin>>DRL;
        }
        void Xuat(){
            sinhvien::Xuat();
            cout<<"\tdiem ren luyen: "<<DRL<<endl;
        }
};
#endif