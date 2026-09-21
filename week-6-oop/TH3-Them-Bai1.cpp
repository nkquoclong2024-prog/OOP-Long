#include<iostream>
#include<math.h>
#define tidi 0.00001
using namespace std;
class cdiem{
    private:
        double x,y;
    public:
        static int sdiem;
        cdiem (double x = 0, double y = 0): x(x), y(y){}
        void nhap(){
            sdiem++;
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
int cdiem::sdiem = 0;
class ctamgiac{
    private:
        cdiem a,b,c;
    public:
        static int stamgaic;
        ctamgiac(cdiem a = (0,0) , cdiem b = (1,0) , cdiem c = (0,1) ):a(a), b(b), c(c){}
        void nhap(){
            stamgaic++;
            cout<<"nhap nhap cac diem cua tam giac\n";
            cout<<"diem thu 1\n";
            a.nhap();
            cout<<"diem thu 2\n";
            b.nhap();
            cout<<"diem thu 3\n";
            c.nhap();
        }
        void xuat(){
            cout<<"cac diem cua tam giac la\n";
            cout<<"diem thu 1\n";
            a.xuat();
            cout<<"diem thu 2\n";
            b.xuat();
            cout<<"diem thu 3\n";
            c.xuat();
        }
        double cv(){
            double c1 = kc(a,b), c2 = kc(b,c), c3 = kc(a,c);
            if(((c1+c2)<c3 && abs(c1-c2)>c3) || ((c1+c3)<c2 && abs(c1-c3)>c2) || ((c2+c3)<c1 && abs(c3-c2)>c1) || c1*c2*c3==0){
                cout<<"tam giac ko hop le\n";
                return 0;
            }
            return c1+c2+c3;
        }
        double dt(){
            double c1 = kc(a,b), c2 = kc(b,c), c3 = kc(a,c);
            if(((c1+c2)<c3 && abs(c1-c2)>c3) || ((c1+c3)<c2 && abs(c1-c3)>c2) || ((c2+c3)<c1 && abs(c3-c2)>c1) || c1*c2*c3==0){
                cout<<"tam giac ko hop le\n";
                return 0;
            }
            cout<<c1<<" "<<c2<<" "<<c3<<endl;
            double ncv = cv()/2;
            double kq=ncv*(ncv-c1)*(ncv-c2)*(ncv-c3);
            return sqrt(kq);
        }
        void pl(){
            double c1 = kc(a,b), c2 = kc(b,c), c3 = kc(a,c);
            if(((c1+c2)<c3 && abs(c1-c2)>c3) || ((c1+c3)<c2 && abs(c1-c3)>c2) || ((c2+c3)<c1 && abs(c3-c2)>c1) || c1*c2*c3==0){
                cout<<"tam giac ko hop le\n";
                return;
            }
            if(c1==c2 && c2==c3){
                cout<<"tam giac hop le la tam giac deu"<<endl;
                return;
            } else if(c1==c2 || c1==c3 || c2==c3){
                if((c1*c1+c2*c2-c3*c3)<tidi || (c1*c1+c3*c3-c2*c2)<tidi || (c3*c3+c2*c2-c1*c1)<tidi) cout<<"tam giac hop le la tam giac vuong can\n";
                else cout<<"tam giac hop le la tam giac can"<<endl;
                return;
            } else if((c1*c1+c2*c2-c3*c3)<tidi || (c1*c1+c3*c3-c2*c2)<tidi || (c3*c3+c2*c2-c1*c1)<tidi){
                cout<<"tam giac hop le la tam giac vuong\n";
                return;
            } else if((c1+c2)>c3 && abs(c1-c2)<c3){
                cout<<"tam giac hop le la tam giac thuong\n";
                return;
            } else cout<<"tam giac ko hop le\n";
        }
         
};
int ctamgiac::stamgaic = 0;
int main(){
    ctamgiac abc;
    abc.nhap();
    int k = 10;
    do{
        cout<<"==============menu==============\n";
        cout<<"0: thay doi gia tri cua cac diem\n";
        cout<<"1: In ra cac diem cua tam giac\n";
        cout<<"2: tinh chu vi tam giac\n";
        cout<<"3: tinh dien tich tam giac\n";
        cout<<"4: kiem tra tam giac hop le va phan loai\n";
        cout<<"5: xuat ra cac diem da nhap va so tam giac da nhap\n";
        cout<<"6: de huy\n";
        cin>>k;
        if(k==0){
           abc.nhap();
        } else if(k==1){
            abc.xuat();
        } else if(k==2){
            cout<<"chu vi tam giac la: "<<abc.cv()<<endl;
        } else if(k==3){
            cout<<"dien tich tam giac la: "<<abc.dt()<<endl;
        } else if(k==4){
            abc.pl();
        } else if(k==5){
            cout<<"so diem la: "<<cdiem::sdiem<<endl;
            cout<<"so tam giac la: "<<ctamgiac::stamgaic<<endl;
        }
    }while(k!=6);
    cout<<"da huy\n";
    return 0;
}