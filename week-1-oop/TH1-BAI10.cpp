#include<iostream>
using namespace std;
struct lv{
    int v,r;
};
void nhap(lv &a){
    cout<<"Nhap gio vao ca: ";
    cin>>a.v;
    while(a.v<6 || a.v>18){
        cout<<"Nhap lai: ";
        cin>>a.v;
    }
    cout<<"Nhap gio ra ca: ";   
    cin>>a.r;
    while(a.r<=a.v || a.r>18){
        cout<<"Nhap lai: ";
        cin>>a.r;
    }
}
int tl(lv a){
    int tl=0;
    if(a.v<12 && a.r>12){
        tl+=(12-a.v)*6000+(a.r-12)*7500;
    } else if(a.r<12){
        tl+=(a.r-a.v)*6000;
    } else{
        tl+=(a.r-a.v)*7500;
    }
    return tl;
}
int main(){
    lv a; nhap(a);
    cout<<tl(a);
    return 0;
}