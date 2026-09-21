#include<iostream>
using namespace std;
struct ntn{
    int d,m,y;  
};
void nhap(ntn &a){
    cin>>a.d>>a.m>>a.y;
}
int thang(ntn a){
    int xx = abs(2032-a.y);
    int x;
    if(xx==0 || xx%4==0) x=0;
    else x=1;
    if(x==0 && a.m==2){
        return 29;
    }
    else if(x!=0 && a.m==2){
        return 28;
    } else if(a.m==1 || a.m==3 || a.m==5 || a.m==7 || a.m==8 || a.m==10 || a.m==12 ){
        return 31;
    } 
    return 30;
}
void xuli(ntn a){
    a.d++;
    if(a.d>thang(a)){
        a.m++;
        a.d=1;
    }
    if(a.m>12){
        a.m=1;
        a.y++;
    }
    cout<<a.d<<"|"<<a.m<<"|"<<a.y;
}
int main(){
    ntn a;
    nhap(a);
    xuli(a);
    return 0;
}