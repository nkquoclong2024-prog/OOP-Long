#include<iostream>
#include<vector>
using namespace std;
class CHam{
    private:
        int n;
        vector<int> a;
    public:
        CHam(int n): n(n), a(n){}
        CHam operator + (const CHam& b){
            int k = max(b.n,n);
            CHam tmp(k);
            for(int i = 0;i<k;i++){
                if(i>=n){
                    tmp.a[i]=b.a[i];
                } else if(i>=b.n){
                    tmp.a[i]=a[i];
                } else tmp.a[i]=a[i]+b.a[i];
            }
            return tmp;
        } 
        CHam operator - (const CHam& b){
            int k = max(b.n,n);
            CHam tmp(k);
            for(int i = 0;i<k;i++){
                if(i>=n){
                    tmp.a[i]=-b.a[i];
                } else if(i>=b.n){
                    tmp.a[i]=a[i];
                } else tmp.a[i]=a[i]-b.a[i];
            }
            return tmp;
        } 
        friend istream& operator >> (istream& is, CHam& k){
            for(int i = 0;i<k.n;i++){
                cout<<"nhap x thu "<<i+1<<endl;
                is>>k.a[i];
            }
            return is;
        }
        friend ostream& operator << (ostream& os, const CHam& k){
            int kk = 0;
            for(int i = 0;i<k.n;i++){
                if(k.a[i]==0) continue;
                if(kk == 0) cout<<k.a[i]<<"x";
                else{
                    if(k.a[i]>0) cout<<" + "<<abs(k.a[i])<<"x^"<<i+1;
                    else cout<<" - "<<abs(k.a[i])<<"x^ "<<i+1;
                }
                kk++;
            }
            return os;
        }
};
int main() {
    int n, m;
    cout << "Nhap so luong he so cua da thuc A: "; 
    cin >> n;
    CHam a(n);
    cin>>a; 
    cout << "Nhap so luong he so cua da thuc B: "; 
    cin >> m;
    CHam b(m);
    cin>>b;
    cout << "\nDa thuc A: " << a << endl;
    cout << "Da thuc B: " << b << endl;
    CHam c = a + b;
    cout << "\nKet qua A + B: " << c << endl;
    c = a - b;    
    cout << "Ket qua A - B: " << c << endl;
    return 0;
}