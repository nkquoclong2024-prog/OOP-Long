#include<iostream>
using namespace std;
void CHOI(){
    int a; cin>>a;
    int b= rand();
    while(a!=b){
        cout<<"BAN HAY DOAN LAI";
        cin>>a;
    }
    cout<<"CHUC MUNG";
}
int main(){
    srand(time(NULL));
    CHOI();
    return 0;
}