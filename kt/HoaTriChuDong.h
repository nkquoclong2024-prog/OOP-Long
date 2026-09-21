#ifndef _HoaTriChuDong
#define _HoaTriChuDong
#include"Hat.h"
class HoaTriChuDong: public Hat
{
    private:
        double TyLeSuyGiamDocLucHangGio;
    public:
        ~HoaTriChuDong(){
            cout<<"Hat hoa tri chu dong thanh cong\n";
        }
        HoaTriChuDong(string a = " ", int b = 0, string c = " ", double d = 0, double e = 0, double f = 0): Hat(a,b,c,d,e), TyLeSuyGiamDocLucHangGio(f){}
        void Nhap(){
            Hat::Nhap();
            cout<<"nhap ty le suy giam doc luc hang gio\n";
            cin>>TyLeSuyGiamDocLucHangGio;
        }
        double GetTLSGDLHG(){
            return TyLeSuyGiamDocLucHangGio;
        }
        void TD(double x){
            TyLeSuyGiamDocLucHangGio = x;
        }
        int PL(){
            return 0;
        }
        double NongDoThucTeChuKiThu(int t){
            return (double)lieuthuoc*hesothamthaumo*(1.0-TyLeSuyGiamDocLucHangGio*pow(0.97,t));
        }
        void Xuat(){
            Hat::Xuat();
            cout<<"\tty le suy giam doc luc hang gio "<<TyLeSuyGiamDocLucHangGio<<endl;
        }
};
#endif