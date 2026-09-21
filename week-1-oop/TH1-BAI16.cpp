#include<iostream>
using namespace std;
void ht(){
    cout<<"NHAP BAN KINH R: ";
    double r; cin>>r;
    cout<<"DIEN TICH HINH TRON LA: "<<r*r*3.14;
}
void hcn(){
    cout<<"NHAP CHIEU DAI VA RONG: ";
    double a,b; cin>>a>>b;
    cout<<"DIEN TICH HINH CHU NHAT LA: "<<a*b;
}
void tg(){
    cout<<"NHAP DUONG CAO VA CANH DAY: ";
    double h,a; cin>>h>>a;
    cout<<"DIEN TICH TAM GIAC LA: "<<(1/2)*h*a;
}
void menu(int &a){
    cout<<"CHON CACH SO 1 2 3 TUONG UNG VOI CAC LUA CHON"<<endl;
    cout<<"1: DIEN TICH HINH TRON"<<endl;
    cout<<"2: DIEN TICH HINH CHU NHAT"<<endl;
    cout<<"3: DIEN TICH TAM GIAC"<<endl;
    cout<<"0: THOAT"<<endl;
    cout<<"NHAP SO: ";
    cin>>a;
    if(a==1) ht();
    else if(a==2) hcn();
    else if(a==3) tg();
    else if(a!=0) cout<<"NHAP LAI"<<endl;
}
int main(){
    int a;
    do{
        menu(a);
    }while(a!=0);
    cout<<"DA DUNG"<<endl;
    return 0;
}