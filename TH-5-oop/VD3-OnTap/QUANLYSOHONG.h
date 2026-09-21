#ifndef _QUANLYSOHONG
#define _QUANLYSOHONG
#include"SOHONG.h"
#include"DATNONGNGHIEP.h"
#include"DATPHINONGNGHIEP.h"
class QUANLYSOHONG
{
    private:
        SOHONG** sh;
        int slsh;
    public:
        ~QUANLYSOHONG(){
            for(int i = 0;i<slsh;i++)
                delete sh[i];
            delete[] sh;
            sh = nullptr;
        }
        void Nhap(){
            int loai;
            cout<<"nhap so luong so hong\n";
            cin>>slsh;
            sh = new SOHONG*[slsh];
            for(int i = 0;i<slsh;i++){
                do{
                    cout<<"chon 1- DAT NONG NGHIEP, 2 -DAT PHI NONG NGHIEP\n";
                    cin>>loai;
                }while(loai<1 || loai>2);
                if(loai==1){
                    sh[i] = new DATNONGNGHIEP;
                    sh[i]->Nhap();
                } else{
                    sh[i] = new DATPHINONGNGHIEP;
                    sh[i]->Nhap();
                }
            }
        }
        void Xuat(){
            for(int i = 0;i<slsh;i++) sh[i]->Xuat();
        }
        void XuatThuaDatDongNhieuThueNhat(){
            int t = 0;
            for(int i = 1;i<slsh;i++){
                if(sh[i]->TienThue()>sh[t]->TienThue()) t = i;
            }
            if(slsh>0) sh[t]->Xuat();
            else cout<<"khong co thua dat nao\n";
        }
        void XuatDatNongNghiepHetHanSuDung(){
            for(int i = 0;i<slsh;i++){
                if(sh[i]->GetLoai()=="DATNONGNGHIEP"){
                    if(((DATNONGNGHIEP*)sh[i])->Getthoihan()<2026) sh[i]->Xuat();
                }
            }
        }
        void WriteFile(string tenfile){
            cout<<"nhap den khi gap ~ huy\n";
            ofstream Outfile(tenfile);
            string x;
            cin.ignore();
            while(true){
                getline(cin, x);
                if(x.back()=='~'){
                    x.pop_back();
                    Outfile<<x<<endl;
                }
                Outfile<<x<<endl;
            }
            Outfile.close();
            cout<<"nhap file thanh cong\n";
        }
        void ReadFile(string tenfile){
            ifstream infile(tenfile);
            string x;
            while(getline(infile, x)){
                cout<<x<<endl;
            }
            infile.close();
            cout<<"doc file thanh cong\n";
        }
        void WriteFilesohong(string tenfile){
            ofstream Outfile(tenfile);
            Outfile<<slsh<<endl;
            for(int i = 0;i<slsh;i++){
                if(sh[i]->GetLoai()=="DATNONGNGHIEP"){
                    Outfile<<1<<endl;
                    Outfile<<sh[i]->GetsoGiayCN()<<endl;
                    Outfile<<sh[i]->Getht()<<endl;
                    Outfile<<sh[i]->GetnamSinh()<<endl;
                    Outfile<<sh[i]->Getcccd()<<endl;
                    Outfile<<sh[i]->Getadds()<<endl;
                    Outfile<<sh[i]->GetsoThuaDat()<<endl;
                    Outfile<<sh[i]->GetsoToBanDo()<<endl;
                    Outfile<<sh[i]->GetaddsDat()<<endl;
                    Outfile<<sh[i]->Getdientich()<<endl;
                    Outfile<<sh[i]->Getd()<<" "<<sh[i]->Getm()<<" "<<sh[i]->Gety()<<endl;
                    Outfile<<sh[i]->GetdonGiaThue()<<endl;
                    Outfile<<((DATNONGNGHIEP*)sh[i])->Getthoihan()<<endl;
                } else{
                    Outfile<<2<<endl;
                    Outfile<<sh[i]->GetsoGiayCN()<<endl;
                    Outfile<<sh[i]->Getht()<<endl;
                    Outfile<<sh[i]->GetnamSinh()<<endl;
                    Outfile<<sh[i]->Getcccd()<<endl;
                    Outfile<<sh[i]->Getadds()<<endl;
                    Outfile<<sh[i]->GetsoThuaDat()<<endl;
                    Outfile<<sh[i]->GetsoToBanDo()<<endl;
                    Outfile<<sh[i]->GetaddsDat()<<endl;
                    Outfile<<sh[i]->Getdientich()<<endl;
                    Outfile<<sh[i]->Getd()<<" "<<sh[i]->Getm()<<" "<<sh[i]->Gety()<<endl;
                    Outfile<<sh[i]->GetdonGiaThue()<<endl;
                }
            }
            Outfile.close();
            cout<<"nhap file so hong thanh cong\n";
        }
        void Readfilesohong(string tenfile){
            int d,m,y;
            string soGiayCN, addsDat;
            string ht,cccd,adds;
            int namSinh, thoihan;
            NGAY ngayCap;
            int soThuaDat, soToBanDo, donGiaThue;
            double dientich;
            ifstream infile(tenfile);
            infile>>slsh;
            sh = new SOHONG*[slsh];
            int loai;
            for(int i = 0;i<slsh;i++){
                infile>>loai;
                if(loai==1){
                    infile.ignore();
                    getline(infile, soGiayCN);
                    getline(infile, ht);
                    infile>>namSinh;
                    infile.ignore();
                    getline(infile, cccd);
                    getline(infile, adds);
                    infile>>soThuaDat>>soToBanDo;
                    infile.ignore();
                    getline(infile, addsDat);
                    infile>>dientich;
                    infile>>d>>m>>y;
                    infile>>donGiaThue;
                    infile>>thoihan;
                    sh[i] = new DATNONGNGHIEP(soGiayCN, ht, namSinh, cccd, adds, soThuaDat, soToBanDo, addsDat, dientich, d , m, y, donGiaThue, thoihan);
                } else{
                    infile.ignore();
                    getline(infile, soGiayCN);
                    getline(infile, ht);
                    infile>>namSinh;
                    infile.ignore();
                    getline(infile, cccd);
                    getline(infile, adds);
                    infile>>soThuaDat>>soToBanDo;
                    infile.ignore();
                    getline(infile, addsDat);
                    infile>>dientich;
                    infile>>d>>m>>y;
                    infile>>donGiaThue;
                    sh[i] = new DATPHINONGNGHIEP(soGiayCN, ht, namSinh, cccd, adds, soThuaDat, soToBanDo, addsDat, dientich, d , m, y, donGiaThue);
                }
            }
            infile.close();
            cout<<"luu vao danh sach thanh cong\n";
        }
};
#endif