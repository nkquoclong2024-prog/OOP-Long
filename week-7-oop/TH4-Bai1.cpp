#include<iostream>
#include<math.h>
using namespace std;
class cSoPhuc{
    private:
        double a,b;
    public:
        cSoPhuc(double a = 0, double b = 0): a(a), b(b){}
        cSoPhuc operator + (const cSoPhuc& c){
            return cSoPhuc(a + c.a, b + c.b);
        }
        cSoPhuc operator - (const cSoPhuc& c){
            return cSoPhuc(a - c.a, b - c.b);
        }
        cSoPhuc operator * (const cSoPhuc& c){
            return cSoPhuc(a*c.a-b*c.b, a*c.b+b*c.a);
        }
        cSoPhuc operator / (const cSoPhuc& c){
            return cSoPhuc((a*c.a+b*c.b)/(c.a*c.a+c.b*c.b), (b*c.a+a*c.b)/(c.a*c.a+c.b*c.b));
        }
        bool operator == (const cSoPhuc& c){
            return ((c.a==a) && (c.b==b));
        }
        bool operator != (const cSoPhuc& c){
            return ((c.a!=a) || (c.b!=b));
        }
        friend istream& operator >> (istream& is, cSoPhuc& c){
            cout<<"nhap so phuc a va b la\n";
            is>>c.a>>c.b;
            return is;
        }
        friend ostream& operator << (ostream& os, cSoPhuc& c){
            if(c.b>0) cout<<c.a<<" + "<<c.b<<"i";
            else if(c.b<0) cout<<c.a<<" - "<<abs(c.b)<<"i";
            else cout<<c.a;
            return os;
        }
};
int main(){
    cSoPhuc a, b, c;
    cin>>a>>b;
    c = a + b;
    cout<<"tong 2 so phuc la:  "<<c<<endl;
    c = a - b;
    cout<<"hieu 2 so phuc la:  "<<c<<endl;
    c = a * b;
    cout<<"tich 2 so phuc la:  "<<c<<endl;
    c = a / b;
    cout<<"thuong 2 so phuc la:  "<<c<<endl; 
    cout<<"so sanh 2 so phuc\n";
    cout<<a<<endl<<b<<endl;
    if(a==b){
        cout<<"a==b";
    } else cout<<"a!=b";    
    return 0;
}