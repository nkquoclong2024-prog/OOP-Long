#ifndef _sach
#define _sach
#include<iostream>
#include<string>
using namespace std;
class Sach{
    protected:
        int ms, nn, sl;
        double dg;
        string xb;
    public:
        ~Sach(){
            cout<<"Da ban\n";
        }
        Sach(int ms = 0, int nn = 0, int sl = 0, double dg = 0, string xb = " "): ms(ms), nn(nn), sl(sl), dg(dg), xb(xb){}
        int GetMaS(){
            return ms;
        }
        int GetNgayNhap(){
            return nn;
        }
        int GetSoLuong(){
            return sl;
        }
        double GetDonGia(){
            return dg;
        }
        string XuatBan(){
            return xb;
        }
        void SetMaS(int ms){
            this->ms=ms;
        }
        void SetNgayNhap(int nn){
            this->nn=nn;
        }
        void SetSoLuong(int sl){
            this->sl=sl;
        }
        void SetDonGia(double dg){
            this->dg=dg;
        }
        void SetXuatBan(string xb){
            this->xb=xb;
        }
        virtual void Nhap(){
            cout<<"Nhap ma so, ngay nhap, so luong, don gia la: ";
            cin>>ms>>nn>>sl>>dg;
            cout<<"Nhap ten nha xuat ban: ";
            cin.ignore();
            getline(cin, xb);
        }
        virtual void Xuat(){
            cout<<"ma so: "<<ms<<"\tngay nhap: "<<nn<<"\tso luong: "<<sl<<"\tdon gia: "<<dg<<"\tnha san xuat: "<<xb;
        }
        virtual double ThanhTien()=0;
        virtual string LoaiSach()=0;
};
#endif