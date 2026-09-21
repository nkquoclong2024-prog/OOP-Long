#include<iostream>
#include<math.h>
using namespace std;
class CDate{
    private:
        int y,m,d;
    public:
        CDate(int y = 0, int m = 0, int  d = 0): y(y), m(m), d(d){}
        void kt(){
            int k[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
            if(y%400==0 || (y%4 && y%100!=0)) k[2]++;
            if(d>k[m]){
                d=1;
                m++;
                if(m>12){
                    m=1;
                    y++;
                }
            }
            if(d<1){
                m--;
                if(m<1){
                    m=12;
                    y--;
                }
                d=k[m];
            }
        }
        CDate operator + (int x){
            CDate k(y, m, d+x);
            k.kt();
            return k; 
        }
        CDate operator - (int x){
            CDate k(y, m, d-x);
            k.kt();
            return k; 
        }
        CDate operator ++ (){
            d++;
            kt();
            return *this;
        }
        CDate operator ++ (int){
            CDate tmp = *this;
            d++;
            kt();
            return tmp;
        }
        CDate operator -- (){
            d--;
            kt();
            return *this;
        }
        CDate operator -- (int){
            CDate tmp = *this;
            d--;
            kt();
            return tmp;
        }
        friend istream& operator >> (istream& is, CDate& c){
            int k[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
            cout<<"nhap ngay thang nam\n";
            cout<<"nhap nam\n";
            is>>c.y;
            if(c.y%400==0 || (c.y%4 && c.y%100!=0)) k[2]++;
            cout<<"nhap thang toi da 12 thang\n";
            is>>c.m;
            cout<<"nhap ngay trong thang "<<c.m<<" co toi da "<<k[c.m]<<endl;
            is>>c.d;
            return is;
        }
        friend ostream& operator << (ostream& os, const CDate& c){
            os<<c.d<<" : "<<c.m<<" : "<<c.y;
            return os;
        }
};
int main(){
    CDate a, b, c;
    cin>>a;
    cout<<"nhap x\n";
    int x; cin>>x;
    c = a + x;
    cout<<"tang "<<x<<" ngay: "<<c<<endl;
    c = a - x;    
    cout<<"giam "<<x<<" ngay: "<<c<<endl;
    cout<<"tang ngay ++a la: "<<a<<" chuyen thanh: "<<(++a)<<endl;
    cout<<"tang ngay a++ la: "<<a<<" chuyen thanh: "<<(a++)<<endl;
    cout<<"tang ngay --a la: "<<a<<" chuyen thanh: "<<(--a)<<endl;
    cout<<"tang ngay a-- la: "<<a<<" chuyen thanh: "<<(a--)<<endl;
    return 0;
}