#ifndef _LapTrinhVien
#define _LapTrinhVien
#include"NhanVien.h"
class LapTrinhVien: public NhanVien
{
    private:
        int sogiolamthem;
    public:
        ~LapTrinhVien(){
            cout<<"Lap trinh vien da nghi \n";
        }
        LapTrinhVien(string mnv = " ", string ht = " ", int tuoi = 0, int sdt = 0, string email = " ", double luongcoban = 0, int sogiolamthem = 0): NhanVien(mnv, ht, tuoi, sdt, email, luongcoban), sogiolamthem(sogiolamthem){}
        double Luong(){
            return luongcoban + sogiolamthem*200000;
        }
        string PhanLoai(){
            return"LapTrinhVien";
        }
        int Getsogiolamthem(){ return sogiolamthem;}
        void Nhap(){
            NhanVien::Nhap();
            cout<<"so gio lam them la\n";
            cin>>sogiolamthem;
        }
        void Xuat(){
            NhanVien::Xuat();
            cout<<"\tluong lap trinh vien la "<<Luong()<<endl;
        }
};
#endif