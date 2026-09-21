#include<iostream>
using namespace std;
void in(int n){
    cout<<"BANG CUU CHUONG THU "<<n<<endl;
    for(int i=1;i<9;i++){
        cout<<n<<" x "<<i<<" = "<<n*i<<endl;
    }
}
void option1(){
    cout<<"NHAP BANG CUU CHUONG MUON IN";
    int n; cin>>n;
    in(n);
}
void option2(){
    cout<<"NHAP m VA n: ";
    int m,n; cin>>m>>n;
    for(int i=m;i<=n;i++){
        in(i);
    }
}
void option3(){
    for(int i=1;i<=9;i++){
        in(i);
    }
}
int main(){
    int a;
    do{
        cout<<"CHON CAC OPTION SAU: "<<endl;
        cout<<"NHAP 1: IN RA BANG CUU CHUONG THU n"<<endl;
        cout<<"NHAP 2: IN TA BANG CUU CHUONG TU m DEN n"<<endl;
        cout<<"NHAP 3: BANG CUU CHUONG TONG HOP"<<endl;
        cout<<"NHAP 0: DE THOAT"<<endl;
        cout<<"NHAP: ";
        cin>>a;
        if(a==1) option1();
        else if(a==2) option2();
        else if(a==3) option3();
        else if(a!=0) cout<<"NHAP LAI"<<endl;
    }while(a!=0);
    cout<<"DA THOAT"<<endl;
    return 0;
}