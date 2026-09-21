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
        friend istream& operator >> (istream& is, DIEM3C& a){
            a.Nhap();
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
int main(){
    DIEM3CMAU a;
    int x;
    bool flag = false;
    do{
        cout<<"0: HUY\n";
        cout<<"1: NHAP\n";
        cout<<"2: xuat\n";
        cout<<"3: KIEM TRA TRUNG\n";
        cout<<"4: SO DIEM DA NHAP\n";
        cin>>x;
        if(!flag && x!=1){
            cout<<"chua nhap hay nhap lai\n";
            continue;
        }
        if(x==1){
            cin>>a;
            flag = true;
        } else if(x==2){
            cout<<a;
        } else if(x==3){
            DIEM3CMAU b;
            cout<<"nhap them 1 diem de kt\n";
            cin>>b;
            if(b.DIEM3CMAU::Kiemtratrung(b)) cout<<"co trung\n";
            else cout<<"khong co trung\n";
        } else if(x==4){
            cout<<"so diem da nhap la: "<<DIEM3CMAU::diem;
        } else{
            cout<<"so ko hop le\n";
        }
    } while(x!=0); 
    return 0;
}
