#include<iostream>
using namespace std;
int ucln(int a, int b){
    while(a*b!=0){
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a+b;
}
void nhap(int &a, int &b){
    cout<<"NHAP a VA b: ";
    cin>>a>>b;
    a=abs(a);
    b=abs(b);
}
int main(){
    int a,b;
    nhap(a,b);
    cout<<"USCLN CUA "<<a<<" VA "<<b<<" LA: "<<ucln(a,b)<<endl;
    cout<<"BSCNN CUA "<<a<<" VA "<<b<<" LA: "<<(a*b)/(ucln(a,b))<<endl;
    return 0;
}