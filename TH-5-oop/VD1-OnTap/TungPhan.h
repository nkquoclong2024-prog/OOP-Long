#ifndef _TungPhan
#define _TungPhan
#include"Ve.h"
class TungPhan: public VE
{
    public:
        ~TungPhan(){
            cout<<"Da huy ve tung phan\n";
        }
        TungPhan(string mv = " ", string ht = " ", int ns = 0, int st = 0): VE(mv, ht, ns, st){}
        string PhanLoai(){
            return"TungPhan";
        }
        double GiaTien(){
            return 70000 + 20000*st;
        }
        void Nhap(){
            VE::Nhap();
        }
        void Xuat(){
            VE::Xuat();
            cout<<"\tso nguoi la: "<<st<<"\tgia tien la: "<<GiaTien()<<endl;
        }
};
#endif