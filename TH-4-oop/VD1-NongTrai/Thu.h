#ifndef _thu
#define _thu
#include<iostream>
#include<string>
using namespace std;
class Thu{
    protected:
        string ten;
        int maso;
    public:
        ~Thu(){
            cout<<"da ban 1 con thu\n";
        }
        Thu(string ten = " ", int maso = 0): ten(ten), maso(maso){
            cout<<"da mua 1 con thu\n";
        }
        string GetTen(){
            return ten;
        }
        int GetMaSo(){
            return maso;
        }
        void SetTen(string tam){
            ten = tam;
        }
        void SetMaSo(int tam){
            maso=tam;
        }
        virtual string Keu()=0;
        virtual string GetLoai()=0;
        virtual void Nhap(){
            cin.ignore();
            cout<<"nhap ten dong vat\n";
            getline(cin, ten);
            cout<<"nhap ma so\n";
            cin>>maso;
        }

        virtual void Xuat(){
            cout<<"ten: "<<ten<<"\tLoai: "<<GetLoai()<<"\tKeu: "<<Keu();
        }
};
#endif