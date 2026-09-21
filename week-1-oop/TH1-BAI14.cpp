#include<iostream>
#include<math.h>
#include<map>
using namespace std;
string ql[]= {"KEO", "BUA", "BAO"};
map<string,string> mp={
    {"KEO","BUA"},
    {"BUA","BAO"},
    {"BAO","KEO"}
};
void input(string &a){
    cout<<"CHON KEO, BUA HAY BAO: ";
    cin>>a;
}
void choi(string a){
    int may = rand()%3;
    if(mp[a]==ql[may]){
        cout<<"THUA";
    } else if(mp[ql[may]]==a){
        cout<<"THANG";
    } else cout<<"HOA";
}
int main(){
    srand (time(NULL));
    string a;
    input(a);
    choi(a);
    return 0;
}