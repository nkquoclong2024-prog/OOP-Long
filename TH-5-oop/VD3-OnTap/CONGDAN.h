#ifndef _CONGDAN
#define _CONGDAN
#include<iostream>
#include<String>
using namespace std;
class CONGDAN
{
    private:
        string ht,cccd,adds;
        int namSinh;
    public:
        ~CONGDAN(){}
        CONGDAN(string ht = " ", int namSinh = 0, string cccd = " ", string adds = " "): ht(ht), namSinh(namSinh), cccd(cccd), adds(adds){}
        string Getht(){ return ht;}
        string Getcccd(){ return cccd;}
        string Getadds(){ return adds;}
        int GetnamSinh(){ return namSinh;}
        void Nhap(){
            cout<<"nhap ho ten\n";
            getline(cin, ht);
            cout<<"nhap nam sinh\n";
            cin>>namSinh;
            cout<<"nhap can cuoc cong dan\n";
            cin.ignore();
            getline(cin, cccd);
            cout<<"nhap dia chi\n";
            getline(cin, adds);
        }
        void Xuat(){
            cout<<"\tho ten "<<ht<<"\tnam sinh "<<namSinh<<"\tcan cuoc cong dan "<<cccd<<"\tdia chi "<<adds;
        }
};
#endif