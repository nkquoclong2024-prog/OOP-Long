#ifndef _KiemChungVien
#define _KiemChungVien
#include"NhanVien.h"
class KiemChungVien: public NhanVien
{
    private:
        int soloi;
    public:
        ~KiemChungVien(){
            cout<<"Kiem chung vien da nghi \n";
        }
        KiemChungVien(string mnv = " ", string ht = " ", int tuoi = 0, int sdt = 0, string email = " ", double luongcoban = 0, int soloi = 0): NhanVien(mnv, ht, tuoi, sdt, email, luongcoban), soloi(soloi){}
        double Luong(){
            return luongcoban + soloi*50000;
        }
        string PhanLoai(){
            return"KiemChungVien";
        }
        void Nhap(){
            NhanVien::Nhap();
            cout<<"so gio lam them la\n";
            cin>>soloi;
        }
        void Xuat(){
            NhanVien::Xuat();
            cout<<"\tluong kiem chung vien la "<<Luong()<<endl;
        }
};
#endif