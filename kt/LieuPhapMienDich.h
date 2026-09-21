#ifndef _LieuPhapMienDich
#define _LieuPhapMienDich
#include"Hat.h"
class LieuPhapMienDich: public Hat
{
    private:
        int GioiHamChuKySongCuaTeBaoMangThuoc;
    public:
        ~LieuPhapMienDich(){
            cout<<"Hat lieu phap mien dich thanh cong\n";
        }
        LieuPhapMienDich(string a = " ", int b = 0, string c = " ", double d = 0, double e = 0, int f = 0): Hat(a,b,c,d,e), GioiHamChuKySongCuaTeBaoMangThuoc(f){}
        void Nhap(){
            Hat::Nhap();
            cout<<"nhap gioi han chu ki song cua te bao mang thuoc\n";
            cin>>GioiHamChuKySongCuaTeBaoMangThuoc;
        }
        double GetGHCKSCTBMT(){
            return GioiHamChuKySongCuaTeBaoMangThuoc;
        }
        void TD(double x){
            GioiHamChuKySongCuaTeBaoMangThuoc = x;
        }
        int PL(){
            return 1;
        }
        double NongDoThucTeChuKiThu(int t){
            if(GioiHamChuKySongCuaTeBaoMangThuoc-t) return lieuthuoc;
            return 0;
        }
        void Xuat(){
            Hat::Xuat();
            cout<<"\tty le suy giam doc luc hang gio "<<GioiHamChuKySongCuaTeBaoMangThuoc<<endl;
        }
};
#endif