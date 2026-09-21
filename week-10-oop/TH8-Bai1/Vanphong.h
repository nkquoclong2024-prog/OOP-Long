#ifndef N_vanphong
#define N_vanphong
#include"Nhanvien.h"
class vanphong: public nhanvien
{
    private:
        int sglv;
    public:
        ~vanphong(){
            cout<<"nhan vien van phong da nghi viec\n";
        }
        vanphong(int sglv = 0): sglv(sglv){}
        string loainhanvien(){
            return"van phong";
        }
        double luong(){
            return sglv*100000;
        }
        void Nhap() override {
            nhanvien::Nhap();
            cout<<"so ngay lam viec\n";
            cin>>sglv;
        }
        void Xuat() override {
            nhanvien::Xuat();
            cout<<"\t| so ngay lam viec: "<<sglv<<"\t| luong: "<<luong()<<endl;
        }
};
#endif