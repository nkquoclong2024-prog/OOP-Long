#ifndef _ToanPhan
#define _ToanPhan
#include"Ve.h"
class ToanPhan: public VE
{
    public:
        ~ToanPhan(){
            cout<<"Da huy ve toan phan\n";
        }
        ToanPhan(string mv = " ", string ht = " ", int ns = 0, int st = 0): VE(mv, ht, ns, st){}
        string PhanLoai(){
            return"ToanPhan";
        }
        double GiaTien(){
            return 200000;
        }
        void Nhap(){
            VE::Nhap();
        }
        void Xuat(){
            VE::Xuat();
            cout<<"\tgia tien la: "<<GiaTien()<<endl;
        }
};
#endif