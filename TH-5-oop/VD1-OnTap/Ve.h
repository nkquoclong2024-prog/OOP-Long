#ifndef _ve
#define _ve
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
class VE
{
    protected:
        string mv, ht;
        int ns, st;
    public:
        virtual ~VE(){}
        VE(string mv = " ", string ht = " ", int ns = 0, int st = 0): mv(mv), ht(ht), ns(ns), st(st){}
        virtual string PhanLoai() = 0;
        virtual double GiaTien() = 0;
        string Getmv(){
            return mv;
        }
        string Getht(){
            return ht;
        }
        int Getns(){
            return ns;
        }
        int Getst(){
            return st;
        }
        virtual void Nhap(){
            cin.ignore();
            cout<<"Nhap ma ve: \n";
            getline(cin, mv);
            cout<<"Nhap ho ten: \n";
            getline(cin, ht);
            cout<<"Nhap nam sinh \n";
            cin>>ns;
            cout<<"Nhap so tro choi \n";
            cin>>st;
            if(st<0) st = 0;
            else if(st>30) st = 30;
        }
        virtual void Xuat(){
            cout<<"ma ve la: "<<mv<<"\tho ten la: "<<ht<<"\tnam sinh la: "<<ns;
        }
};
#endif