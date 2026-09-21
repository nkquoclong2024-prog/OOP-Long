#ifndef _ThamKhao
#define _ThamKhao
#include"Sach.h"
class ThamKhao: public Sach{
    private:
        double thue;
    public:
        ~ThamKhao(){};
        ThamKhao(double x = 0): Sach(), thue(x){}
        double GetThue(){
            return thue;
        }
        void SetThue(double thue){
            this->thue=thue;
        }
        double ThanhTien(){
            return sl*dg+thue;
        }
        string LoaiSach(){
            return "ThamKhao";
        }
        void Nhap(){
            Sach::Nhap();
            cout<<"Nhap thue: ";
            cin>>thue;
        }
        void Xuat(){
            Sach::Xuat();
            cout<<"\tthue sach la: "<<thue<<"\ttien mua sach la: "<<ThanhTien()<<endl;
        }
};
#endif