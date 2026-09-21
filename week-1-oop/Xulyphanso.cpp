#include<iostream>
#include<math.h>
#include"Xulyphanso.h"
using namespace std;
int gcd(int a, int b){
    while(b){
        a=a%b;
        swap(a,b);
    }
    return a;
}
void nhap(ps& a){
    cout<<"nhap tu so: ";
    cin>>a.ts;
    do{
        cout<<"nhap mau so khac 0: ";
        cin>>a.ms;
    } while(a.ms==0);
}
void rutgon(ps &a){
    int k = gcd(abs(a.ts),abs(a.ms));
    if(a.ms==1) cout<<a.ts;
    else if(a.ms==-1 && a.ts<0) cout<<abs(a.ts);
    else if(a.ms==-1 && a.ts>0) cout<<-a.ts;
    if(a.ts*a.ms>0) cout<<"phan so rut gon "<<abs(a.ts)/k<<"/"<<abs(a.ms)/k;
    else if(a.ts*a.ms<0) cout<<"phan so rut gon -"<<abs(a.ts)/k<<"/"<<abs(a.ms)/k;
    else if(a.ts==0) cout<<0;
}
void sosanh(ps a, ps b){
    if((double)a.ts/a.ms<(double)b.ts/b.ms) rutgon(b);
    else rutgon(a);
}