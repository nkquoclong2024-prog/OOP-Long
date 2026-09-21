#include<iostream>
using namespace std;
class Vehicle
{
    private:
        string cx, lx;
        double gt, xyl;
    public:
        Vehicle(string = "", string = "", double gt = 0, double xyl = 0);
        void nhap(){
            cout<<"NHAP CAC GIA TRI LAN LUOT CHU XE, LOAI XE, TRI GIA XE(>=0), DUNG TICH XI LANH(>=0)";
            getline(cin, cx);
            getline(cin, lx);
            cin>>gt>>xyl;
            cout<<endl;
        }
        void xuat(){
            cout<<cx<<" | "<<lx<<" | "<<gt<<" | "<<xyl<<endl;
        }
        string getcx(){return cx;}
        string getlx(){return lx;}
        double getgt(){return gt;}
        double getxyl(){return xyl;}
        void setcx(string x){cx=x;}
        void setlx(string x){lx=x;}
        void setgt(double x){gt=x;}
        void setxyl(double x){xyl=x;}
        void thue(){
            if(xyl<100) cout<<cx<<" | "<<lx<<" | "<<gt<<" | "<<xyl<<" | THUE CUA XE LA: "<<(1.0/100)*gt<<endl;
            else if(xyl<200) cout<<cx<<" | "<<lx<<" | "<<gt<<" | "<<xyl<<" | THUE CUA XE LA: "<<(3.0/100)*gt<<endl;
            else cout<<cx<<" | "<<lx<<" | "<<gt<<" | "<<xyl<<" | THUE CUA XE LA: "<<(5.0/100)*gt<<endl;
        }
};
Vehicle::Vehicle(string x, string y, double k, double l){
    cx=x;
    lx=y;
    gt=k;
    xyl=l;
}
int main(){
    Vehicle xe1("Nguyen Van A", "wave", 3000, 50), xe2("Nguyen Van B", "vision", 10000, 150),xe3;
    cout<<"NHAP DU LIEU XE 3 LA : \n";
    xe3.nhap();
    cout<<"BANG KE KHAI";
    xe1.thue();
    xe2.thue();
    xe3.thue();
    return 0;
}