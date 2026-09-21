#include<iostream>
#include<vector>
using namespace std;
class cdmy{
    private:
        int d, m, y;
    public:
        cdmy(int x = 0, int y = 0, int z = 0): d(x), m(y), y(z){}
        friend istream& operator >> (istream& is, cdmy& a){
            is>>a.d>>a.m>>a.y;
            return is;
        } 
        friend ostream& operator << (ostream& os, cdmy& a){
            os<<a.d<<" / "<<a.m<<" / "<<a.y;
            return os;
        }
        double tuoi(){
            return (2026-y);
        }
};
class NhanVien{
    private:
        string ms, ht;
        cdmy nsh, nvl;
    public:
        static int n;
        ~NhanVien(){
            cout<<"DA HUY\n";
        }
        NhanVien(string ms = "", string ht = "", cdmy a = (0,0,0), cdmy b = (0,0,0)): ms(ms), ht(ht), nsh(a), nvl(b){}
        friend istream& operator >> (istream& is, NhanVien& a1){
            n++;
            cout<<"NHAP MA SO\n";
            getline(is, a1.ms);
            cout<<"NHAP HO TEN\n";
            getline(is, a1.ht);
            cout<<"NHAP NGAY THANG NAM SINH\n";
            is>>a1.nsh;
            cout<<"NHAP NGAY THANG NAM LAM\n";
            is>>a1.nvl;
            return is;
        }
        friend ostream& operator << (ostream& os, NhanVien& a1){
            os<<a1.ms<<" | "<<a1.ht<<" | "<<a1.nsh<<" | "<<a1.nvl<<" | "<<a1.nsh.tuoi()<<endl; 
            return os;
        }
        double sonamlam(){
            return nvl.tuoi();
        }
};
int NhanVien::n=0;
class cListsv{
    private:
        vector<NhanVien> a;
    public:
        cListsv(NhanVien x){
            a.push_back(x);
        }
        void nhap(){
            cin.ignore();
            NhanVien x;
            cin>>x; 
            a.push_back(x);
        }
        void xuat(int x){
            cout<<a[x];
        }
        void lvt5(int n){
            for(int i= 0;i<n;i++){
                if(a[i].sonamlam()>5){
                    cout<<a[i];
                }
            }
        }
};
int main(){
    cout<<"NHAP SINH VIEN\n";
    NhanVien x; cin>>x;
    cListsv a(x);
    int k = 4;
    do{
        cout<<"========menu==========\n";
        cout<<"0: NHAP THEM THONG TIN SINH VIEN MOI\n";
        cout<<"1: XUAT THONG TIN SINH VIEN KEM TUOI BAT KI\n";
        cout<<"2: IN RA CAC NHAN VIEN DA LAM VIEC TREN 5 NAM\n";
        cout<<"3: DE HUY\n";
        cin>>k;
        if(k==0){
            a.nhap();
        } else if(k==1){
            a.xuat(0);
        } else if(k==2){
            a.lvt5(NhanVien::n);
        }
    } while(k<3);
    return 0;
}