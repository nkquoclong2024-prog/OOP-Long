#include<iostream>
#include<math.h>
using namespace std;
class PTBac1
{
    private:
        double a, b;
    public:
        PTBac1(double = 0, double = 0);
        void seta(double x){a = x;}
        void setab(double x, double y){a = x; b = y;}
        void Nhap(){
            cin>>a>>b;
        }
        bool giai(){
            if(a==0 && b==0){
                cout<<"PT VO SO NGHIEM\n";
                return false;
            } else if(a==0){
                cout<<"PT VO NGHIEM\n";
                return false;
            } else return true;
        }
        void xuat(){
            if(!giai()) return;
            cout<<a<<"x ";
            if (b>0) cout<<"+ "<<b<<" = "<<-b/a<<endl;
            else if(b<0) cout<<"- "<<abs(b)<<" = "<<-b/a<<endl;
            else cout<<"= "<<0<<endl;
        }
};
PTBac1::PTBac1(double x, double y){
    a = x;
    b = y;
}
int main(){
    PTBac1 d1(0,0);
    cout<<"nhap he so a va b";
    d1.Nhap();
    d1.xuat();
    return 0;
}