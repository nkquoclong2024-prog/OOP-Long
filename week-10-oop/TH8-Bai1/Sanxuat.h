#ifndef N_sanxuat
#define N_sanxuat
#include"Nhanvien.h"
class Sanxuat: public nhanvien
{
    private:
        double lcb;
        int ssp;
    public:
        ~Sanxuat(){
            cout<<"nhan vien san xuat da nghi viec\n";
        }
        Sanxuat(double lcb = 0, int ssp = 0): lcb(lcb), ssp(ssp){}
        string loainhanvien(){
            return"san xuat";
        }
        double luong(){
            return lcb+ssp*5000;
        }
        void Nhap() override {
            nhanvien::Nhap();
            cout<<"nhap luong can ban va so san pham\n";
            cin>>lcb>>ssp;
        }
        void Xuat() override {
            nhanvien::Xuat();
            cout<<"\t| luong can ban: "<<lcb<<"\t| so san pham: "<<ssp<<"\t| luong: "<<luong()<<endl;
        }
};
#endif