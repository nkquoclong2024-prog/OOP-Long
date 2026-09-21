#include<iostream>
#include<math.h>
using namespace std;
class ps{
    private:
        int ts, ms;
    public:
        ps(int ts = 0, int ms = 1): ts(ts), ms(ms){}
        int gcd(int a, int b){
            while(b){
                a=a%b;
                swap(a,b);
            }
            return a;
        }
        void nhap(){
            cout<<"nhap tu so: ";
            cin>>ts;
            do{
                cout<<"nhap mau so khac 0: ";
                cin>>ms;
            } while(ms==0);
        }
        void rutgon(){
            int k = gcd(abs(ts),abs(ms));
            if(ms==1) cout<<ts;
            else if(ms==-1 && ts<0);
            else if(ms==-1 && ts>0) ts=-ts;
            if(ts*ms>0){
                ts= ts/k; 
                ms =ms/k;
            }
            else if(ts*ms<0) {
                ts=-abs(ts)/k;
                ms = abs(ms)/k;
            }
            else if(ts==0){
                ts = 0;
            }
        }
        bool operator > (const ps& a){
            return ts*a.ms>a.ts*ms;
        }
        bool operator < (const ps& a){
            return ts*a.ms<a.ts*ms;
        }
        bool operator >= (const ps& a){
            return ts*a.ms>=a.ts*ms;
        }
        bool operator <= (const ps& a){
            return ts*a.ms<=a.ts*ms;
        }
        ps operator + (const ps& a){
            return ps(ts*a.ms+a.ts*ms, a.ms*ms);
        }
        ps operator - (const ps& a){
            return ps(ts*a.ms-a.ts*ms, a.ms*ms);
        }
        ps operator / (const ps& a){
            return ps(ts*a.ms, a.ts*ms);
        }
        ps operator * (const ps& a){
            return ps(ts*a.ts, a.ms*ms);
        }
        friend istream& operator >> (istream& is, ps& a){
            cout<<"nhap tu va mau so\n";
            is>>a.ts>>a.ms;
            return is;
        }
        friend ostream& operator << (ostream& os, ps& a){
            cout<<"xuat ra tu va mau la\n";
            cout<<"tu so la: "<<a.ts<<endl;
            cout<<"mau so la: "<<a.ms<<endl;
            return os;
        }
        operator double() const {
            return (double) ts/ms;
        }
        
};
int main(){
    ps a,b,c;
    cin>>a>>b;
    c = a + b;
    c.rutgon();
    cout<<"tong 2 ps co gia tri la: "<<c<<endl;
    c = a - b;
    c.rutgon();
    cout<<"hieu 2 ps co gia tri la: "<<c<<endl;
    c = a * b;
    c.rutgon();
    cout<<"tich 2 ps co gia tri la: "<<c<<endl;
    c = a / b;
    c.rutgon();
    cout<<"thuong 2 ps co gia tri la: "<<c<<endl;
    cout<<"ps truoc do khi ep kieu la: "<<(double) c; 
    cout<<"so sanh a va b \n";
    if(a>b){
        cout<<"a>b";
    } else if(a<b){
        cout<<"a<b";
    } else {
        cout<<"a==b";
    }
    return 0;
}