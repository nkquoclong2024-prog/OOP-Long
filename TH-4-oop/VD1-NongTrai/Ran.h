#ifndef _ran
#define _ran
#include"Thu.h"
using namespace std;
class Ran: public Thu{
    private:
        double trung;
    public:
        ~Ran(){};
        Ran(string ten = " ", int maso = 0, double trung = 0): Thu(ten, maso), trung(trung){};
        double GetTrung(){
            return trung;
        }
        void SetTrung(double trung){
             this->trung = trung;
        }
        double chiphinuoiduong(){
            return trung*11000+100000;
        }
        void Nhap(){
            Thu::Nhap();
            cout<<"nhap so qua trung\n";
            cin>>trung;
        }
        void Xuat(){
            Thu::Xuat();
            cout<<"\ttrung(qua): "<< trung<<"\tso tien nuoi: "<<chiphinuoiduong() << endl;
        }
        string Keu(){
            return "xi xi...";
        }
        string GetLoai(){
            return "Ran";
        }
};
#endif