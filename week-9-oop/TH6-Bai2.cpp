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
        ~DIEM3C(){}
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
class DIEMMAU3C: public DIEM3C
{
    private:
        int r,g,b;
    public:
        DIEMMAU3C(double x = 0, double y = 0, double z = 0, int r = 0, int g = 0, int b =0): DIEM3C(x,y,z), r(r), g(g), b(b){}
        ~DIEMMAU3C(){
            cout<<"da huy\n";
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
            setR(x); setG(y); setB(z);
        }
        int getR(){return r;}
        int getG(){return g;}
        int getB(){return b;}
        bool kiemtratrung(DIEMMAU3C& a){
            return (a.getx()==getx() && a.gety()==gety() && a.getz()==getz() && a.r==r && a.g==g && a.b==b);
        }
        void Nhap(){
            DIEM3C::Nhap();
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
        friend istream& operator >> (istream& is, DIEMMAU3C& a){
            a.DIEMMAU3C::Nhap();
            return is;
        }
        friend ostream& operator << (ostream& os, const DIEMMAU3C& a){
            a.DIEM3C::Xuat();
            cout<<"RGB la: "<<a.r<<", "<<a.g<<", "<<a.b<<"\n";
            return os;
        }
};
int main() {
    DIEMMAU3C A, B, C;
    int choice;
    do {
        cout << "1. Nhap toa do va mau sac 3 diem A, B, C" << endl;
        cout << "2. Xuat thong tin 3 diem" << endl;
        cout << "3. Kiem tra diem A va B co trung nhau (ca toa do & mau)" << endl;
        cout << "4. Tinh khoang cach giua A va B" << endl;
        cout << "5. Tinh chu vi tam giac ABC" << endl;
        cout << "6. Tinh dien tich tam giac ABC" << endl;
        cout << "7. Doi mau diem A (Set RGB)" << endl;
        cout << "8. Di chuyen toa do diem A" << endl;
        cout << "0. Thoat" << endl;
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\nNHAP DIEM A\n"; cin >> A;
                cout << "\nNHAP DIEM B \n"; cin >> B;
                cout << "\nNHAP DIEM C\n"; cin >> C;
                break;
            case 2:
                cout << "\nDiem A: " << A;
                cout << "Diem B: " << B;
                cout << "Diem C: " << C;
                break;
            case 3:
                if(A.kiemtratrung(B)) 
                    cout << "A va B HOAN TOAN TRUNG NHAU (toa do va mau sac).\n";
                else 
                    cout << "A va B KHONG trung nhau.\n";
                break;
            case 4:
                cout << "Khoang cach giua A va B: " << A.khoangcach(B) << endl;
                break;
            case 5:
                cout << "Chu vi tam giac ABC: " << A.cv(B, C) << endl;
                break;
            case 6:
                cout << "Dien tich tam giac ABC: " << A.dt(B, C) << endl;
                break;
            case 7:
                int r, g, b;
                cout << "Nhap ma mau moi cho A (R G B): ";
                cin >> r >> g >> b;
                A.setRGB(r, g, b);
                cout << "=> Diem A sau khi doi mau: " << A;
                break;
            case 8:
                double dx, dy, dz;
                cout << "Nhap khoang cach di chuyen (dx, dy, dz): ";
                cin >> dx >> dy >> dz;
                A.dichuyen(dx, dy, dz);
                cout << "Diem A sau khi di chuyen: " << A;
                break;
            case 0:
                cout << "Dang thoat\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while(choice != 0);

    return 0;
}