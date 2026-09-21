#include<iostream>
#include<string>
using namespace std;
class LOPSTRING{
    private:
        string a;
    public:
        LOPSTRING(const string& x = ""): a(x) {}
        ~LOPSTRING(){
            cout<<"DA HUY\n";
        }
        int size(){
            return a.size();
        }
        LOPSTRING& operator=(const LOPSTRING& x){
            a = x.a;
            return *this;
        }
        LOPSTRING operator+(const LOPSTRING& x ){
            LOPSTRING kq;
            kq.a = a + x.a ;
            return kq;
        }
        void reverse(){
            string x="";
            for(int i = size()-1; i>=0;i--){
                x+=a[i];
            }
            a = x;
        }
        string vh();
        string vt(){
            string x = "";
            for(int i = 0;i<size();i++){
                if(a[i]>'Z') x+=a[i];
                else x+=(char)((int) a[i])+((int)('a'-'A'));
            }
            return x;
        }
        friend istream& operator>>(istream& is, LOPSTRING& x);
        friend ostream& operator<<(ostream& os, LOPSTRING& x);
};
string LOPSTRING::vh(){
    string x = "";
    for(int i = 0;i<size();i++){
        if(a[i]<'a') x+=a[i];
        else x+=(char)((int) a[i])+int('A'-'a');
    }
    return x;
}
istream& operator>>(istream& is, LOPSTRING& x){
    cout<<"NHAP CHUOI: \n";
    is>>x.a;
    return is;
}
ostream& operator<<(ostream& os, LOPSTRING& x){
    os<<x.a;
    return os;
}
int main(){
    LOPSTRING x,y,z;
    cout<<"NHAP 1 CHUOI DE XAC DINH CHIEU DAI: \n";
    cin>>x;
    cout<<x.size()<<endl;
    cout<<"NHAP THEM 1 CHUOI DE NOI 2 CHUOI:\n";
    cin>>y;
    z= x + y;
    cout<<z<<endl;
    cout<<z<<" DAO LAI LA: "; 
    z.reverse();
    cout<<z<<endl;
    cout<<x<<" VIET HOA LA: ";
    cout<<x.vh()<<endl;
    cout<<y<<" VIET THUONG LA: ";
    cout<<y.vt()<<endl;
    return 0;
}