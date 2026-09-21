#ifndef _giaodichtrungcu
#define _giaodichtrungcu
#include"Giaodich.h"
class TRUNGCU: public GIAODICH
{
    private:
        double vitri;
    public:
        ~TRUNGCU(){
            cout<<"da ban trung cu\n";
        }
        TRUNGCU(double v = 0): vitri(v){}
        void Nhap(){
            GIAODICH::nhap();
            cout<<"Nhap vi tri trung cu ";
            cin>>vitri;
        }
        double GIA(){
            if(vitri==1) return dt*dg*2;
            else if(vitri>=15) return dt*dg*1.2;
            return dt*dg;
        }
        void Xuat(){
            GIAODICH::xuat();
            cout<<"\tvi tri can trung cu la: "<<vitri<<"\tgia cua can trung cu la: "<<GIA()<<endl;
        }
        string TENBATDONGSAN(){
            return "TRUNG CU";
        }
};
#endif