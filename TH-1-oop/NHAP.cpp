#include<bits/stdc++.h>
using namespace std;
class DIEM2D{
    private:
        int x,y;
    public:
        //DIEM2D(): x(0), y(0){}
        DIEM2D(int x = 0, int y = 0) {
            this->x = x;
            this->y = y;
        }
        friend istream& operator>>(istream &is, DIEM2D &a);
        friend ostream& operator<<(ostream &os, const DIEM2D &a);
        void xuat() const {
            cout<<x<<" "<<y<<endl;
        }
};
istream& operator>>(istream&is, DIEM2D &a){
    cout<<"nhap x va y \n";
    is>>a.x>>a.y;
    return is;
}
ostream& operator<<(ostream &os, const DIEM2D &a){
    // os<<a.x<<" "<<a.y;
    a.xuat();
    return os;
}
int main(){
    DIEM2D a;
    cin>>a;
    cout<<a;
    return 0;
}