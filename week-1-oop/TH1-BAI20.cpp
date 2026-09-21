#include<iostream>
#include<math.h>
using namespace std;
bool snt(int a){
    if(a==2) return true;
    if(a<2) return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0) return false;
    }
    return true;
}
bool scp(int a){
    if(sqrt(a)==(int)sqrt(a)) return true;
    return false;
}
bool sht(int a){
    int s=0;
    for(int i=1;i<a;i++){
        if(a%i==0) s+=i;
    }
    if(s==a) return true;
    return false;
}
bool sdx(int a){
    int k=a, b=0;
    while(k){
        b=k%10+b*10;
        k=k/10;
    }
    if(b==a) return true;
    return false;
}
int main(){
    cout<<"NHAP SO CAN KT LA: ";
    int a; cin>>a;
    if(snt(a)) cout<<a<<" LA SO NGUYEN TO"<<endl;
    else cout<<a<<" KHONG LA SO NGUYEN TO"<<endl;
    if(scp(a)) cout<<a<<" LA SO CHINH PHUONG"<<endl;
    else cout<<a<<" KHONG LA SO CHINH PHUONG"<<endl;
    if(sht(a)) cout<<a<<" LA SO HOAN THIEN"<<endl;
    else cout<<a<<" KHONG LA SO HOAN THIEN"<<endl;
    if(sdx(a)) cout<<a<<" LA SO DOI XUNG"<<endl;
    else cout<<a<<" KHONG LA SO DOI XUNG"<<endl;
    return 0;
}