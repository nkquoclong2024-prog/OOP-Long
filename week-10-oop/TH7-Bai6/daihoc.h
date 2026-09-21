#ifndef daihoc_h
#define daihoc_h
#include"Sinhvientotnghiep.h"
class sdaihoc: public sinhvien
{
    private:
        string tenluanvan;
        double diem;
    public:
        sdaihoc(int diem = 0, string tenluanvan = " "): diem(diem), tenluanvan(tenluanvan){}
        ~sdaihoc() override{
            cout<<"tot nghiep dai hoc\n";
        }
        void Nhap() override{
            sinhvien::Nhap();
            cout<<"nhap ten luan van\n";
            cin.ignore();
            getline(cin, tenluanvan);
            cout<<"nhap diem luan van\n";
            cin>>diem;
        }
        void Xuat() override{
            sinhvien::Xuat();
            cout<<"\t|\t"<<tenluanvan<<"\t|\t"<<diem<<endl;
        }
        string PHANLOAI(){
            return "dai hoc";
        }
        bool TOTNGHIEP(){
            return (tc>=145 && tb>=5 && diem>=5);
        }
}; 
#endif