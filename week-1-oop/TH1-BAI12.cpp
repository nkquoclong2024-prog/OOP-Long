#include<iostream>
#include<iomanip>
using namespace std;
int nhap(){
    int x; cin>>x;
    return x;
}
void KT(double a,  double b){
    if(a==0 && b==0) cout<<"VO SO NGHIEM";
    else if(a==0) cout<<"VO NGHIEM";
    else cout<<fixed<<setprecision(2)<<b/a; 
} 
int main(){
    double a,b;
    a=nhap();
    b=nhap();
    KT(a,b);
    return 0;
}