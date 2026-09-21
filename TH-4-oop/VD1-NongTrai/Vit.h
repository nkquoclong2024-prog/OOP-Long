#ifndef _vit
#define _vit
#include"Thu.h"
using namespace std;
class Vit: public Thu{
    private:
        double nuoc;
    public:
        ~Vit(){};
        Vit(string ten = " ", int maso = 0, double nuoc = 0): Thu(ten, maso), nuoc(nuoc){};
        double GetNuoc(){
            return nuoc;
        }
        void SetNuoc(double nuoc){
             this->nuoc = nuoc;
        }
        double chiphinuoiduong(){
            return nuoc*1500+100000;
        }
        void Nhap(){
            Thu::Nhap();
            cout<<"nhap so m^3 nuoc\n";
            cin>>nuoc;
        }
        void Xuat(){
            Thu::Xuat();
            cout<<"\tnuoc(m^3): "<< nuoc<<"\tso tien nuoi: "<<chiphinuoiduong() << endl;
        }
        string Keu(){
            return "quac quac...";
        }
        string GetLoai(){
            return "Vit";
        }
};
#endif