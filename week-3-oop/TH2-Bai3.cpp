#include<iostream>
#include<math.h>
using namespace std;
class SP
{
    private:
        double x,y;
    public:
        SP(double = 0 , double = 0 );
        void Xuat();
        void nhap();
        double getx();
        double gety();
        void setx(double);
        void sety(double);
        void setxy(double, double);
        SP Tong(SP);
        SP Tru(SP);
        SP Nhan(SP);
        SP Chia(SP);
};
SP::SP(double xx, double yy){
    x = xx;
    y = yy;
}
void SP::Xuat(){
    cout<<"So phuc la: ("<<x<<","<<y<<")\n";
}
void SP::nhap(){
    cout<<"NHAP SO PHUC GIA TRI X VA Y LA: ";
    cin>>x>>y;
    cout<<endl;
}
double SP::getx(){
    return x;
}
double SP::gety(){
    return y;
}
void SP::setx(double xx){
    x=xx;
    cout<<"DA THAY DOI X\n";
}
void SP::sety(double yy){
    y=yy;
    cout<<"DA THAY DOI Y\n";
}
void SP::setxy(double xx, double yy){
    x=xx;
    y=yy;
    cout<<"DA THAY DOI X VA Y\n";
}
SP SP::Tong(SP x){
    cout<<"DA THUC HIEN PHEP CONG \n";
    double k1 = this->x+x.getx();
    double k2 = this->y+x.gety();
    SP kq(k1, k2);
    return kq;
}
SP SP::Tru(SP x){
    cout<<"DA THUC HIEN PHEP TRU \n";
    double k1 = this->x-x.getx();
    double k2 = this->y-x.gety();
    SP kq(k1, k2);
    return kq;
}
SP SP::Nhan(SP x){
    cout<<"DA THUC HIEN PHEP NHAN \n";
    double k1 = this->x*x.getx()-this->y*x.gety();
    double k2 = this->x*x.gety() + this->y*x.getx();
    SP kq(k1, k2);
    return kq;    
}
SP SP::Chia(SP x){
    cout<<"DA THUC HIEN PHEP CHIA \n";
    double k1 = (this->x*x.getx()+this->y*x.gety())/(x.getx()*x.getx()+x.gety()*x.gety());
    double k2 = (this->y*x.getx()-this->x*x.gety())/(x.getx()*x.getx()+x.gety()*x.gety());
    SP kq(k1, k2);
    return kq;    
}
int main(){
    SP d1, d2;
    int k = 0;
    cout<<"NHAP 2 SO PHUC la: \n";
    d1.nhap(); d2.nhap();
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
            d1.Tong(d2).Xuat();
        } else if(k==2){
            d1.Tru(d2).Xuat();
        } else if(k==3){
            d1.Nhan(d2).Xuat();
        } else if(k==4){
            d1.Chia(d2).Xuat();
        }
    } while(k!=5);
    cout<<"DA KET THUC\n";
    return 0;
}