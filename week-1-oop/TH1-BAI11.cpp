#include<iostream>
using namespace std;
struct sv{
    string kv;
    double ms,t,v,a;
};
void nhap(sv *a){
    for(int i=0;i<3;i++){
        cin>>a[i].kv>>a[i].ms>>a[i].t>>a[i].v>>a[i].a;
    }
}
double diem(sv a){
    if(a.kv=="A"){
        if(a.ms==1){
            return a.t+a.v+a.a+1.5+1.5;
        } else if(a.ms==2){
            return a.t+a.v+a.a+1.5+1;
        } else if(a.ms==3){
            return a.t+a.v+a.a+1.5+0.5;
        }
    } else if(a.kv=="B"){
        if(a.ms==1){
            return a.t+a.v+a.a+1+1.5;
        } else if(a.ms==2){
            return a.t+a.v+a.a+1+1;
        } else if(a.ms==3){
            return a.t+a.v+a.a+1+0.5;
        }
    } else if(a.kv=="C"){
        if(a.ms==1){
            return a.t+a.v+a.a+0.5+1.5;
        } else if(a.ms==2){
            return a.t+a.v+a.a+0.5+1;
        } else if(a.ms==3){
            return a.t+a.v+a.a+0.5+0.5;
        }
    } 
    return 0;
}
void xl(sv *a){
    for(int i=0;i<3;i++){
        if(a[i].t*a[i].v*a[i].a!=0){
            cout<<diem(a[i])<<endl;
        }
    }
}
int main(){
    sv *a = new sv[3];
    nhap(a);
    xl(a);
    return 0;
}