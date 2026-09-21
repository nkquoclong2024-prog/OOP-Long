#include<iostream>
#include<math.h>
using namespace std;
class TamGiac
{
    private:
        double a,b,c;
    public:
        TamGiac(double = 1, double = 1, double = 1);
        void Nhap(){
            cin>>a>>b>>c;
        }
        void Xuat(){
            cout<<"DO DAI 3 CANH LA: "<<a<<", "<<b<<", "<<c<<endl;
            if(TGHL()){
                pl();
                cout<<"CHU VI VA DIEN TICH LA: "<<cv()<<" va "<<dt()<<endl;
            }
        }
        bool TGHL(){
            if ((a+b)<c && abs(a-b)>c) return false;
            return true;
        }
        void pl(){
            double c1 = a, c2 = b, c3 = c;
            if(c1==c2 && c2==c3){
                cout<<"TAM GIAC DIEU"<<endl;
                return;
            } else if(c1==c2 || c1==c3 || c2==c3){
                if((c1*c1+c2*c2)==c3*c3 || (c1*c1+c3*c3)==c2*c2 || (c3*c3+c2*c2)==c1*c1) cout<<"TAM GIAC VUONG CAN\n";
                else cout<<"TAM GIAC CAN"<<endl;
                return;
            } else if((c1*c1+c2*c2)==c3*c3 || (c1*c1+c3*c3)==c2*c2 || (c3*c3+c2*c2)==c1*c1){
                cout<<"TAM GIAC VUONG\n";
                return;
            } else if((c1+c2)>c3 && abs(c1-c2)<c3){
                cout<<"TAM GIAC THUONG\n";
                return;
            } else cout<<"KHONG PHAI TAM GIAC\n";
        }
        double cv(){
            return a+b+c;
        }
        double dt(){
            double ncv = cv()/2;
            double kq=ncv*(ncv-a)*(ncv-b)*(ncv-c);
            return sqrt(kq);
        }
};
TamGiac::TamGiac(double x, double y,double z){
    a = x;
    b = y;
    c = z;
}
int main(){
    TamGiac d1(10,10,10);
    cout<<"NHAP CAC CANH CUA TAM GAC :\n";
    d1.Nhap();
    d1.Xuat();
    return 0;
}