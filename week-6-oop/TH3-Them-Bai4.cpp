#include<iostream>
#include<math.h>
using namespace std;
class cdiem{
    private:
        double x,y;
    public:
        cdiem (double x = 0, double y = 0): x(x), y(y){}
        void nhap(){
            cout<<"nhap x va y\n";
            cin>>x>>y;
        }
        void xuat(){
            cout<<x<<" "<<y<<endl;
        }
        double getX()const { return x;}
        double getY()const { return y;}
        void setX(double x) { this->x=x;}
        void setY(double y) {this->y=y;}
        void td(double a, double b){
            x+=a; y+=b;
        }
        friend double kc(cdiem a, cdiem b){
            return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
        }
};
class cDTHANG{
    private:
        cdiem a,b;
    public:
        ~cDTHANG(){
            cout<<"DA HUY";
        }
        static int sDTHANG;
        cDTHANG(cdiem a = (0,0), cdiem b = (0,0)): a(a), b(b){}
        void set(double x1, double y1, double x2, double y2){
            a.setX(x1);
            a.setY(y1);
            b.setX(x2);
            b.setY(y2);
        }
        void tinhtien(double x){
            a.td(x,x);
            b.td(x,x);
        }
        void kt(){
            if(a.getX()==b.getX() && a.getY()==b.getY()){
                cout<<"KHONG THOA\n";
            } else cout<<"THOA\n";
        }
        void nhap(){
            cout<<"NHAP CAC DIEM\n";
            a.nhap();
            b.nhap();
            sDTHANG++;
        }
        double cd() const{
            return kc(a,b);
        }
        friend ostream& operator << (ostream& os, cDTHANG& a){
            cout<<"XUAT CAC DIEM TAO RA DOAN THANG\n";
            a.a.xuat();
            a.b.xuat();
            return os;
        }
};
int cDTHANG::sDTHANG = 0;
int main(){
    cDTHANG a;
    a.nhap();
    int k=10;
    do{
        cout<<"========menu=======\n";
        cout<<"0: nhap lai doan thang\n";
        cout<<"1: xuat cac doan thang\n";
        cout<<"2: tin tien doan thang 1 gia tri x\n";
        cout<<"3: kiem tra hop le\n";
        cout<<"4: chieu dai doan thang\n";
        cout<<"5: kiem tra so doan thang da nhap\n";
        cout<<"6: Huy\n";
        cin>>k;
        if(k==0){
            a.nhap();
        } else if(k==1){
            cout<<a;
        } else if(k==2){
            cout<<"nhap 1 gia tri tinh tien\n";
            double x; cin>>x;
            a.tinhtien(x);
        } else if(k==3){
            a.kt();
        } else if(k==4){
            cout<<"doan thang co chieu dai la "<<a.cd()<<endl;
        } else if(k==5){
            cout<<"so doan da nhap la "<<cDTHANG::sDTHANG<<endl;
        }
    }while(k<6);
    return 0;
}