#include<iostream>
#include<vector>
#include <ctime>
#include <cstdlib>
#include<math.h>
#include<algorithm>
using namespace std;
class MANG1C{
    private:
        int n;
        int *a;
    public:
        ~MANG1C(){
            n = 0;
            if(a!=nullptr){
                delete[]a;
            }
            cout<<"DAHUY";
        }
        MANG1C(){}
        MANG1C(int n): n(n), a(new int[n]){}
        MANG1C(int n, int m): n(n), a(new int[m]){
            for(int i = 0;i<n;i++){
                a[i]=m;
            }
        }
        bool check(){
            if(n==0) return false;
            else return true;
        }
        void nhap(){
            if(n==0){
                cout<<"nhap so luong phan tu\n";
                cin>>n;
                a = new int[n];
            } 
            cout<<"nhap cac phan tu cua mang\n";
            for(int i = 0;i<n;i++){
                cin>>a[i];
            }
        }
        void psmang(int mi, int ma){
            cout<<"nhap so gia tri trong mang\n";
            cin>>n;
            a = new int[n];
            for(int  i =0;i<n;i++){
                a[i]= mi + rand()%(ma-mi+1);
            }
        }
        MANG1C& operator == (MANG1C& b){
            n=b.n;
            delete [] a;
            a = new int [n];
            for(int i = 0;i<n;i++){
                a[i]=b.a[i];
            }
            return *this;
        }
        void xuat() const{
            cout<<"cac gia tri cua mang la\n";
            for(int i = 0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        friend istream& operator >> (istream& is, MANG1C& a){
            a.nhap();
            return is;
        }
        friend ostream& operator << (ostream& os, MANG1C& a){
            a.xuat();
            return os;
        }
        void SetN(int n){
            vector<int> tmp;
            for(int i = 0;i<this->n;i++){
                tmp.push_back(a[i]);
            }
            this->n=n;
            delete [] a;
            a = new int[n];
            for(int i = 0;i<tmp.size();i++){
                a[i]=tmp[i];
            }
        }
        bool kt(int x){
            if(x<2) return false;
            for(int j = 2;j<x;j++){
                    if(x%j==0) return false;
            }
            return true;
        }
        void songt(){
            cout<<"mang co cac so nguyen to la\n";
            for(int i = 0;i<n;i++){
                if(kt(a[i])) cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        void socp(){
            int k = 0;
            for(int i = 0;i<n;i++){
                if(abs(sqrt(a[i])-round(sqrt(a[i])))<0.00000001) k++;
            }
            cout<<"so luong so chinh phuong la: "<<k<<endl;
        }
        void tongsohoanthien(){
            int sum = 0;
            for(int  i =0;i<n;i++){
                int tmp = 0;
                for(int j = 1;j<a[i];j++){
                    if(a[i]%j==0) tmp+=j; 
                }
                if(tmp==a[i]) sum+=a[i];
            }
            cout<<"tong cua cac so hoan hao la: "<<sum<<endl;
        }
        void tbcongsodoixung(){
            int tb = 0, sl = 0;
            for(int  i =0;i<n;i++){
                int tmp = a[i], t = 0;
                while(tmp!=0){
                    t=t*10+tmp%10;
                    tmp = tmp/10;
                }
                if(t==a[i]){
                    sl++;
                    tb+=a[i];
                }
            }
            cout<<"trung binh cong so doi xung la: "<<tb/sl<<endl;
        }
        void ktcophantule(){
            for(int i = 0;i<n;i++){
                if(a[i]%2!=0){
                    cout<<"mang co phan tu le\n";
                    return;
                }
            }
            cout<<"mang ko co phan tu le\n";
        }
        void phantuchanbenhat(){
            int tim = INT_MAX;
            for(int i = 0;i<n;i++){
                if(a[i]%2==0){
                    if(tim>a[i]){
                        tim=a[i];
                    }
                }
            }
            if(tim!=INT_MAX){
                cout<<tim<<" la phan tu chan nho nhat\n";
            } else cout<<"khong co phan tu chan\n";
        }
        void sapxepmang(){
            sort(a, a+n);
        }
        void xoaphantu(int vt){
            vector<int> b;
            for(int i = 0;i<n;i++){
                if(i!=vt) b.push_back(a[i]);
            }
            n--;
            delete[] a;
            a = new int[n];
            for(int i = 0;i<n;i++){
                a[i]= b[i];
            }
        }
        void themphantu(int gt, int vt){
            vector<int> b;
            for(int i = 0;i<n;i++){
                if(i==vt) b.push_back(gt);
                b.push_back(a[i]);
            }
            n++;
            delete[] a;
            a = new int[n];
            for(int i = 0;i<n;i++){
                a[i]= b[i];
            }
        }
        void capnhatgiatri(int gt, int vt){
            a[vt]=gt;
        }
        void timkiemtuyentinh(int gt){
            for(int i = 0;i<n;i++){
                if(a[i]==gt){
                    cout<<"gia tri do o vi tri"<<i<<endl;
                    return;
                }
            }
            cout<<"khong tim thay\n";
        }
        void timkiemnhiphan(int gt){
            cout<<"khi tim kiem nhi phan phai sap xep mang\n";
            sapxepmang();
            int l = 0, r = n-1;
            while(l<=r){
                int mid = (l+r)/2;
                if(gt==a[mid]){
                    cout<<"gia tri do o vi tri"<<mid<<endl;
                    return;
                }
                if(gt>a[mid]){
                    l=mid+1;
                } else{
                    r = mid-1;
                }
            }
            cout<<"khong tim thay\n";
        }
};
int main(){
    srand(time(nullptr));
    MANG1C a;
    int k = 0;
    do{
        cout<<"1: nhap mang\n";
        cout<<"2: phat sinh mang\n";
        cout<<"3: xuat mang\n";
        cout<<"4: cap nhat so phan tu mang\n";
        cout<<"5: liet ke cac phan tu la SNT \n";
        cout<<"6: dem so luong cac phan tu la SCP\n";
        cout<<"7: tinh tong cac phan tu la SHT\n";
        cout<<"8: tinh TB cong gia tri cac phan tu la SDX\n";
        cout<<"9: kiem tra mang toan phan tu le\n";
        cout<<"10: tim phan tu chan be nhat\n";
        cout<<"11: sap xep mang tang dan\n";
        cout<<"12: xoa phan tu tai vi tri\n";
        cout<<"13: them phan tu tai vi tri\n";
        cout<<"14: xoa mang\n";
        cout<<"15: cap nhat gia tri phan tu tai vi tri\n";
        cout<<"16: tim kiem tuyen tinh\n";
        cout<<"17: tim kiem nhi phan\n";
        cout<<"0: thoat CT\n";
        cin>>k;
        switch(k) {
            case 1:
                cin >> a;
                break;
            case 2: {
                int mi, ma;
                cout << "Nhap khoang min va max de phat sinh: ";
                cin >> mi >> ma;
                a.psmang(mi, ma);
                break;
            }
            case 3:
                if(!a.check()) cout << "Mang dang rong!\n";
                else cout << a;
                break;
            case 4: {
                int sl;
                cout << "Nhap so luong phan tu moi: ";
                cin >> sl;
                a.SetN(sl);
                break;
            }
            case 5:
                a.songt();
                break;
            case 6:
                a.socp();
                break;
            case 7:
                a.tongsohoanthien();
                break;
            case 8:
                a.tbcongsodoixung();
                break;
            case 9:
                a.ktcophantule();
                break;
            case 10:
                a.phantuchanbenhat();
                break;
            case 11:
                a.sapxepmang();
                cout << "Da sap xep mang tang dan.\n";
                break;
            case 12: {
                int vt;
                cout << "Nhap vi tri can xoa: ";
                cin >> vt;
                a.xoaphantu(vt);
                break;
            }
            case 13: {
                int gt, vt;
                cout << "Nhap gia tri va vi tri can them: ";
                cin >> gt >> vt;
                a.themphantu(gt, vt);
                break;
            }
            case 14:
                a.SetN(0); 
                cout << "Da xoa toan bo mang.\n";
                break;
            case 15: {
                int gt, vt;
                cout << "Nhap vi tri va gia tri moi: ";
                cin >> vt >> gt; 
                a.capnhatgiatri(gt, vt);
                break;
            }
            case 16: {
                int gt;
                cout << "Nhap gia tri can tim: ";
                cin >> gt;
                a.timkiemtuyentinh(gt);
                break;
            }
            case 17: {
                int gt;
                cout << "Nhap gia tri can tim: ";
                cin >> gt;
                a.timkiemnhiphan(gt);
                break;
            }
            case 0:
                cout << "Dang thoat chuong trinh...\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai!\n";
                break;
        }
    }while(k!=0);
    return 0;
}