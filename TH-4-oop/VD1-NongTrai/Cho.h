#ifndef _cho
#define _cho
#include"Thu.h"
using namespace std;
class Cho: public Thu{
    private:
        double xuong;
    public:
        ~Cho(){};
        Cho(string ten = " ", int maso = 0, double xuong = 0): Thu(ten, maso), xuong(xuong){};
        double GetXuong(){
            return xuong;
        }
        void SetXuong(double xuong){
             this->xuong = xuong;
        }
        double chiphinuoiduong(){
            return xuong*50000+100000;
        }
        void Nhap(){
            Thu::Nhap();
            cout<<"nhap so kg xuong\n";
            cin>>xuong;
        }
        void Xuat(){
            Thu::Xuat();
            cout<<"\tXuong(kg): "<< xuong<<"\tso tien nuoi: "<<chiphinuoiduong() << endl;
        }
        string Keu(){
            return "gau gau...";
        }
        string GetLoai(){
            return "Cho";
        }
};
#endif