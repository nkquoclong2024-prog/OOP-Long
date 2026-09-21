#ifndef _DATNONGNGHIEP
#define _DATNONGNGHIEP
#include"SOHONG.h"
class DATNONGNGHIEP: public SOHONG
{
    private:   
        int thoihan;
    public:
        ~DATNONGNGHIEP(){
            cout<<"DA BAN DAT NONG NGHIEP\n";
        }
        DATNONGNGHIEP(string soGiayCN = " ", string ht = " ", int namSinh = 0, string cccd = " ", string adds = " ", int soThuaDat = 0, int soToBanDo = 0, string addsDat = " ", double dt = 0, int d = 0, int m = 0, int y = 0, int donGiaThue = 0, int thoihan= 0):SOHONG(soGiayCN, ht, namSinh, cccd, adds, soThuaDat, soToBanDo, addsDat, dt, d , m, y, donGiaThue), thoihan(thoihan){}
        void Nhap(){
            SOHONG::Nhap();
            cout<<"nhap thoi han\n";
            cin>>thoihan;
        }
        int Getthoihan(){ return thoihan;}
        void Xuat(){
            SOHONG::Xuat();
            cout<<"\tthoi han la "<<thoihan<<endl;
        }
        string GetLoai(){
            return"DATNONGNGHIEP";
        }
};
#endif