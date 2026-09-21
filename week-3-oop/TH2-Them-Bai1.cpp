#include<iostream>
#include<cmath>
using namespace std;
class Diem
{
    private:
        double x,y;
    public:
        Diem(double = 0, double = 0);
        void Nhap(){
            cout<<"NHAP TOA DO DIEM X VA Y: ";
            cin>>x>>y;
            cout<<endl;
        }
        void Xuat(){
            cout<<"DIEM: "<<x<<", "<<y<<endl;
        }
        int getx(){ return x;}
        int gety(){ return y;}
        void setx(int xx){x=xx;}
        void sety(int yy){y=yy;}
        void dichuyen(double x, double y){
            this->x+=x;
            this->y+=y;
        }
        bool kttrung(Diem k){
            return (x==k.getx() && y==k.gety());
        }
        double kc(Diem k){
            double k1 = (k.x-x)*(k.x-x)+(k.y-y)*(k.y-y);
            return sqrt(k1);
        }
        Diem dx(){
            return Diem (-x + 0,-y + 0); 
        }
        double cv(Diem yy, Diem zz){
            double c1 = kc(yy), c2 = kc(zz), c3 = yy.kc(zz);
            return c1+c2+c3;
        }
        double dt(Diem yy, Diem zz){
            double c1 = kc(yy), c2 = kc(zz), c3 = yy.kc(zz);
            double ncv = cv(yy,zz)/2;
            double kq=ncv*(ncv-c1)*(ncv-c2)*(ncv-c3);
            return sqrt(kq);
        }
        void pl(Diem yy, Diem zz){
            double c1 = kc(yy), c2 = kc(zz), c3 = yy.kc(zz);
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

};
Diem::Diem(double x, double y){
    this->x=x;
    this->y=y;
}
int main(){
    Diem d1, d2, d3;
    cout<<"NHAP TOA DO CAC DIEM\n";
    d1.Nhap(); d2.Nhap(); d3.Nhap();
    int  k = 0;
    do{
        cout<<"CHON CAC LUA CHON SAU \n";
        cout<<"1: XUAT DIEM\n";
        cout<<"2: KIEM TRA TRUNG\n";
        cout<<"3: LAY DOI XUNG\n";
        cout<<"4: LAY CHU VI\n";
        cout<<"5: TINH DIEN TICH\n";
        cout<<"6: PHAN LOAI TAM GIAC\n";
        cout<<"7: HUY\n";
        cin>>k;
        if(k==1){
            cout<<"DIEM MUON XUAT 1, 2 hay 3. \n";
            int x; cin>>x;
            if(x==1) d1.Xuat();
            else if(x==2) d2.Xuat();
            else if(x==3) d3.Xuat();
        } else if(k==2){
            cout<<"CAC DIEM MUON KT TRUNG: \n";
            cout<<"GIOI HAN TRONG 3 DIEM\n";
            int x,y; cin>>x>>y;
            Diem dd1,dd2;
            if(x==1) dd1 = d1;
            else if(x==2) dd1 = d2;
            else if(x==3) dd1 = d3;
            if(y==1) dd2 = d1;
            else if(y==2) dd2 = d2;
            else if(y==3) dd2 = d3;
            cout<<dd1.kttrung(dd2)?"CO":"KHONG";
        } else if(k==3){
            cout<<"CHON 1,2,3 DIEM DE LAY DOI XUNG\n";
            int x; cin>>x;
            if(x==1) d1.dx();
            else if(x==2) d2.dx();
            else if(x==3) d3.dx();
        } else if(k==4){
            cout<<"CHU VI CUA TAM GIAC LA: "<<d1.cv(d2,d3)<<endl;
        } else if(k==5){
            cout<<"DIEM TICH CUA TAM GIAC LA: "<<d1.dt(d2, d3)<<endl;
        } else if(k==6){
            d1.pl(d2,d3);
        }
    } while(k!=7);
    cout<<"DA HUY\n";
    return 0;
}