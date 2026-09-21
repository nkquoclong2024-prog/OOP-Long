#include<iostream>
#include<math.h>
using namespace std;
int nhap(){
    int x; cin>>x;
    return x;
}
double DELTA(double a,  double b, double c){
    if(a==0) return -1;
    return b*b-4*a*c;

}
void GIAI(double a, double b, double c){
    if(DELTA(a,b,c)<0){
        cout<<"VO NGHIEM";
        return;
    }
    if(DELTA(a,b,c)==0){
        cout<<"CO 1 NGHIEM LA: "<<-(b*b)/(2*a);
    } else {
        cout<<"CO 2 NGHIEM LA:"<<endl;
        cout<<"x1= "<<(-(b)-sqrt(DELTA(a,b,c)))/(2*a)+0<<endl;
        cout<<"x2= "<<(-(b)+sqrt(DELTA(a,b,c)))/(2*a)+0;
    }
}
int main(){
    double a,b,c;
    a=nhap();
    b=nhap();
    c=nhap();
    GIAI(a,b,c);
    return 0;
}