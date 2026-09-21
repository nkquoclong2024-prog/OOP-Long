#ifndef _ViMoiTruong
#define _ViMoiTruong
#include<iostream>
#include<string>
using namespace std;
class ViMoiTruong
{
    private:
        string mmt;
        double lm, nongdooxi;
    public:
        ViMoiTruong(string a = " ", double b = 0, double c = 0): mmt(a), lm(b), nongdooxi(c){}
        void Nhap(){
            cout<<"nhap ma moi truong\n";
            cin.ignore();
            getline(cin, mmt);
            cout<<"nhap luu luong mau va nong do oxi\n";
            cin>>lm>>nongdooxi;
        }
        void Set(string a, double b, double c){
            mmt = a;
            lm = b;
            nongdooxi = c;
        }
        string Getmmt(){
            return mmt;
        }
        double Getlm(){
            return lm;
        }
        double Getnongdooxi(){
            return nongdooxi;
        }
        void Xuat(){
            cout<<"ma moi truong: "<<mmt<<"\tluu luong mau "<<lm<<"\tnong do oxi "<<nongdooxi<<endl;
        }
};
#endif