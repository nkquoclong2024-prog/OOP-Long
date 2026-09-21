#include<iostream>
#include<string>
using namespace std;
struct sv{
    string name;
    double math, lit;
};
void nhap(sv & a){
    cin.ignore();
    getline(cin, a.name);
    cin>>a.math>>a.lit;
}
int main(){
    int n; cin>>n;
    sv *ds = new sv[n+1];
    sv cao, thap;
    cao.math=0, cao.lit=0;
    thap.math=10, thap.lit=10;
    for(int i=0;i<n;i++){
        nhap(ds[i]);
        if((ds[i].math+ds[i].lit)/2>(cao.math+cao.lit)/2) cao=ds[i];
        if((ds[i].math+ds[i].lit)/2<(thap.math+thap.lit)/2) thap=ds[i];
    }
    cout<<"Trung binh cao nhat "<<cao.name<<"|"<<cao.math<<"|"<<cao.lit<<endl;
    cout<<"Trung binh thap nhat "<<thap.name<<"|"<<thap.math<<"|"<<thap.lit;
    return 0;
}