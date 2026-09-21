#include<iostream>
#include<math.h>
using namespace std;
struct ps{
    int ts,ms;
};
void nhap(ps& a){
    cout<<"nhap tu so: ";
    cin>>a.ts;
    do{
        cout<<"nhap mau so khac 0: ";
        cin>>a.ms;
    } while(a.ms==0);
}
void sapxep(ps *a, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ps k;
            if((double)a[i].ts/a[i].ms>(double)a[j].ts/a[j].ms){
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
}
void xuat(ps &a){
    if(a.ms==1) cout<<a.ts;
    else if(a.ms==-1 && a.ts<0) cout<<abs(a.ts);
    else if(a.ms==-1 && a.ts>0) cout<<-a.ts;
    if(a.ts*a.ms>0) cout<<abs(a.ts)<<"/"<<abs(a.ms);
    else if(a.ts*a.ms<0) cout<<abs(a.ts)<<"/"<<abs(a.ms);
    else if(a.ts==0) cout<<0;
}
int main(){
    double mi=INT_MIN, tu,mau;
    int n;
    cin>>n;
    ps* a = new ps[n];
    for(int i=0;i<n;i++){
        nhap(a[i]);
        if(mi<(double)a[i].ts/a[i].ms){
            mi=(double)a[i].ts/a[i].ms;
            tu = a[i].ts;
            mau = a[i].ms;
        }
    }
    sapxep(a,n);
    for(int i=0;i<n;i++){
        xuat(a[i]);
        cout<<" ";
    }
    cout<<endl;
    for(int i=n-1;i>=0;i--){
        xuat(a[i]);
        cout<<" ";
    }
    return 0;
}