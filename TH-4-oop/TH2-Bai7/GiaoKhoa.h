#ifndef _GiaoKhoa
#define _GiaoKhoa
#include"Sach.h"
class GiaoKhoa: public Sach{
    private:
        bool TinhTrang;
    public:
        ~GiaoKhoa(){};
        GiaoKhoa(bool x = false): Sach(), TinhTrang(x){}
        bool GetTinhTrang(){
            return TinhTrang;
        }
        void SetTinhTrang(bool TinhTrang){
            this->TinhTrang=TinhTrang;
        }
        double ThanhTien(){
            if(TinhTrang) return sl*dg;
            return sl*dg*0.5;
        }
        string LoaiSach(){
            return "GiaoKhoa";
        }
        void Nhap(){
            Sach::Nhap();
            cout<<"Nhap TinhTrang(1:la moi - 0: la cu): ";
            cin>>TinhTrang;
        }
        void Xuat(){
            Sach::Xuat();
            cout<<"\tTinhTrang sach la: "<<(TinhTrang?"Moi":"Cu")<<"\ttien mua sach la: "<<ThanhTien()<<endl;
        }
};
#endif