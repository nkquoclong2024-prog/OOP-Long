#ifndef _NhanVien
#define _NhanVien
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class NhanVien
{
    protected:
        string mnv, ht, email;
        int tuoi, sdt;
        double luongcoban;
    public:
        virtual ~NhanVien(){}
        NhanVien(string mnv = " ", string ht = " ", int tuoi = 0, int sdt = 0, string email = " ", double luongcoban = 0): mnv(mnv), ht(ht), tuoi(tuoi), sdt(sdt), email(email), luongcoban(luongcoban){}
        virtual double Luong() = 0;
        virtual string PhanLoai() = 0;
        string Getmnv(){ return mnv;}
        string Getht(){ return ht;}
        string Getemail(){ return email;}
        int Gettuoi(){ return tuoi;}
        int Getsdt(){ return sdt;}
        double Getluongcoban(){ return luongcoban;}
        virtual void Nhap(){
            cout<<"Nhap ma nhan vien\n";
            cin.ignore();
            getline(cin, mnv);
            cout<<"Nhap ho ten\n";
            getline(cin, ht);
            cout<<"Nhap so tuoi\n";
            cin>>tuoi;
            cout<<"Nhap so dien thoai\n";
            cin>>sdt;
            cout<<"Nhap email \n";
            cin.ignore();
            getline(cin, email);
            cout<<"Nhap luong co ban\n";
            cin>>luongcoban;
        } 
        virtual void Xuat(){
            cout<<"Ma nhan vien "<<mnv<<"\t ho ten "<<ht<<"\ttuoi "<<tuoi<<"\tso dien thoai "<<sdt<<"\temail "<<email<<"\tluong co ban "<<luongcoban;
        }
};
#endif