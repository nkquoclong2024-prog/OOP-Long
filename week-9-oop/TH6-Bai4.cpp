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
            cout<<"NHAP TOA DO DIEM X VA Y VA Z: ";
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
};
class DIEM3C: public Diem2D
{
    private:
        double z;
    public:
        DIEM3C(double x = 0, double y = 0, double z = 0): Diem2D(x,y), z(z){}
        ~DIEM3C(){
        }
        double getz(){ return z;}
        void setz(double zz){ z =zz;}
        void setxyz(double xx, double yy,double zz){
            setx(xx);
            sety(yy);
            z=zz;
        }
        bool Kiemtratrung(DIEM3C& tmp){
            return tmp.getx()==getx() && tmp.gety()==gety() && tmp.z==z; 
        }
        void dichuyen(double a, double b, double c){
            Diem2D::dichuyen(a,b);
            z+=c;
        }
        double khoangcach(DIEM3C& a){
            double x = getx(), y = gety();
            return sqrt(pow(x-a.getx(),2) + pow(y-a.gety(),2) + pow(z-a.z,2));
        }
        DIEM3C timdoixung(){
            return DIEM3C(-getz(), -gety(), -z);
        }
        double cv(DIEM3C& a, DIEM3C&b){
            double c1 = khoangcach(a), c2 = khoangcach(b), c3 = a.khoangcach(b);
            return (c1+c2+c3);
        }
        double dt(DIEM3C& a, DIEM3C&b){
            double c1 = khoangcach(a), c2 = khoangcach(b), c3 = a.khoangcach(b);
            double c = cv(a,b)/2;
            return sqrt(c*(c-c1)*(c-c2)*(c-c3));
        }
        void Nhap(){
            Diem2D::Nhap();
            cin>>z;
            cout<<endl;
        }
        void Xuat() const{
            Diem2D::Xuat();
            cout<<", "<<z<<"\n"; 
        }
        friend istream& operator >> (istream& is, DIEM3C& a){
            a.DIEM3C::Nhap();
            return is;
        }
        friend ostream& operator << (ostream& os, const DIEM3C& a){
            a.DIEM3C::Xuat();
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
class DIEM3CMAU: public DIEM3C, public MAU
{
    public:
        static int diem;
        ~DIEM3CMAU(){
            cout<<"da huy\n";
        }
        DIEM3CMAU(double x = 0, double y = 0, double z = 0, int r = 0, int g = 0, int b = 0): DIEM3C(x,y,z), MAU(r,g,b){};
        bool kiemtratrung(DIEM3CMAU& a){
            return DIEM3C::Kiemtratrung(a) && MAU::kiemtratrung(a);
        }
        friend istream& operator >> (istream& is, DIEM3CMAU& a){
            diem++;
            a.DIEM3C::Nhap();
            a.MAU::Nhap();
            return is;
        }
       friend ostream& operator << (ostream& os, DIEM3CMAU& a){
            cout<<a.getx()<<", "<<a.gety()<<", "<<a.getz()<<", "<<a.getR()<<", "<<a.getG()<<", "<<a.getB()<<endl;
            return os;
        }
};
int DIEM3CMAU::diem = 0;

int main() {
    DIEM3CMAU A, B, C;
    int luachon;

    do {
        cout << "1. Nhap thong tin 3 diem A, B, C" << endl;
        cout << "2. Xuat thong tin 3 diem A, B, C" << endl;
        cout << "3. Kiem tra A va B co trung nhau khong (Toa do & Mau)" << endl;
        cout << "4. Tinh khoang cach giua A va B" << endl;
        cout << "5. Tinh chu vi tam giac ABC" << endl;
        cout << "6. Tinh dien tich tam giac ABC" << endl;
        cout << "7. Di chuyen toa do diem A theo vector (dx, dy, dz)" << endl;
        cout << "8. Thay doi mau sac (RGB) cua diem A" << endl;
        cout << "9. Tim diem doi xung cua A" << endl;
        cout << "10. Hien thi tong so diem tao qua viec nhap tu ban phim" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Moi ban nhap lua chon: ";
        cin >> luachon;

        switch(luachon) {
            case 1:
                cout << "\nNhap diem A\n"; cin >> A;
                cout << "\nNhap diem B\n"; cin >> B;
                cout << "\nNhap diem C\n"; cin >> C;
                break;
            case 2:
                cout << "\nThong tin cac diem dang co:\n";
                cout << "Diem A: " << A;
                cout << "Diem B: " << B;
                cout << "Diem C: " << C;
                break;
            case 3:
                if(A.kiemtratrung(B)) 
                    cout << "Ket qua: Diem A va B HOAN TOAN TRUNG NHAU.\n";
                else 
                    cout << "Ket qua: Diem A va B KHONG trung nhau.\n";
                break;
            case 4:
                cout << "Khoang cach giua A va B: " << A.khoangcach(B) << endl;
                break;
            case 5:
                cout << "Chu vi tam giac tao boi A, B, C: " << A.cv(B, C) << endl;
                break;
            case 6:
                cout << "Dien tich tam giac tao boi A, B, C: " << A.dt(B, C) << endl;
                break;
            case 7:
                double dx, dy, dz;
                cout << "Nhap thong so di chuyen (dx, dy, dz): ";
                cin >> dx >> dy >> dz;
                A.dichuyen(dx, dy, dz);
                cout << "Diem A sau khi di chuyen: " << A;
                break;
            case 8:
                int r, g, b;
                cout << "Nhap bo mau moi cho A (R G B): ";
                cin >> r >> g >> b;
                A.setRGB(r, g, b);
                cout << "Diem A sau khi cap nhat mau: " << A;
                break;
            case 9:
                {
                    DIEM3C dxA = A.timdoixung();
                    cout << "Toa do diem doi xung cua A qua goc toa do la: " << dxA;
                }
                break;
            case 10:
                cout << "Tong so lan nhap diem (bien static): " << DIEM3CMAU::diem << endl;
                break;
            case 0:
                cout << "Dang thoat\n";
                break;
            default:
                cout << "Lua chon khong hop le. Xin vui long chon lai!\n";
        }
    } while(luachon != 0);

    return 0;
}