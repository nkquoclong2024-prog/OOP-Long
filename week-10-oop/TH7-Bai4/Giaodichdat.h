#ifndef dat_n
#define dat_n
#include"Giaodich.h"
using namespace std;
class GIAODICHDAT: public GIAODICH
{
    private:
        char loai;
    public:
        ~GIAODICHDAT(){
            cout<<"da ban dat\n";
        }
        GIAODICHDAT(char loai = ' '): loai(loai){}
        void nhap() override {
            GIAODICH::nhap();
            cout<<"chon loai dat (A, B, C)\n";
            cin>>loai;
            while(loai!='A' && loai!='B' && loai!='C'){
                cout<<"chi co loai A, B, C\n";
                cin>>loai;
            }
        }
        double GIA() override {
            if(loai=='B' || loai=='C') return dt*dg;
            else if(loai=='A') return dt*dg*1.5;
            return -1;
        }
        void xuat() override {
            GIAODICH::xuat();
            cout<<"\t loai dat la: "<<loai<<"\t gia dat la: "<<GIA()<<endl;
        }
        string TENBATDONGSAN(){
            return"DAT";
        }
};
#endif