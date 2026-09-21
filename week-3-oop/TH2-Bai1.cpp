#include<iostream>
#include<math.h>
using namespace std;
class cPhanSo
{
    private:
        double ts,ms;
    public:
        ~cPhanSo();
        cPhanSo(double = 0, double = 1);
        void Nhap();
        void Xuat();
        void Setps(double, double);
        double Getts();
        double Getms();
        void Setts(double);
        void Setms(double);
        cPhanSo Tong(cPhanSo);
        cPhanSo Tru(cPhanSo);
        cPhanSo Nhan(cPhanSo);
        cPhanSo Chia(cPhanSo);

};
cPhanSo::~cPhanSo(){
    cout<<"DA HUY PS\n";
}
cPhanSo::cPhanSo(double x, double y){
    ts = x;
    ms = y;
}
void cPhanSo::Nhap(){
    cout<<"NHAP TU SO:\n";
    cin>>ts;
    cout<<"NHAP MAU SO:\n";
    do{
        cin>>ms;
        if(ms!=0) break;
        cout<<"MAU SO NHAP PHAI KHAC 0\n";
    } while(1);
    cout<<endl;
}
void cPhanSo::Xuat(){
    if(this->ms==1) cout<<"PHAN SO LA: "<<this->ts<<endl;
    else cout<<"PHAN SO LA: "<<this->ts<<"/"<<this->ms<<endl;
}
void cPhanSo::Setps(double ts, double ms){
    this->ts=ts;
    this->ms=ms;
    cout<<"DA THAY PS\n";
}
void cPhanSo::Setts(double x){
    ts = x;
    cout<<"DA THAY TS\n";
}
void cPhanSo::Setms(double x) {
    ms = x;
    cout<<"DA THAY MS\n";
}
double cPhanSo::Getts(){
    return ts;
}
double cPhanSo::Getms(){
    return ms;
}
cPhanSo cPhanSo::Tong(cPhanSo y) {
    cout<<"DA THUC HIEN PHEP CONG \n";
    double kts = this->ts*y.Getms() + this->ms*y.Getts();
    double kms = this->ms*y.Getms();
    cPhanSo kq(kts, kms);
    return kq;
}
cPhanSo cPhanSo::Tru(cPhanSo y) {
    cout<<"DA THUC HIEN PHEP TRU \n";
    double kts=this->ts*y.Getms() - this->ms*y.Getts();
    double kms=this->ms*y.Getms();
    cPhanSo kq(kts, kms);
    return kq;
}
cPhanSo cPhanSo::Nhan(cPhanSo y) {
    cout<<"DA THUC HIEN PHEP NHAN \n";
    double kts=this->ts*y.Getts();
    double kms=this->ms*y.Getms();
    cPhanSo kq(kts, kms);
    return kq;
}
cPhanSo cPhanSo::Chia(cPhanSo y) {
    cout<<"DA THUC HIEN PHEP CHIA \n";
    double kts=this->ts*y.Getms();
    double kms=this->ms*y.Getts();
    cPhanSo kq(kts, kms);
    return kq;
}
int main(){
    cPhanSo x1, x2;
    int k = 0;
    cout<<"Nhap 2 phan so : \n";
    x1.Nhap();
    x2.Nhap();
    do{
        cout<<"CHON CAC OPTION \n";
        cout<<"1: LA PHEP CONG  \n";
        cout<<"2: LA PHEP TRU  \n";
        cout<<"3: LA PHEP NHAN  \n";
        cout<<"4: LA PHEP CHIA  \n";
        cout<<"5: DE HUY\n";
        cout<<"NHAP SO : ";
        cin>>k;
        cout<<endl;
        if(k==1){
            x1.Tong(x2).Xuat();
        } else if(k==2){
            x1.Tru(x2).Xuat();
        } else if(k==3){
            x1.Nhan(x2).Xuat();
        } else if(k==4){
            x1.Chia(x2).Xuat();
        }
    } while(k!=5);
    return 0;
}
