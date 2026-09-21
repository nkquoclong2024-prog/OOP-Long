#ifndef _NGAY
#define _NGAY
#include<iostream>
#include<String>
using namespace std;
class NGAY
{
    private:
        int d,m,y;
    public:
        NGAY(int d = 0, int m = 0, int y = 0): d(d), m(m), y(y){}
        int Getd(){ return d;}
        int Getm(){ return m;}
        int Gety(){ return y;}
        void Nhap(){
            do{
                cout<<"Nhap ngay - thang  - nam\n";
                cin>>d>>m>>y;
            } while(!KiemTraHopLe());
        }
        void Xuat(){
            cout<<"\tngay cung cap: "<<d<<" | "<<m<<" | "<<y;
        }
        bool KiemTraHopLe(){
            int t[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            if((y%4==0 && y%100!=0) || (y%400==0)) t[2]++;
            return m>=1 && m<=12 && d>=1 && d<=t[m];
        }
};
#endif