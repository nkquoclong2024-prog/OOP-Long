#ifndef pho_n
#define pho_n
#include"Giaodich.h"
using namespace std;
class GIAODICHNHAPHO: public GIAODICH
{
    private:
        string loai;
    public:
        ~GIAODICHNHAPHO(){
            cout<<"da ban nha\n";
        }
        GIAODICHNHAPHO(string loai = " "): loai(loai){}
        void nhap() override {
            GIAODICH::nhap();
            cout<<"chon loai nha (cao cap, thuong)\n";
            cin>>loai;
            while(loai!="cao cap" && loai!="thuong"){
                cout<<"chi co loai cao cap, thuong\n";
                cin>>loai;
            }
        }
        double GIA() override {
            if(loai=="cao cap") return dt*dg;
            else if(loai=="thuong") return dt*dg*0.9;
            return -1;
        }
        void xuat() override {
            GIAODICH::xuat();
            cout<<"\tloai nha la: "<<loai<<"\t gia nha la: "<<GIA()<<endl;
        }
        string TENBATDONGSAN(){
            return"NHA PHO";
        }
};
#endif