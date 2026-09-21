#include<iostream>
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
        ~NhanVien(){
            cout<<"DA HUY\n";
        }
        NhanVien(string ms = "", string ht = "", cdmy a = (0,0,0), cdmy b = (0,0,0)): ms(ms), ht(ht), nsh(a), nvl(b){}
        friend istream& operator >> (istream& is, NhanVien& a1){
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
};
int main(){
    NhanVien a;
    cout<<"NHAP SINH VIEN\n";
    cin>>a;
    int k = 2;
    do{
        cout<<"========menu==========\n";
        cout<<"0: NHAP THONG TIN SINH VIEN\n";
        cout<<"1: XUAT THONG TIN SINH VIEN KEM TUOI\n";
        cout<<"2: DE HUY\n";
        cin>>k;
        if(k==0){
            cin.ignore();
            cin>>a;
        } else if(k==1){
            cout<<a;
        }
    } while(k<2);
    return 0;
}