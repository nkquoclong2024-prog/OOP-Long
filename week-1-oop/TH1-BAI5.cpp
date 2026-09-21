#include<iostream>
#include<string>
using namespace std;
struct sv{
    string name;
    double math, lit;
};
void nhap(sv &a){
    getline(cin, a.name);
    cin>>a.math>>a.lit;
}
int main(){
    sv a;
    nhap(a);
    cout<<(a.math+a.lit)/2;
    return 0;
}