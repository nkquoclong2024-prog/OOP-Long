#include<iostream>
using namespace std;
struct ntn{
    int d,m,y;  
};
void nhap(ntn &a){
    cin>>a.d>>a.m>>a.y;
}
void xuli(ntn a){
    if(a.m<3){
        a.m+=12;
        a.y--;
    }
    int h = (a.d+(13*(a.m+1)/5)+a.y+a.y/4-a.y/100+a.y/400)%7;
    if(h==0) cout<<"THU 7";
    else if (h==1) cout<<"CHU NHAT";
    else cout<<"THU "<<h;
}
int main(){
    ntn a;
    nhap(a);
    xuli(a);
    return 0;
}