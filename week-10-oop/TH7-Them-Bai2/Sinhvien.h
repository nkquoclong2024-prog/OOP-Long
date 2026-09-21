#ifndef N_sinhvien
#define N_sinhvien
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class sinhvien
{
    protected:
        int ms;
        string ht, khoa;
        double dtb;
    public:
        virtual ~sinhvien(){}
        sinhvien(int ms = 0, string ht = " ", string khoa = " ", double dtb = 0): ms(ms), ht(ht), khoa(khoa), dtb(dtb){}
        virtual string PhanLoai() = 0;
        virtual double Hocbong() = 0;
        // virtual int GetDRL(){return 0;}
        // virtual int GetSBV(){return 0;}
        double Getdtb(){
            return dtb;
        }
        int Getms(){
            return ms;
        }
        string Getht(){
            return ht;
        }
        string Getkhoa(){
            return khoa;
        }
        virtual void Nhap(){
            cout<<"nhap ma so sinh vien\n";
            cin>>ms;
            cout<<"nhap ho ten\n";
            cin.ignore();
            getline(cin, ht);
            cout<<"nhap ten khoa\n";
            // cin.ignore();
            getline(cin, khoa);     
            cout<<"nhap diem trung binh\n";
            cin>>dtb;    
        }
        virtual void Xuat(){
            cout<<"ma so: "<<ms<<"\tho ten: "<<ht<<"\tten khoa: "<<khoa<<"\tdiem trung binh: "<<dtb;
        }
};
#endif