#ifndef _Hat
#define _Hat
#include<math.h>
#include<vector>
#include"ViMoiTruong.h"
class Hat
{
    protected:
        string ma, tenhoachat;
        vector<ViMoiTruong> vmt;
        int slvmt;
        double lieuthuoc, hesothamthaumo;
    public:
        Hat(string a = " ", int b = 0, string c = " ", double d = 0, double e = 0): ma(a), slvmt(b), tenhoachat(c), lieuthuoc(d), hesothamthaumo(e){}
        virtual ~Hat(){}
        virtual void Nhap(){
            cout<<"nhap ma hat\n";
            cin.ignore();
            getline(cin, ma);
            cout<<"nhap so luong mach mau da di qua\n";
            cin>>slvmt;
            for(int i = 0;i<slvmt;i++){
                ViMoiTruong x;
                x.Nhap();
                vmt.push_back(x);
            }
            cout<<"nhap vao hoa chat dac tri\n";
            cin.ignore();
            getline(cin, tenhoachat);
            cout<<"nhap vao lieu luong thuoc ban dau va he so tham thau mo\n";
            cin>>lieuthuoc>>hesothamthaumo;
        }
        void Set(string a, int b, string c, double d, double e){
            ma = a;
            slvmt = b;
            tenhoachat = c;
            lieuthuoc = d;
            hesothamthaumo = e;
        }
        void Setds(string a, double b, double c, int i){
            ViMoiTruong x;
            vmt.push_back(x);
            vmt[i].Set(a,b,c);
        }
        string Getms(){
            return ma;
        }
        string GetTHC(){
            return tenhoachat;
        }
        int Getslvmt(){
            return slvmt;
        }
        double GetLieuThuoc(){
            return lieuthuoc;
        }
        double GetHSTTM(){
            return hesothamthaumo;
        }
        string Getmmtds(int i){
            return vmt[i].Getmmt();
        }
        double Getlmds(int i){
            return vmt[i].Getlm();
        }
        double Getnongdooxi(int i){
            return vmt[i].Getnongdooxi();
        }
        virtual void TD(double) = 0;
        virtual int PL() = 0;
        virtual double NongDoThucTeChuKiThu(int) = 0;
        virtual void Xuat(){
            cout<<"Ma chuoi "<<ma<<endl;
            cout<<"danh sach cac vi moi truong mach mau da di qua\n";
            for(int i = 0;i<slvmt;i++){
                vmt[i].Xuat();
            }
            cout<<"ten hoa chat dac tri "<< tenhoachat<<"\tlieu luong thuoc ban dau "<<lieuthuoc<<"\the so tham thau mo "<<hesothamthaumo;
        }
};
#endif