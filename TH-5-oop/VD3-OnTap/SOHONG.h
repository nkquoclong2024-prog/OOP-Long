#ifndef _SOHONG
#define _SOHONG
#include"CONGDAN.h"
#include"NGAY.h"
#include<fstream>
class SOHONG
{
    protected:
        string soGiayCN, addsDat;
        CONGDAN chuDat;
        NGAY ngayCap;
        int soThuaDat, soToBanDo, donGiaThue;
        double dientich;
    public:
        virtual ~SOHONG(){}
        SOHONG(string soGiayCN = " ", string ht = " ", int namSinh = 0, string cccd = " ", string adds = " ", int soThuaDat = 0, int soToBanDo = 0, string addsDat = " ", double dt = 0, int d = 0, int m = 0, int y = 0, int donGiaThue = 0): soGiayCN(soGiayCN), chuDat(ht, namSinh, cccd, adds), soThuaDat(soThuaDat), soToBanDo(soToBanDo), addsDat(addsDat), dientich(dt), ngayCap(d,m,y), donGiaThue(donGiaThue){}
        string GetsoGiayCN(){ return soGiayCN;}
        string Getht(){ return chuDat.Getht();}
        int GetnamSinh(){ return chuDat.GetnamSinh();}
        string Getcccd(){ return chuDat.Getcccd();}
        string Getadds(){ return chuDat.Getadds();}
        int GetsoThuaDat(){ return soThuaDat;}
        int GetsoToBanDo(){ return soToBanDo;}
        string GetaddsDat(){ return addsDat;}
        double Getdientich(){ return dientich;}
        int Getd(){ return ngayCap.Getd();}
        int Getm(){ return ngayCap.Getm();}
        int Gety(){ return ngayCap.Gety();}
        int GetdonGiaThue(){ return donGiaThue;}
        virtual void Nhap(){
            cout<<"nhap so giay chung nhan\n";
            cin.ignore();
            getline(cin, soGiayCN);
            chuDat.Nhap();
            cout<<"nhap so thua dat va so to ban do\n";
            cin>>soThuaDat>>soToBanDo;
            cin.ignore();
            cout<<"nhap dia chi cua thua dat\n";
            getline(cin, addsDat);
            cout<<"nhap dien tich cua dat\n";
            cin>>dientich;
            ngayCap.Nhap();
            cout<<"nhap don gia thue\n";
            cin>>donGiaThue;
        }
        virtual void Xuat(){
            cout<<"so giau chung nhan "<<soGiayCN;
            chuDat.Xuat();
            cout<<"\tso thua dat "<<soThuaDat<<"\tso to ban do "<<soToBanDo<<"\tdia chi cua dat "<<addsDat<<"\tdien tich cua dat "<<dientich;
            ngayCap.Xuat();
            cout<<"\tdon gia thue "<<donGiaThue;
        }
        virtual string GetLoai()=0;
        double TienThue(){
            return dientich*donGiaThue;
        }
};
#endif