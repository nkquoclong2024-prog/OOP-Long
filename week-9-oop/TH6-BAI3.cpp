#include<iostream>
#include<math.h>
using namespace std;
class Diem2D
{
    private:
        double x,y;
    public:
        Diem2D(double x = 0, double y = 0): x(x), y(y){}
        void Nhap(){
            cout<<"NHAP TOA DO DIEM X VA Y: ";
            cin>>x>>y;
        }
        void Xuat() const { 
            cout<<"DIEM: "<<x<<", "<<y;
        }
        double getx(){ return x;}
        double gety(){ return y;}
        void setx(double xx){x=xx;}
        void sety(double yy){y=yy;}
        void dichuyen(double x, double y){
            this->x+=x;
            this->y+=y;
        }
        bool kttrung(Diem2D k){
            return (x==k.getx() && y==k.gety());
        }
        double kc(Diem2D k){
            double k1 = (k.x-x)*(k.x-x)+(k.y-y)*(k.y-y);
            return sqrt(k1);
        }
        Diem2D dx(){
            return Diem2D (-x + 0,-y + 0); 
        }
        double cv(Diem2D yy, Diem2D zz){
            double c1 = kc(yy), c2 = kc(zz), c3 = yy.kc(zz);
            return c1+c2+c3;
        }
        double dt(Diem2D yy, Diem2D zz){
            double c1 = kc(yy), c2 = kc(zz), c3 = yy.kc(zz);
            double ncv = cv(yy,zz)/2;
            double kq=ncv*(ncv-c1)*(ncv-c2)*(ncv-c3);
            return sqrt(kq);
        }
        friend istream& operator >> (istream& is, Diem2D& a){
            a.Diem2D::Nhap();
            return is;
        }
        friend ostream& operator << (ostream& os, const Diem2D& a){
            a.Diem2D::Xuat();
            return os;
        }
};
class MAU
{
    private:
        int r,g,b;
    public:
        MAU(int r = 0, int g = 0, int b =0): r(r), g(g), b(b){}
        ~MAU(){
        }
        void setR(int r){ 
            if(r>255) r=255;
            if(r<0) r = 0;
            this->r = r;
        }
        void setG(int g){ 
            if(g>255) g=255;
            if(g<0) g = 0;
            this->g = g;
        }
        void setB(int b){ 
            if(b>255) b=255;
            if(b<0) b = 0;
            this->b = b;
        }
        void setRGB(int x, int y, int z){
            r = x; g = y; b = z;
        }
        int getR(){return r;}
        int getG(){return g;}
        int getB(){return b;}
        bool kiemtratrung(MAU& a){
            return (a.r==r && a.g==g && a.b==b);
        }
        void Nhap(){
            cout<<"nhap 3 so RGB la: \n";
            cin>>r>>g>>b;
            while(r>255 || r<0){
                cout<<"nhap lai R [0,255]\n";
                cin>>r;
            }
            while(g>255 || g<0){
                cout<<"nhap lai G [0,255]\n";
                cin>>g;
            }
            while(b>255 || b<0){
                cout<<"nhap lai B [0,255]\n";
                cin>>b;
            }
        }
        friend istream& operator >> (istream& is, MAU& a){
            a.Nhap();
            return is;
        }
        friend ostream& operator << (ostream& os, const MAU& a){
            cout<<"RGB la: "<<a.r<<", "<<a.g<<", "<<a.b<<"\n";
            return os;
        }
};
class DIEM2CMAU: public Diem2D, public MAU
{
    public:
        static int diem;
        ~DIEM2CMAU(){
            cout<<"da huy\n";
        }
        DIEM2CMAU(double x = 0, double y = 0, double z = 0, int r = 0, int g = 0, int b = 0): Diem2D(x,y), MAU(r,g,b){};
        bool kiemtratrung(DIEM2CMAU& a){
            return Diem2D::kttrung(a) && MAU::kiemtratrung(a);
        }
        friend istream& operator >> (istream& is, DIEM2CMAU& a){
            diem++;
            a.Diem2D::Nhap();
            a.MAU::Nhap();
            return is;
        }
       friend ostream& operator << (ostream& os, DIEM2CMAU& a){
            cout<<a.getx()<<", "<<a.gety()<<", "<<a.getR()<<", "<<a.getG()<<", "<<a.getB()<<endl;
            return os;
        }
};
int DIEM2CMAU::diem = 0;

int main() {
    DIEM2CMAU A, B, C;
    int luaChon;
    do {
        cout << "1. Nhap thong tin 3 diem A, B, C" << endl;
        cout << "2. Xuat thong tin 3 diem A, B, C" << endl;
        cout << "3. Kiem tra diem A va B co trung nhau khong (Toa do & Mau)" << endl;
        cout << "4. Tinh khoang cach giua A va B" << endl;
        cout << "5. Tinh chu vi tam giac tao boi A, B, C" << endl;
        cout << "6. Tinh dien tich tam giac tao boi A, B, C" << endl;
        cout << "7. Di chuyen toa do diem A theo vector (dx, dy)" << endl;
        cout << "8. Thay doi mau sac (RGB) cua diem A" << endl;
        cout << "9. Tim diem doi xung cua diem A qua goc toa do" << endl;
        cout << "10. Hien thi tong so lan nhap" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch(luaChon) {
            case 1:
                cout << "\nNhap thong tin diem A\n"; cin >> A;
                cout << "\nNhap thong tin diem B\n"; cin >> B;
                cout << "\nNhap thong tin diem C\n"; cin >> C;
                break;
            case 2:
                cout << "\nDiem A:" << A;
                cout << "Diem B:" << B;
                cout << "Diem C:" << C;
                break;
            case 3:
                if(A.kiemtratrung(B)) 
                    cout << "Ket qua: Diem A va B HOAN TOAN TRUNG NHAU.\n";
                else 
                    cout << "Ket qua: Diem A va B KHONG trung nhau.\n";
                break;
            case 4:
                cout << "Khoang cach giua A va B la: " << A.kc(B) << endl;
                break;
            case 5:
                cout << "Chu vi tam giac ABC la: " << A.cv(B, C) << endl;
                break;
            case 6:
                cout << "Dien tich tam giac ABC la: " << A.dt(B, C) << endl;
                break;
            case 7:
                double dx, dy;
                cout << "Nhap thong so di chuyen (dx, dy): ";
                cin >> dx >> dy;
                A.dichuyen(dx, dy);
                cout << "Diem A sau khi di chuyen: \n" << A;
                break;
            case 8:
                int r, g, b;
                cout << "Nhap ma mau moi cho diem A (R G B): ";
                cin >> r >> g >> b;
                A.setRGB(r, g, b);
                cout << "Diem A sau khi doi mau: \n" << A;
                break;
            case 9:
                {
                    Diem2D doiXungA = A.dx();
                    cout << "Toa do diem doi xung cua A la: " << doiXungA << endl;
                }
                break;
            case 10:
                cout << "Tong so lan da nhap diem la: " << DIEM2CMAU::diem << endl;
                break;
            case 0:
                cout << "Dang thoat\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai!\n";
        }
    } while(luaChon != 0);

    return 0;
}