#include<iostream>
#include<vector>
using namespace std;
class CMatrix{
    private:
        int n,m;
        vector<vector<int>> a;
    public:
        CMatrix(int n, int m): n(n), m(m){
            cout<<"nhap "<<m*n<<" gia tri cua matrix\n";
            for(int i = 0;i<n;i++){
                vector<int> temp;
                for(int j = 0;j<m;j++){
                    int x; cin>>x;
                    temp.push_back(x);
                }
                a.push_back(temp);
            }
        }
        friend ostream& operator << (ostream&, CMatrix&);
        int getn(){return n;}
        int getm(){return m;}
        int get(int x,int y){return a[x][y];}
        
};
class CVector{
    private:
        int n;
        vector<int> k;
    public:
        CVector (int n): n(n), k(n){}
        friend istream& operator >> (istream&, CVector&);
        friend ostream& operator << (ostream&, CVector&);
        friend CVector operator * ( CVector&, CMatrix&);
};
istream& operator >> (istream& is, CVector& a){
    cout<<"nhap "<<a.n<<" gia tri cua vector\n";
    for(int i = 0;i<a.n;i++){
        is>>a.k[i];
    }
    return is;
}
ostream& operator << (ostream& os, CVector& a){
    cout<<"In ra cac gia tri cua vector\n";
    for(int i = 0;i<a.n;i++){
        os<<a.k[i]<<" ";
    }
    return os;
}
ostream& operator << (ostream& os, CMatrix& b){
    cout<<"cac gia tri cua matrix\n";
    for(int i = 0;i<b.n;i++){
        for(int j =0;j<b.m;j++){
            os<<b.a[i][j]<<" ";
        }
        os<<endl;
    }
    return os;
}
CVector operator * ( CVector& a, CMatrix& b){
        CVector kk(b.getm());
        for(int i = 0;i<b.getm();i++){
            int t = a.k[0]*b.get(0,i);
            for(int j = 1;j<b.getn();j++){
                t=t+a.k[j]*b.get(j,i);
            }
            kk.k[i]=t;
        }
        return kk;
}
int main() {
    int n_vector;
    cout << "Nhap so chieu cua vector (n): ";
    cin >> n_vector;
    CVector v(n_vector);
    cin >> v; 
    int n_matrix, m_matrix;
    cout << "Nhap so dong (n) va so cot (m) cua ma tran: ";
    cin >> n_matrix >> m_matrix;
    CMatrix m(n_matrix, m_matrix); 
    cout << "\nxuat thong tin vector va matrix\n";
    cout << v;
    cout<<endl;    
    cout << m;

    cout << "KET QUA PHEP NHAN (Vector * Matrix)";
    if (n_vector == n_matrix) {
        CVector result = v * m;
        cout << result;
    } else {
        cout << "KHONG THE TINH (Kich thuoc vector khong khop voi so dong cua ma tran)!\n";
    }

    return 0;
}