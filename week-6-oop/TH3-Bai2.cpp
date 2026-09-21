#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

class cDiem {
public:
    double x, y;
    cDiem(double x = 0, double y = 0) : x(x), y(y) {}
    friend istream& operator >> (istream& is, cDiem& a){
        is>>a.x>>a.y;
        return is;
    }
    friend ostream& operator << (ostream& os, cDiem& a){
        os<< "(" << a.x << ", " << a.y << ")";
        return os;
    }
    float khoangCach(cDiem d) {
        return sqrt((x - d.x) * (x - d.x) + (y - d.y) * (y - d.y));
    }
    void tinhTien(double dx, double dy) {
        x += dx;
        y += dy;
    }
    void quay(double gocRad) {
        double x_new = x * cos(gocRad) - y * sin(gocRad);
        double y_new = x * sin(gocRad) + y * cos(gocRad);
        x = x_new;
        y = y_new;
    }
    void thuPhong(double k) {
        x *= k;
        y *= k;
    }
};

class cDaGiac {
private:
    int n;          
    cDiem *dinh;    

public:
    cDaGiac() {
        n = 0;
        dinh = nullptr;
    }
    ~cDaGiac() {
        if (dinh != nullptr) {
            delete[] dinh;
        }
        cout<<"DA HUY\n";
    }
    void nhap() {
        do {
            cout << "Nhap so luong dinh cua da giac (n >= 3): ";
            cin >> n;
        } while (n < 3);

        if (dinh != nullptr) {
            delete[] dinh;
        }
        dinh = new cDiem[n];

        for (int i = 0; i < n; i++) {
            cout << "Nhap toa do dinh thu " << i + 1 << " (x y): ";
            cin>>dinh[i];
        }
    }
    void xuat() {
        for (int i = 0; i < n; i++) {
            cout<<dinh[i];
            if (i < n - 1) cout << " -> ";
        }
        cout << endl;
    }
    double tinhChuVi() {
        double chuVi = 0;
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n; 
            chuVi += dinh[i].khoangCach(dinh[next]);
        }
        return chuVi;
    }
    double tinhDienTich() {
        double dienTich = 0;
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            dienTich += (dinh[i].x * dinh[next].y - dinh[next].x * dinh[i].y);
        }
        return abs(dienTich) / 2.0;
    }
    void tinhTien(double dx, double dy) {
        for (int i = 0; i < n; i++) {
            dinh[i].tinhTien(dx, dy);
        }
    }
    void quay(double gocRad) {
        for (int i = 0; i < n; i++) {
            dinh[i].quay(gocRad);
        }
    }
    void thuPhong(double k) {
        for (int i = 0; i < n; i++) {
            dinh[i].thuPhong(k);
        }
    }
};

int main() {
    cDaGiac dg;
    cout << "NHAP THONG TIN DA GIAC\n";
    dg.nhap();
    int k = 10;
    do{
        cout<<"0: xuat cac dinh\n";
        cout<<"1: chu vi cua da giac\n";
        cout<<"2: dien tich cua da giac\n";
        cout<<"3: tinh tien\n";
        cout<<"4: quay 90 do\n";
        cout<<"5: thu phong\n";
        cin>>k;
        if(k==0){
            cout << "Cac dinh: ";
            dg.xuat();
        } else if(k==1){
            cout << "Chu vi: " << dg.tinhChuVi() << endl;
        } else if(k==2){
            cout << "Dien tich: " << dg.tinhDienTich() << endl;
        } else if(k==3){
            cout<<"nhap 2 gia tri tinh tien\n";
            double x,y; cin>>x>>y;
            dg.tinhTien(x, y);
        } else if(k==4){
            dg.quay(PI / 2);
        } else if(k==5){
            cout<<"nhap vao gia tri cua x\n";
            double x; cin>>x;
            dg.thuPhong(x);
        }
    }while(k<6);
    return 0;
}