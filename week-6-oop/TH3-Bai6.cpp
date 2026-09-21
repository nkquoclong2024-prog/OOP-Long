#include<iostream>
#include<string>
#include<vector>
using namespace std;
class cCandidate{
    private:
        string ma, name;
        int d,m,y;
        double toan, van, anh;
    public:
        static int sv;
        cCandidate(string ma = "", string name = "", int d = 1, int m = 1, int y = 1, double toan = 0, double van = 0, double anh = 0): ma(ma), name(name), d(d), m(m), y(y), toan(toan), van(van), anh(anh){}
        void nhap(){
            sv++;
            cout<<"nhap sinh vien thu "<<sv<<endl;
            cout<<"nhap ma so: \n";
            getline(cin, ma);
            cout<<"nhap ten: \n";
            getline(cin, name);
            cout<<"nhap ngay thang nam va diem mon toan van anh\n";
            cin>>d>>m>>y>>toan>>van>>anh;
            cin.ignore();
        }
        double tong() const{ 
            return toan + van + anh;
        }
        void xuat() const{
            cout<<ma<<" | "<<name<<" | "<<d<<" | "<<m<<" | "<<y<<" | "<<toan<<" | "<<van<<" | "<<anh<<endl;
        }
        void operator = (const cCandidate& a){
            ma = a.ma;
            name = a.name;
            d = a.d;
            m = a.m;
            y = a.y;
            toan = a.toan;
            van = a.van;
            anh = a.anh;
        }
};
class cListCandidate{
    private:
        int n = 0;
        vector<cCandidate> a;
    public:
        cListCandidate(int n = 0): n(n), a(n){}
        friend istream& operator >> (istream& is, cListCandidate& b){
            for(int i = 0; i < b.n;i++){
                b.a[i].nhap();
            }
            return is;
        } 
        void xdd() const{
            int t = 0;
            for(int i = 0;i<n;i++){
                if(a[i].tong()>15){
                    a[i].xuat();
                    t++;
                }
            }
            if(t==0) cout<<"khong co sinh vien nao tong tren 15\n";
        }
        void max() const{
            if(n==0) return;
            cCandidate temp = a[0];
            for(int i = 0;i<n;i++){
                if(a[i].tong()> temp.tong()){
                    temp = a[i];
                }
            }
            temp.xuat();
        }
        void sort() {
            for(int i = 0;i<n;i++){
                for(int j = i+1;j<n;j++){
                    if(a[i].tong()<a[j].tong()){
                        swap(a[i],a[j]);
                    }
                }
            }
            cout<<"danh sach sau khi sap xep la\n";
            for(int i = 0;i<n;i++){
                a[i].xuat();
            }
        }
};
int cCandidate::sv = 0;
int main(){
    int n;
    cout<<"nhap gia tri cua n la: \n";
    cin>>n;
    cin.ignore();
    cListCandidate temp(n);
    cin>>temp;
    int k;
    do{
        cout<<"chon cac lua chon sau \n";
        cout<<"0: xuat thong tin thi sinh co tong diem lon hon 15\n";
        cout<<"1: cho biet thi sinh nao co diem cao nha\n";
        cout<<"2: sap xep danh sach thi sinh theo thu tu giam dan\n";
        cout<<"cac so khac tu dong huy\n";
        cin>>k;
        if(k==0){
            temp.xdd();
        } else if(k==1){
            temp.max();
        } else if(k==2){
            temp.sort();
        }
    } while(k<3);
    cout<<"da huy\n";
    return 0;
}