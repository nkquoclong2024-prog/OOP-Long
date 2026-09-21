#include<iostream>
#include<math.h>
#include<map>
using namespace std;
class NTN
{
    private:
        int d, m, y;
    public:
        NTN(int = 0,int = 0,int = 0);
        void Nhap();
        void Xuat();
        int Getd(){return d;}
        int Getm(){return m;}
        int Gety(){return y;}
        void Setd(int x){d = x;}
        void Setm(int x){m = x;}
        void Sety(int x){y = x;}
        void Tangd();
        void giamd();
        void ktnn();
        void thu();
};
NTN::NTN(int x, int y, int z){
    d=x;
    m=y;
    this->y=z;
}
void NTN::ktnn(){
    if(y%4==0) cout<<"NAM "<<y<<" LA NAM NHUAN \n";
    else cout<<"NAM "<<y<<" KHONG LA NAM NHUAN \n";
}
void NTN::Nhap(){
    int tt[] ={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
    cout<<"NHAP NGAY THANG NAM: ";
    cin>>d>>m>>y;
    if(y%4==0) tt[2]++;
    while(d>tt[m]){
        cout<<"NGAY TOI DA CUA THANG NAY LA: "<<tt[m]<<endl;
        cout<<"NHAP LAI NGAY";
        cin>>d;
    }
    cout<<endl;
}
void NTN::Xuat(){
    cout<<d<<"/"<<m<<"/"<<y<<endl;
}
void NTN::Tangd(){
    int tt[] ={0,31,28,31,30,31,30,31,31,30,31,30,31};
    d++;
    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) tt[2] ++;
    if(d>tt[m]){
        m++;
        d=1;
        if(m>12){
            m=1;
            y++;
        }
    }
}
void NTN::giamd(){
    int tt[] ={0,31,28,31,30,31,30,31,31,30,31,30,31};
    d--;
    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) tt[2] ++;
    if(d<1){
        m--;
        if(m<1){
            m=12;
            y--;
        }
        d = tt[m];
    }
}
void NTN::thu(){
    if(m<3){
        m+=12;
        y--;
    }
    int h = (d+(13*(m+1)/5)+y+y/4-y/100+y/400)%7;
    if(h==0) cout<<"THU 7";
    else if (h==1) cout<<"CHU NHAT";
    else cout<<"THU "<<h;
    cout<<endl;
}
int main(){
    NTN d1;
    d1.Nhap();
    int k = 0;
    do{
        cout<<"cho các lựa chọn sau \n";
        cout<<"1: xuat ngay thang nam\n";
        cout<<"2: tang len 1 ngay\n";
        cout<<"3: giam 1 ngay\n";
        cout<<"4: kiem tra nam nhuan\n";
        cout<<"5: ngay do la thu may\n";
        cout<<"6: HUY\n";
        cin>>k;
        if(k==1){
            d1.Xuat();
        } else if(k==2){
            d1.Tangd();
            d1.Xuat();
        } else if(k==3){
            d1.giamd();
            d1.Xuat();
        } else if(k==4){
            d1.ktnn();
        } else if(k==5){
            d1.thu();
        }
    } while(k!=6);
    cout<<"da huy\n";
    return 0;
}

