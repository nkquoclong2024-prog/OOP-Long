#ifndef giaodich_n
#define giaodich_n
#include<iostream>
#include<math.h>
using namespace std;
class GIAODICH
{
    protected:
        string ma;
        int nd, td, yd;
        double dt, dg;
    public:
        GIAODICH(int nd = 0, int td = 0, int yd = 0, string ma = " ", double dt = 0, double dg = 0): nd(nd), td(td), yd(yd), ma(ma), dt(dt), dg(dg){};
        virtual ~GIAODICH() {}
        int Getday(){ return nd;};
        int Getmonth(){ return td;};
        int Getyear(){ return yd;};
        virtual void nhap(){
            cout<<"nhap ma\n";
            cin.ignore();
            getline(cin, ma);
            cout<<"ngay/thang/nam giao dich, dien tich va don gia\n";
            cin>>nd>>td>>yd>>dt>>dg;
        }
        virtual void xuat(){
            cout<<"ma dat la: "<<ma<<"\t ngay giao dich la: "<<nd<<"/"<<td<<"/"<<yd<<"\tdien tich dat: "<<dt<<"\tdon gia dat la: "<<dg;
        }
        virtual double GIA() = 0;
        virtual string TENBATDONGSAN() = 0;
};
#endif