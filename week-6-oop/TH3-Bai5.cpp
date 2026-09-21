#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class cDaThuc {
    private:
        int n;
        vector<double> a;

    public:
        cDaThuc(int n = 0): n(n), a(n + 1) {}
    void nhap(){
        cout<<"\nNhap "<<n+1<<" gia tri cua da thuc\n";
        for(int i = n;i>=0;i--){
            cin>>a[i];
        }
    }
    void xuat() const {
        int t = 0;
        for(int i = n; i>=0;i--){
            if(a[i]==0){
                t++;
                continue;
            }
            if(i!=n-t){
                if(a[i]>0) cout<<"+";
                else cout<<"-";
            }
            if(i!=0) cout<<abs(a[i])<<"x^"<<i;
            else cout<<abs(a[i]);
        }
    }
    cDaThuc operator + (const cDaThuc &c) const {
        int kc = min(n,c.n);
        cDaThuc ans(max(c.n,n));
        for(int i = 0;i<=kc;i++){
            ans.a[i]=c.a[i]+a[i];
        }
        if(kc==n){
            for(int i = kc+1; i<=c.n;i++){
                ans.a[i]=c.a[i];
            }
        } else{
            for(int i = kc+1; i<=n;i++){
                ans.a[i]=a[i];
            }
        }
        return ans;
    }
    double giatri(double x) const{
        double kq = 0;
        for(int i = n;i>=0;i--){
            kq+=a[i]*pow(x,i);
        }
        return kq;
    }
    cDaThuc operator - (const cDaThuc& c) const {
        int kc = min(n,c.n);
        cDaThuc ans(max(c.n,n));
        for(int i = 0;i<=kc;i++){
            ans.a[i]=a[i]-c.a[i];
        }
        if(kc==n){
            for(int i = kc+1; i<=c.n;i++){
                ans.a[i]=-c.a[i];
            }
        } else{
            for(int i = kc+1; i<=n;i++){
                ans.a[i]=a[i];
            }
        }
        return ans;
    }
    friend istream& operator >> (istream& is, cDaThuc& kk){
        kk.nhap();
        return is;
    }
    friend ostream& operator << (ostream& os, const cDaThuc& kk){
        kk.xuat();
        cout<<endl;
        return os;
    }
};
int main(){
    int k;
    cout<<"nhap hang cua da thuc\n";
    cin>>k;
    cDaThuc a(k);
    cin>>a;
    do{
        cout<<"nhap cac so tu 0->3\n";
        cout<<"0: xuat da thuc vua nhap\n";
        cout<<"1: gia tri cua da thuc voi 1 gia tri x cu the\n";
        cout<<"2: cong hai da thuc\n";
        cout<<"3: tru hai da thuc\n";
        cout<<"lon hon 4 tu dong huy\n";
        cin>>k;
        if(k==0){
            cout<<a;
        } else if(k==1){
            cout<<"nhap gia tri cua x la: \n";
            double x; cin>>x;
            cout<<"gia tri cua phuong trinh khi x = "<<x<<" la "<<a.giatri(x);
        } else if(k==2){
            cout<<"nhap hang cua da thuc can cong\n";
            int n; cin>>n;
            cDaThuc b(n); cin>>b;
            cout<<"da thuc khi cong: \n";
            cout<<b+a;
        } else if(k==3){
            cout<<"nhap hang cua da thuc can tru\n";
            int n; cin>>n;
            cDaThuc b(n); cin>>b;
            cout<<"da thuc khi tru : \n";
            cout<<a-b;
        }
    }while(k<4);
    cout<<"da huy";
    return 0;
}