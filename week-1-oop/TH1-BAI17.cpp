#include<iostream>
using namespace std;
void cong(double a, double b){
    cout<<"a + b = "<<a+b;
}
void tru(double a, double b){
    cout<<"a - b = "<<a-b;
}
void nhan(double a, double b){
    cout<<"a x b = "<<a*b;
}
void chia(double a, double b){
    cout<<"a : b = "<<a/b;
}
void nhap(double &a, double &b){
    cout<<"NHAP CAC GIA TRI A VA B ";
    cin>>a>>b;
}
int main(){
    double a,b; nhap(a,b);
    cout<<"NHAP CAC KI TU {+ - x :} DE THUC HIEN PHEP TINH"<<endl;
    cout<<"NHAP OUT DE THOAT"<<endl;
    cout<<"NHAP: ";    
    string check;
    do{
        cin>>check;
        if(check=="+") cong(a,b);
        else if(check=="-") tru(a,b);
        else if(check=="x") nhan(a,b);
        else if(check==":") chia(a,b);
        else if(check!="OUT") cout<<"NHAP LAI"<<endl;
    }while(check!="OUT");
    cout<<"DA OUT"<<endl;
    return 0;
}