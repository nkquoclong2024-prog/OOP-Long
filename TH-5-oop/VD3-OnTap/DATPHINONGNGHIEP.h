#ifndef _DATPHINONGNGHIEP
#define _DATPHINONGNGHIEP
#include"SOHONG.h"
class DATPHINONGNGHIEP: public SOHONG
{
    public:
        ~DATPHINONGNGHIEP(){
            cout<<"DA BAN DAT NONG NGHIEP\n";
        }
        DATPHINONGNGHIEP(string soGiayCN = " ", string ht = " ", int namSinh = 0, string cccd = " ", string adds = " ", int soThuaDat = 0, int soToBanDo = 0, string addsDat = " ", double dt = 0, int d = 0, int m = 0, int y = 0, int donGiaThue = 0):SOHONG(soGiayCN, ht, namSinh, cccd, adds, soThuaDat, soToBanDo, addsDat, dt, d , m, y, donGiaThue){}
        void Nhap(){
            SOHONG::Nhap();
        }
        void Xuat(){
            SOHONG::Xuat();
            cout<<endl;
        }
        string GetLoai(){
            return"DATPHINONGNGHIEP";
        }
};
#endif