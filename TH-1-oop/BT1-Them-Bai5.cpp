#include<iostream>
#include<string>
using namespace std;
class HOCSINH{
    private:
        double t,v;
        string hvt, msv;
    public:
        HOCSINH (string m="", string h="", int vv = 0, int tt = 0) : msv(m), hvt(h), v(vv), t(tt){}
        double mean(){
            return(t+v)/2;
        }
        string xl(){
            double k = mean();
            if(k<2) return "Kem";
            else if(k<5) return "Yeu";
            else if(k<7) return "Trung binh";
            else if(k<8) return "Kha";
            else if(k<9) return "Gioi";
            return "Xuat xac";
        }
        friend istream& operator>>(istream& is, HOCSINH& x){
            getline(is, x.msv);
            getline(is, x.hvt);
            is>>x.v>>x.t;
            return is;
        }
        friend ostream& operator<<(ostream& os, HOCSINH& x){
            os<<"msv: "<<x.msv<<"\nho va ten: "<<x.hvt<<"\ndiem van: "<<x.v<<"\ndiem toan: "<<x.t<<"\ndiem trung binh: "<<x.mean()<<"\nxep loai: "<<x.xl();
            return os;
        }
};
int main(){
    HOCSINH x;
    cout<<"NHAP MSV, TEN, DIEM VAN, DIEM TOAN \n";
    cin>>x;
    cout<<x;
    return 0;
}