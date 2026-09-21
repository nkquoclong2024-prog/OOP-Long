#ifndef N_nhanvien
#define N_nhanvien
#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
class nhanvien
{
    protected:
        string ht;
        int d, m, y;
    public:
        virtual ~nhanvien(){}
        nhanvien(string ht = " ", int d = 0, int m = 0, int y = 0): ht(ht), d(d), m(m), y(y){}
        virtual double luong() = 0;
        virtual string loainhanvien() = 0;
        int Getd(){
            return d;
        }
        int Getm(){
            return m;
        }
        int Gety(){
            return y;
        }
        virtual void Nhap(){
            cout<<"nhap ho ten\n";
            cin.ignore();
            getline(cin, ht);
            cout<<"nhap ngay sinh\n";
            cin>>d>>m>>y;
        } 
        virtual void Xuat(){
            cout<<"ten nhan vien: "<<ht<<"\t| ngay "<<d<<"\t| thang "<<m<<"\t| nam "<<y;
        }
};
#endif