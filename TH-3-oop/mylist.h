#ifndef mylist_h
#define mylist_h
#include<iostream>
#include<math.h>
using namespace std;
class MyList{
    private:
        int size;
        int *data;
    public:
        ~MyList(){
            if(size>0){
                delete[] data;
            }
            data = nullptr;
            size = 0;
        }        
        MyList(int n  = 0, int m = 0): size(n), data(new int[n]){
            for(int i = 0;i<n;i++){
                data[i]=m;
            }
        }
        MyList(const MyList& a){
            if(size>0){
                delete[] data;
            }
            data = nullptr;
            size = a.size;
            data = new int[size];
            for(int i  = 0;i<size;i++){
                data[i]=a.data[i];
            }
        }
        void nhap(){
            cin>>size;
            data = new int[size];
            for(int i  =0;i<size;i++){
                cin>>data[i];
            }
        }
        void xuat(){
            cout<<size<<endl;
            for(int i = 0;i<size;i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
        friend istream& operator >> (istream& is, MyList& a){
            a.nhap();
            return is;
        }
        friend ostream& operator << (ostream& os, MyList& a){
            a.xuat();
            return os;
        }
        MyList& operator=(const MyList& a) {
            if (this != &a) {
                delete[] data;
                size = a.size;
                if (size > 0) {
                    data = new int[size];
                    for (int i = 0; i < size; i++) data[i] = a.data[i];
                } else {
                    data = nullptr;
                }
            }
            return *this;
        }
        bool operator == (const MyList& a){
            if(size!=a.size) return false;
            for(int i = 0;i<size;i++){
                if(a.data[i]!=data[i]) return false;
            }
            return true;
        }
        MyList operator + (const MyList& a){
            MyList kq(a.size+size, 0);
            int k = 0;
            for(int i = 0;i<size;i++){
                kq.data[k++] = data[i];
            }
            for(int i = 0;i<a.size;i++){
                kq.data[k++] = a.data[i];
            }
            return kq;
        }
        MyList& operator++(){
            MyList tmp(*this);
            if(size>0){
                size++;
                delete[] data;
            }
            data = new int[size];
            data[0]=0;
            for(int i = 0;i<size-1;i++){
                data[i+1]=tmp.data[i];
            }
            return *this;
        }
        MyList operator -- (int){
            MyList tmp(*this);
            if(size>0){
                delete [] data;
                data = nullptr;
            }
            size--;
            data = new int[size];
            for(int i = 0;i<size;i++){
                data[i] = tmp.data[i];
            }
            return tmp;
        }
        bool PerfectNumberTest(int n){
            int tmp = 0;
            for(int i = 1;i<n;i++){
                if(n%i==0) tmp+=i;
                if(tmp>n) return false;
            }
            return tmp==n;
        }
        bool CheckExistencePerfectNumberGreaterThanMinimum(){
            int n = 0, amax = 0, c = data[0];
            for(int i = 0;i<size;i++){
                if(PerfectNumberTest(data[i])){
                    amax = max(amax, data[i]);
                    n++;
                }
                c = min(data[i],c);
            }
            return (n && amax>c);
        }
};
#endif