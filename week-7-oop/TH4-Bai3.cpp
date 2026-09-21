#include<iostream>
#include<math.h>
using namespace std;
class CTime{
    private:
        int h,p,s;
    public:
        CTime(int h = 0, int p = 0, int  s = 0): h(h), p(p), s(s){}
        void kt(){
            if(s>60){
                s=0;
                p++;
                if(p>60){
                    p=0;
                    h++;
                    if(h>24){
                        h=1;
                    }
                }
            }
            if(s<0){
                s=60;
                p--;
                if(p<0){
                    p=60;
                    h--;
                    if(h<1){
                        h=24;
                    }
                }
            }
        }
        CTime operator + (const CTime& c){
            CTime k(h+c.h, p+c.p, s+c.s);
            k.kt();
            return k; 
        }
        CTime operator - (const CTime& c){
            CTime k(h-c.h, p-c.p, s-c.s);
            k.kt();
            return k; 
        }
        CTime operator ++ (){
            s++;
            kt();
            return *this;
        }
        CTime operator ++ (int){
            CTime tmp = *this;
            s++;
            kt();
            return tmp;
        }
        CTime operator -- (){
            s--;
            kt();
            return *this;
        }
        CTime operator -- (int){
            CTime tmp = *this;
            s--;
            kt();
            return tmp;
        }
        friend istream& operator >> (istream& is, CTime& c){
            cout<<"nhap gio ([1,24]), phut ([0,60]), giay ([0,60])\n";
            is>>c.h>>c.p>>c.s;
            return is;
        }
        friend ostream& operator << (ostream& os, const CTime& c){
            os<<c.h<<" : "<<c.p<<" : "<<c.s;
            return os;
        }
};
int main(){
    CTime a, b, c;
    cin>>a>>b;
    c = a + b;
    cout<<"tong 2 gio la: "<<c<<endl;
    c = a - b;    
    cout<<"hieu 2 gio la: "<<c<<endl;
    cout<<"tang gio ++a la: "<<a<<" chuyen thanh: "<<(++a)<<endl;
    cout<<"tang gio a++ la: "<<a<<" chuyen thanh: "<<(a++)<<endl;
    cout<<"tang gio --a la: "<<a<<" chuyen thanh: "<<(--a)<<endl;
    cout<<"tang gio a-- la: "<<a<<" chuyen thanh: "<<(a--)<<endl;
    return 0;
}