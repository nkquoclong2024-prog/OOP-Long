#include<iostream>
#include<vector>
using namespace std;
class cdmy{
    private:
        int d, m, y;
    public:
        cdmy(int x = 0, int y = 0, int z = 0): d(x), m(y), y(z){}
        int getd(){return d;};
        int getm(){return m;};
        int gety(){return y;};
        friend istream& operator >> (istream& is, cdmy& a){
            is>>a.d>>a.m>>a.y;
            return is;
        } 
        friend ostream& operator << (ostream& os, cdmy& a){
            os<<a.d<<" / "<<a.m<<" / "<<a.y;
            return os;
        }
        cdmy operator == (const cdmy& a){
            d = a.d;
            m = a.m;
            y = a.y;
            return *this;
        }
};
class cNhanVienSX{
    private:
        string ma, ht;
        cdmy ngs;
        int ssp, giasp;
    public:
        cNhanVienSX(string x = "", string ht = "", cdmy ngs = (0,0,0), int ssp = 0, int giasp = 0): ma(x), ht(ht), ngs(ngs), ssp(ssp), giasp(giasp){}
        friend istream& operator >> (istream& is, cNhanVienSX& a){
            cin.ignore();
            cout<<"nhap ma nhan vien\n";
            getline(is, a.ma);
            cout<<"nhap ho ten nhan vien\n";
            getline(is, a.ht);
            cout<<"nhap ngay thang nam sinh nhan vien\n";
            is>>a.ngs;
            cout<<"nhap so luong san pham va gia moi san pham\n";
            is>>a.ssp>>a.giasp;
            return is;
        }
        cNhanVienSX operator == (const cNhanVienSX& a){
            ma = a.ma;
            ht = a.ht;
            ngs = a.ngs;
            ssp = a.ssp;
            giasp = a.giasp;
            return *this;
        }
        friend ostream& operator << (ostream& os, cNhanVienSX& a){
            os<<a.ma<<" | "<<a.ht<<" | "<<" | "<<a.ngs<<" | "<<a.ssp<<" | "<<a.giasp<<"\n";
            return os;
        }
        int luongnv(){
            return ssp*giasp;
        }
        int tuoi(){
            return 2026-ngs.gety();
        }
};
class cList{
    private:
        vector<cNhanVienSX> k;
        int n;
    public:
        cList(int n ):n(n){}
        void nhap(){
            for(int i = 0;i<n;i++){
                cNhanVienSX x; cin>>x;
                k.push_back(x);
            }
        }
        void xuat(){
            for(int i = 0;i<n;i++){
                cout<<k[i];
            }
        }
        void nvmin(){
            cNhanVienSX x=k[0];
            for(int i =1;i<n;i++){
                if(x.luongnv()>k[i].luongnv()){
                    x=k[i];
                }
            }
            cout<<"nhan vien co luong thap nhat la: \n";
            cout<<x;
        }
        int tong(){
            int sum = 0;
            for(int i = 0;i<n;i++){
                sum+=k[i].luongnv();
            }
            return sum;
        }
        void maxtuoi(){
            cNhanVienSX x=k[0];
            for(int i =1;i<n;i++){
                if(x.tuoi()<k[i].tuoi()){
                    x=k[i];
                }
            }
            cout<<"nhan vien co tuoi cao nhat la: \n";
            cout<<x;
        }
        void sapxep(){
            for(int i = 0;i<n;i++){
                for(int j = i+1;j<n;j++){
                    if(k[i].luongnv()>k[j].luongnv()){
                        swap(k[i], k[j]);
                    }
                }
            }
        }
};
int main(){
    int n;
    cout<<"nhap so luong nhan vien\n";
    cin>>n;
    cList a(n);
    a.nhap();
    int  k =0;
    a.xuat();
    a.nvmin();
    a.tong();
    a.maxtuoi();
    a.sapxep();
    a.xuat();
    return 0;
}