#include<iostream>
#include<math.h>
#define tidy 0.000001
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
class cHCN{
    private:
        cdiem A,B;
    public:
        static int sHCN;
        cHCN(cdiem A =(0,0), cdiem B = (0,0)): A(A), B(B){}
        void nhap(){
            sHCN++;
            cout<<"nhap cac diem cua HCN\n";
            A.nhap();
            B.nhap();
        }
        void xuat(){
            cout<<"cac diem tao thanh HCN\n";
            A.xuat();
            B.xuat();
        }
        void dch(int x){
            A.td(x,x);
            B.td(x,x);
        }
        double cv(){
            return 2*(abs(A.getX()-B.getX())+abs(A.getY()-B.getY()));
        }
        double dt(){
             return abs(A.getX()-B.getX())*abs(A.getY()-B.getY());
        }
        void kt(){
            if(kc(A,B)<tidy){
                cout<<"khong hop le\n";
            } else cout<<"hop le\n";
        }
};  
int cHCN::sHCN=0;
int main(){
    cHCN c;
    c.nhap();
    cout<<"di chuyen hinh chu nhat len 5 don vi\n";
    c.xuat();
    c.dch(5);
    c.xuat();
    cout<<"chu vi HCN la: "<<c.cv()<<endl;
    cout<<"dien tich HCN la: "<<c.dt()<<endl;
    cout<<"kiem tra tinh hop le\n";
    c.kt();
    c.nhap();
    cout<<"so HCN da nhap la: "<<cHCN::sHCN<<endl;
    return 0;
}