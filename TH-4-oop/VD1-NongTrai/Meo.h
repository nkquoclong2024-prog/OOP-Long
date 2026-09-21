#ifndef _meo
#define _meo
#include"Thu.h"
using namespace std;
class Meo: public Thu{
    private:
        double ca;
    public:
        ~Meo(){};
        Meo(string ten = " ", int maso = 0, double ca = 0): Thu(ten, maso), ca(ca){};
        double GetCa(){
            return ca;
        }
        void SetCa(double ca){
             this->ca = ca;
        }
        double chiphinuoiduong(){
            return ca*16000+100000;
        }
        void Nhap(){
            Thu::Nhap();
            cout<<"nhap so kg ca\n";
            cin>>ca;
        }
        void Xuat(){
            Thu::Xuat();
            cout<<"\tca(kg): "<< ca<<"\tso tien nuoi: "<<chiphinuoiduong() << endl;
        }
        string Keu(){
            return "meo meo...";
        }
        string GetLoai(){
            return "Meo";
        }
};
#endif