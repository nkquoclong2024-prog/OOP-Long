#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;

class MATRAN{
private:  
    int sd,sc;
    int **p;
public: 
    ~MATRAN(){
            if(sd > 0 || sc > 0 ){
                for(int i=0;i<sd;i++)
                    delete []p[i];
            }
            delete []p;
            p=nullptr;
            cout << "Da huy MATRAN\n";
    }
    MATRAN():sd(0),sc(0),p(nullptr){}
    MATRAN(int d, int c):sd(d),sc(c),p(new int *[sd]){
        for(int i=0;i<sd;i++)
             p[i]= new int[sc];
    }
    MATRAN(const MATRAN &other){
        this->sd=other.sd;
        this->sc=other.sc;  
        p = new int*[sd];
        for(int i=0;i<sd;i++){
            p[i]= new int[sc];
            for(int j=0;j<sc;j++)
            p[i][j]=other.p[i][j];
        }
    }
    MATRAN& operator = (const MATRAN &other){
        if(this == &other ) return *this;
        if(this->sd > 0 || this->sc > 0){
            for(int i=0;i<sd;i++)
                delete []p[i];
        }
        delete []p;
        this->sd=other.sd;
        this->sc=other.sc;  
        p = new int*[sd];
        for(int i=0;i<sd;i++){
            p[i]= new int[sc];
            for(int j=0;j<sc;j++)
            p[i][j]=other.p[i][j];
        }
        return *this;
    }
    int getsd(){ return sd; }
    int getsc() { return sc; }
    int getPIJ(int i, int j){
        if(p==nullptr) return -1;
        if(i>=sd && j >=sc)
            return -1;
        return p[i][j];
    }
    friend istream& operator >> (istream &is, MATRAN& a){
        is >> a.sd >> a.sc;
        a.p = new int*[a.sd];
        for(int i=0;i<a.sd;i++){
            a.p[i]= new int[a.sc];
            for(int j=0;j<a.sc;j++)
                is >> a.p[i][j];
        }
        return is;
    }
    friend ostream& operator << (ostream &os, const MATRAN&a){
        os  << "So dong : " << a.sd << endl;
        os  << "So cot : " << a.sc << endl;
        for(int i=0;i<a.sd;i++){
            for(int j=0;j<a.sc;j++)
                os <<  a.p[i][j]<<" ";
            cout << endl;
        }
        return os;
    }
    void PhatSinh(int mi,int ma){
        srand(time(nullptr));
        for(int i=0;i<sd;i++)
            for(int j=0;j<sc;j++)
                p[i][j] = rand() % (ma-mi+1)+mi;
    }
    void LietKeSNT(){
        bool snt = false;
        for(int i=0;i<sd;i++)
            for(int j=0;j<sc;j++){
                if (p[i][j] < 2) continue;
                bool flag = true;
                for(int k = 2; k <= sqrt(p[i][j] ); k++) {
                    if(p[i][j]  % k == 0) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    cout << p[i][j]  << " ";
                    snt = true;
                }
        }
        if (!snt) cout << "Khong co";
        cout << endl;
    }
    int SoLuongSoChinhPhuong(){
        int res = 0;
        for(int i = 0; i < sd; i++)
        for(int j=0;j<sc;j++){
                if (p[i][j] > 0) {
                int x = sqrt(p[i][j]);
                if(p[i][j] == x * x) res++;
                }
            } 
        return res;
    }
    int TongSoHoanThienTrenDongK(int k){
        int res = 0;
        for(int i=0;i<sc;i++){
            if(p[k][i] < 6) continue;
            int tong = 0;
            for(int j = 1; j <= p[k][i]/2; j++){
                if(p[k][i] % j == 0) tong += j;
            }   
            if(tong == p[k][i]) res += p[k][i]; 
        }
        return res;
    }
    int TBCongSoDoiXungTrenCotK(int k){
        double res = 0;
        double dem = 0;
        for(int i=0;i<sd;i++){
            int temp = abs(p[i][k]); 
            int SDX = 0;
            while(temp > 0){
                SDX = SDX * 10 + temp % 10;
                temp /= 10;
            }
            if(SDX == abs(p[i][k])){
                res += p[i][k];
                dem++;
            }
        }   
        if(dem==0){
            return res;
        }
        return res/dem;
    }
    void SapXepGiamDanMaTran(){
        int k = sd * sc; 
        for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (p[i / sc][i % sc] < p[j / sc][j % sc]) {
                swap(p[i / sc][i % sc] , p[j / sc][j % sc]);
            }
        }
    }
    }
    void SapXepTangDanMaTranTheoDongK(int k){
        if(p!=nullptr){
            sort(p[k],p[k]+sc);
        }
    }

};int main() {
    int chon;
    MATRAN mt;
    int d, c, k, mi, ma;

    do {
        cout << "\n====================== MENU ======================\n";
        cout << "1. Nhap ma tran" << endl;
        cout << "2. Phat sinh ma tran ngau nhien" << endl;
        cout << "3. Xuat ma tran" << endl;
        cout << "4. Liet ke cac so nguyen to trong ma tran" << endl;
        cout << "5. Dem so luong so chinh phuong" << endl;
        cout << "6. Tinh tong so hoan thien tren dong K" << endl;
        cout << "7. Tinh trung binh cong so doi xung tren cot K" << endl;
        cout << "8. Sap xep ma tran giam dan (toan bo)" << endl;
        cout << "9. Sap xep dong K tang dan" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "==================================================\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> chon;
        switch (chon) {
            case 1:
                cout << "Nhap so dong va so cot, sau do nhap cac phan tu:\n";
                cin >> mt;
                break;

            case 2:
                cout << "Nhap so dong: "; cin >> d;
                cout << "Nhap so cot: "; cin >> c;
                cout << "Nhap khoang gia tri (min max): "; cin >> mi >> ma;
                mt = MATRAN(d, c);
                mt.PhatSinh(mi, ma);
                cout << "Da phat sinh ma tran ngau nhien.\n";
                break;

            case 3:
                cout << "\nMa tran hien tai:\n" << mt;
                break;

            case 4:
                cout << "Cac so nguyen to co trong ma tran: ";
                mt.LietKeSNT();
                break;

            case 5:
                cout << "So luong so chinh phuong: " << mt.SoLuongSoChinhPhuong() << endl;
                break;

            case 6:
                cout << "Nhap dong K can tinh: "; cin >> k;
                if (k >= 0 && k < mt.getsd()) {
                    cout << "Tong so hoan thien tren dong " << k << " la: " << mt.TongSoHoanThienTrenDongK(k) << endl;
                } else {
                    cout << "Dong khong hop le!\n";
                }
                break;

            case 7:
                cout << "Nhap cot K can tinh: "; cin >> k;
                if (k >= 0 && k < mt.getsc()) {
                    cout << "TBC so doi xung tren cot " << k << " la: " << mt.TBCongSoDoiXungTrenCotK(k) << endl;
                } else {
                    cout << "Cot khong hop le!\n";
                }
                break;

            case 8:
                mt.SapXepGiamDanMaTran();
                cout << "Da sap xep ma tran giam dan.\n";
                break;

            case 9:
                cout << "Nhap dong K can sap xep: "; cin >> k;
                if (k >= 0 && k < mt.getsd()) {
                    mt.SapXepTangDanMaTranTheoDongK(k);
                    cout << "Da sap xep dong " << k << " tang dan.\n";
                } else {
                    cout << "Dong khong hop le!\n";
                }
                break;

            case 0:
                break;

            default:
                cout << "Lua chon khong hop le. Vui long nhap lai!\n";
        }
    } while (chon != 0);

    return 0;
}