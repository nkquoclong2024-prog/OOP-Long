#include<iostream>
using namespace std;
class cdmy{
    private:
        int d, m, y;
    public:
        ~cdmy(){
            cout<<"DA HUY\n";
        }
        cdmy(int x = 0, int y = 0, int z = 0): d(x), m(y), y(z){}
        friend istream& operator >> (istream& is, cdmy& a){
            is>>a.d>>a.m>>a.y;
            return is;
        } 
        friend ostream& operator << (ostream& os, cdmy& a){
            os<<"ngay: "<<a.d<<"\nthang:"<<a.m<<"\nnam:"<<a.y<<endl;
            return os;
        }
        void kt(){
            if(y%400==0 || (y%4==0 && y%100!=0)){
                cout<<"LA NAM NHUAN\n";
            }   else{
                cout<<"KHONG LA NAM NHUAN\n";
            }

        }
};
int main(){
    cdmy a;
    cout<<"Nhap ngay thang nam\n";
    cin>>a;
    int k=3;
    do{
        cout<<"=======menu======\n";
        cout<<"0: nhap ngay thang nam\n";
        cout<<"1: xuat ngay thang nam\n";
        cout<<"2: kiem tra nam nhuan\n";
        cout<<"3: huy\n";
        cin>>k;
        if(k==0){
            cin>>a;
        } else if(k==1){
            cout<<a;
        } else if(k==2){
            a.kt();
        }
    }while(k<3);
    return 0;
}