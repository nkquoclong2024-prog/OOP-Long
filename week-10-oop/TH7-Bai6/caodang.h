#ifndef caodang_h
#define caodang_h
#include"SInhvientotnghiep.h"
class caodang: public sinhvien
{
    private:
        double diemthi;
    public:
        caodang(int diemthi = 0): diemthi(diemthi){}
        ~caodang() override{
            cout<<"tot nghiep cao dang\n";
        }
        void Nhap() override{
            sinhvien::Nhap();
            cout<<"nhap diem thi tot nghiep\n";
            cin>>diemthi;
        }
        void Xuat() override{
            sinhvien::Xuat();
            cout<<"\t|\t"<<diemthi<<endl;
        }
        string PHANLOAI(){
            return "cao dang";
        }
        bool TOTNGHIEP(){
            return (tc>=110 && tb>=5 && diemthi>=5);    
        }
}; 
#endif