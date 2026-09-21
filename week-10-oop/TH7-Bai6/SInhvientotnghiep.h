#ifndef sinhvien_h
#define sinhvien_h
#include<iostream>
#include<string>
using namespace std;
class sinhvien
{
    protected:
        int ms, tc;
        double tb;
        string ht, ads;
    public:
        sinhvien(int ms =0, string ht = " ", string ads = " ", int tc = 0, double tb = 0): ms(ms), tc(tc), tb(tb), ads(ads), ht(ht){}
        virtual ~sinhvien(){}
        virtual string PHANLOAI() = 0;
        virtual bool TOTNGHIEP() = 0;
        double Gettb(){
            return tb;
        }
        virtual void Nhap(){
            cout<<"nhap ma so sanh vien \n";
            cin>>ms;
            cout<<"nhap ho va ten sinh vien\n";
            cin.ignore();
            getline(cin, ht);
            cout<<"nhap dia chi sinh vien\n";
            cin.ignore();
            getline(cin, ads);
            cout<<"nhap tong so tin chi\n";
            cin>>tc;
            cout<<"nhap diem trung binh\n";
            cin>>tb;
        }
        virtual void Xuat(){
            cout<<"SV: "<<ms<<"\t|\t"<<ht<<"\t|\t"<<ads<<"\t|\t"<<tc<<"\t|\t"<<tb;
        }
};
#endif