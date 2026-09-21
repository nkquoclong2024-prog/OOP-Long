#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
class MTVUONG{
    private:
        int n;
        int **p;
    public:
        ~MTVUONG(){
            n = 0;
            for(int i=0; i<n; i++)
                delete[] p[i];
            cout<<"DA HUY";
        }
        MTVUONG(): n(0) {}
        MTVUONG(int n): n(n), p(new int*[n])
        {
            for(int i=0; i<n; i++)
                p[i] = new int[n];
        }
        MTVUONG& operator = (const MTVUONG& a){
            n = a.n;
            for(int i=0; i<n; i++)
                delete[] p[i];
            p = new int*[n];
            for(int i = 0;i<n; i++){
                p[i] = new int[n];
                for(int j = 0;j<n;j++){
                    p[i][j] = a.p[i][j];
                }
            }
            return *this;
        }
        int getN(){ return n;}
        int getPIJ(int i, int j){
            if(i>=n || j>=n){
                return -1;
            }
            else return p[i][j];
        } 
        void setPIJ(int i, int j, int x){
            p[i][j]=x;
        }  
        friend istream& operator >> (istream& is, MTVUONG& a){
            cout<<"nhap cap cua ma tran\n";
            is>>a.n;
            a.p=new int*[a.n];
            cout<<"nhap du "<<a.n*a.n<<" phan tu\n";
            for(int i =0;i<a.n;i++){
                a.p[i]=new int[a.n];
                for(int j = 0;j<a.n;j++){
                    is>>a.p[i][j];
                }
            }
            return is;
        }
        friend ostream& operator << (ostream& os, const MTVUONG& a){
            os<<"ma tran "<<a.n*a.n<<" phan tu\n";
            for(int i =0;i<a.n;i++){
                for(int j = 0;j<a.n;j++){
                    os<<a.p[i][j]<<" ";
                }
                os<<endl;
            }
            return os;
        }
        void phatsinhmatrantudo(int n, int mi, int ma){
            this->n=n;
            p = new int*[n];
            for(int i = 0;i<n;i++){
                p[i] = new int[n];
                for(int j = 0;j<n;j++){
                    p[i][j]=mi+ rand()%ma-mi+1;
                }
            }
        }
        void lietkecacphantulenamtrenduongcheocuamatran(){
            cout<<"cac phan tu le nam tren duong cheo cua ma tran la: \n";
            for(int i = 0;i<n;i++){
                if(p[i][i]%2!=0) cout<<p[i][i]<<" ";
            }
            cout<<endl;
        }
        void diemsoluongphantucokytucuoila3namtrenduongcheophu(){
            int dem = 0;
            for(int i = 0;i<n;i++){
                if(p[i][n-i-1]%10==3) dem++;
            }
            cout<<"so luong phan tu nam tren duong cheo phu co ky tu cuoi la 3 la: "<<dem<<endl;
        }
        void ktcophantuamnaotrenduongcheochinh(){
            for(int i = 0;i<n;i++){
                for(int j = i+1;j<n;j++){
                    if(p[i][j]<0){
                        cout<<"co phan tu am\n";
                        return;
                    }
                }
            }
            cout<<"khong co phan tu am\n";
        }
        void phantuchandautienoduoiduongcheophula(){
            for(int  i = 0;i<n;i++){
                for(int j = n-i;j<n;j++){
                    if(p[i][j]%2==0){
                        cout<<"phan tu chan dau tien la: "<<p[i][j]<<endl;
                        return;
                    }
                }
            }
            cout<<"khong co phan tu chan nao het\n";
        }
        void sapxepgiamdancacphantutrenduongcheophucuamatran(){
            for(int i = 0;i<n;i++){
                for(int j = 1;j<n-i-1;j++){
                    int k = j - 1, k1 = p[i][j];
                    while(k>=0 &&  k1>p[i][k]){
                        p[i][k+1]=p[i][k];
                        k--;
                    }
                    p[i][k+1]=k1;
                }
            }
        }
};
int main(){
    srand(time(NULL));
    MTVUONG mt;
    int choice;

    do {
        cout << "\n====================== MENU ======================\n";
        cout << "1. Nhap ma tran bang tay (Toan tu >>)\n";
        cout << "2. Phat sinh ma tran ngau nhien\n";
        cout << "3. Xuat ma tran (Toan tu <<)\n";
        cout << "4. Kiem tra ham setPIJ, getPIJ va getN\n";
        cout << "5. Liet ke cac phan tu le tren duong cheo chinh\n";
        cout << "6. Dem phan tu co chu so cuoi la 3 tren duong cheo phu\n";
        cout << "7. Kiem tra co phan tu am nao o tam giac tren hay khong\n";
        cout << "8. Tim phan tu chan dau tien duoi duong cheo phu\n";
        cout << "9. Chay ham sap xep (sap xep theo hang)\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "==================================================\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin >> mt;
                break;
            }
            case 2: {
                int n, mi, ma;
                cout << "Nhap cap cua ma tran: "; cin >> n;
                cout << "Nhap gia tri min: "; cin >> mi;
                cout << "Nhap gia tri max: "; cin >> ma;
                mt.phatsinhmatrantudo(n, mi, ma);
                cout << "-> Da tao ma tran ngau nhien!\n";
                break;
            }
            case 3: {
                if (mt.getN() == 0) {
                    cout << " Ma tran dang trong!\n";
                } else {
                    cout << mt;
                }
                break;
            }
            case 4: {
                if (mt.getN() == 0) {
                    cout << "Ma tran dang trong, chua the thao tac!\n";
                    break;
                }
                int r, c, val;
                cout << "Cap ma tran hien tai: " << mt.getN() << "\n";
                cout << "Nhap chi so dong i va cot j can xem: "; 
                cin >> r >> c;
                cout << "Gia tri tai p[" << r << "][" << c << "] la: " << mt.getPIJ(r, c) << "\n";
                cin >> val;
                mt.setPIJ(r, c, val);
                cout << "Da cap nhat gia tri moi!\n";
                break;
            }
            case 5: {
                mt.lietkecacphantulenamtrenduongcheocuamatran();
                break;
            }
            case 6: {
                mt.diemsoluongphantucokytucuoila3namtrenduongcheophu();
                break;
            }
            case 7: {
                mt.ktcophantuamnaotrenduongcheochinh();
                break;
            }
            case 8: {
                mt.phantuchandautienoduoiduongcheophula();
                break;
            }
            case 9: {
                mt.sapxepgiamdancacphantutrenduongcheophucuamatran();
                cout << "Da thuc hien sap xep!\n";
                break;
            }
            case 0: {
                cout << "Tam biet!\n";
                break;
            }
            default: {
                cout << "Lua chon khong hop le. Vui long nhap lai!\n";
                break;
            }
        }
    } while (choice != 0);

    return 0;
}
