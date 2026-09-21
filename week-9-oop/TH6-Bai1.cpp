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
        static int diem;
    public:
        DIEM3C(double x = 0, double y = 0, double z = 0): Diem2D(x,y), z(z){}
        ~DIEM3C(){
            diem--;
            cout<<"da huy\n";
        }
        int xuatsodiem(){
            return diem;
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
        friend istream& operator >> (istream& is, DIEM3C& a){
            a.Nhap();
            diem++;
            cin>>a.z;
            cout<<endl;
            return is;
        }
        friend ostream& operator << (ostream& os, const DIEM3C& a){
            a.Xuat();
            cout<<", "<<a.z<<endl; 
            return os;
        }
};

int DIEM3C::diem = 0;

int main() {
    DIEM3C A, B, C;
    int luachon;

    do {
        cout << "1. Nhap toa do 3 diem A, B, C"<<endl;
        cout << "2. Xuat toa do 3 diem A, B, C"<<endl;
        cout << "3. Kiem tra diem A va B co trung nhau khong"<<endl;
        cout << "4. Tinh khoang cach giua A va B"<<endl;
        cout << "5. Tinh chu vi tam giac tao boi A, B, C"<<endl;
        cout << "6. Tinh dien tich tam giac tao boi A, B, C"<<endl;
        cout << "7. Di chuyen diem A theo vector (dx, dy, dz)"<<endl;
        cout << "8. Tim diem doi xung cua A qua goc toa do"<<endl;
        cout << "9. Thiet lap lai toa do moi cho A (setxyz)"<<endl;
        cout << "10. In ra so diem da tung nhap"<<endl;
        cout << "0. Thoat chuong trinh"<<endl;
        cin >> luachon;

        switch(luachon) {
            case 1:
                cout << "Nhap diem A:\n"; cin >> A;
                cout << "Nhap diem B:\n"; cin >> B;
                cout << "Nhap diem C:\n"; cin >> C;
                break;
            case 2:
                cout << "Toa do Diem A: " << A;
                cout << "Toa do Diem B: " << B;
                cout << "Toa do Diem C: " << C;
                break;
            case 3:
                if(A.Kiemtratrung(B)) 
                    cout << "Ket qua: Diem A va Diem B TRUNG NHAU.\n";
                else 
                    cout << "Ket qua: Diem A va Diem B KHONG trung nhau.\n";
                break;
            case 4:
                cout << "Khoang cach giua A va B la: " << A.khoangcach(B) << endl;
                break;
            case 5:
                cout << "Chu vi tam giac ABC la: " << A.cv(B, C) << endl;
                break;
            case 6:
                cout << "Dien tich tam giac ABC la: " << A.dt(B, C) << endl;
                break;
            case 7:
                double dx, dy, dz;
                cout << "Nhap khoang cach can di chuyen (dx, dy, dz): ";
                cin >> dx >> dy >> dz;
                A.dichuyen(dx, dy, dz);
                cout << "Diem A sau khi di chuyen: " << A;
                break;
            case 8:
                {
                    DIEM3C doiXungA = A.timdoixung();
                    cout << "Diem doi xung cua A la: " << doiXungA;
                }
                break;
            case 9:
                double nx, ny, nz;
                cout << "Nhap toa do moi cho A (x, y, z): ";
                cin >> nx >> ny >> nz;
                A.setxyz(nx, ny, nz);
                cout << "Diem A sau khi duoc cap nhat: " << A;
                break;
            case 10:
                cout<<"So diem da nhap la: "<<A.xuatsodiem()<<endl;
                break;
            case 0:
                cout << "Dang thoat\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai!\n";
        }
    } while(luachon != 0);

    return 0;
}
