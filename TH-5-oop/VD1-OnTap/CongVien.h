#ifndef _CongVien
#define _CongVien
#include"Ve.h"
#include"ToanPhan.h"
#include"TungPhan.h"
class CongVien
{
    private:
        VE** ve;
        int slve;
    public:
        ~CongVien(){
            for(int i = 0;i<slve;i++)
                delete ve[i];
            delete[]ve;
            ve = nullptr;
        }
        CongVien(){};
        void Nhap(){
            int loai;
            cout<<"Nhap so luong ve\n";
            cin>>slve;
            ve = new VE*[slve];
            for(int i = 0;i<slve;i++){
                cout<<"nhap 1 - Toan Phan, 2 - Tung Phan\n";
                cin>>loai;
                if(loai==1){
                    ve[i] = new ToanPhan;
                    ve[i]->Nhap();
                } else{
                    ve[i] = new TungPhan;
                    ve[i]->Nhap();
                }
            } 
        }
        void Xuat(){
            for(int i = 0;i<slve;i++){
                ve[i]->Xuat();
            }
        }
        double TongTienVe(){
            double tong = 0;
            for(int i  = 0;i<slve;i++){
                tong+=ve[i]->GiaTien();
            }
            return tong;
        }
        int  SoVeTungPhan(){
            int kq = 0;
            for(int i = 0 ;i<slve;i++){
                if(ve[i]->PhanLoai()=="TungPhan") kq++;
            }
            return kq;
        }
        void Writefile(string tenfile){
            ofstream outfile(tenfile);
            if(!outfile.fail()){
                string x;
                cin.ignore();
                while(true){
                    getline(cin,x);
                    if(x.back()=='~'){
                        x.pop_back();
                        outfile<<x<<endl;
                        break;
                    }
                    outfile<<x<<endl;
                }
                outfile.close();
                cout<<"ghi file thanh cong\n";
            } else{
                cout<<"khong the mo file\n";
            }
        }
        void Readfile(string tenfile){
            ifstream inputfile(tenfile);
            string x;
            cin.ignore();
            while(getline(inputfile,x)){
                cout<<x<<endl;
            }
            inputfile.close();
            cout<<"doc file thanh cong\n";
        }
        void WritefileVe(string tenfile){
            ofstream outfile(tenfile);
            if(!outfile.fail()){
                outfile<<slve<<endl;
                for(int i = 0;i<slve;i++){
                    if(ve[i]->PhanLoai()=="ToanPhan"){
                        outfile<<1<<endl;
                        outfile<<ve[i]->Getmv()<<endl;
                        outfile<<ve[i]->Getht()<<endl;
                        outfile<<ve[i]->Getns()<<endl;
                        outfile<<ve[i]->Getst()<<endl;
                    } else{
                        outfile<<2<<endl;
                        outfile<<ve[i]->Getmv()<<endl;
                        outfile<<ve[i]->Getht()<<endl;
                        outfile<<ve[i]->Getns()<<endl;
                        outfile<<ve[i]->Getst()<<endl;
                    }
                }
                outfile.close();
                 cout<<"ghi file danh sach thanh cong\n";
            } else{
                cout<<"tao file khong thanh cong\n";
            }
        }
        void ReadfileVe(string tenfile){
            ifstream inputfile(tenfile);
            string mv,ht;
            int ns, st, loai;
            inputfile>>slve;
            ve = new VE*[slve];
            for(int i = 0;i<slve;i++){
                inputfile>>loai;
                inputfile.ignore();
                getline(inputfile, mv);
                getline(inputfile, ht);
                inputfile>>ns;
                inputfile>>st;
                if(loai==1){
                    ve[i] = new ToanPhan(mv,ht,ns,st);
                } else{
                    ve[i] = new TungPhan(mv,ht,ns,st);
                }
            }
            inputfile.close();
            cout<<"luu vao danh sach doi tuong thanh con\n";
        }
};
#endif