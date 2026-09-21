#ifndef _CongTy
#define _CongTy
#include"NhanVien.h"
#include"LapTrinhVien.h"
#include"KiemChungVien.h"
class CongTy
{
    private:
        NhanVien**NV;
        int slnv;
    public:
        ~CongTy(){
            for(int i =  0;i<slnv;i++)
                delete NV[i];
            delete[]NV;
            NV = nullptr;
        }
        CongTy(){}
        void Nhap(){
            int loai;
            cout<<"so luong nhan vien\n";
            cin>>slnv;
            NV = new NhanVien*[slnv];
            for(int i = 0;i<slnv;i++){
                cout<<"nhap 1 - Lap trinh vien, 2 - Kiem chung vien\n";
                cin>>loai;
                if(loai==1){
                    NV[i] = new LapTrinhVien;
                    NV[i]->Nhap();
                } else{
                    NV[i] = new KiemChungVien;
                    NV[i]->Nhap();
                }
            }
        }
        void Xuat(){
            for(int i = 0;i<slnv;i++){
                NV[i]->Xuat();
            }
        }
        void DSNhanVienLuongThapHonTB(){
            double tb = 0, t = 0;
            for(int i = 0;i<slnv;i++){
                tb+=NV[i]->Luong();
            }
            tb = tb/slnv;
            for(int i = 0;i<slnv;i++){
                if(NV[i]->Luong()<tb){
                    t++;
                    NV[i]->Xuat();
                }
            }
            if(t==0) cout<<"Khong co nhan vien nao thoa\n";
        }
        void DSNhanVienCoMucLuongToiThieuDoNhapLa(double x){
            int t = 0;
            for(int i = 0;i<slnv;i++){
                if(NV[i]->Luong()>=x){
                    NV[i]->Xuat();
                    t++;
                }
            }
            if(t==0) cout<<"Khong co nhan vien nao thoa\n";
        }
        void writefile(string tenfile){
            cout<<"nhap ~ de thoat\n";
            ofstream OutFile(tenfile);
            string x;
            cin.ignore();
            while(true){
                getline(cin, x);
                if(x.back()=='~'){
                    x.pop_back();
                    OutFile<<x<<endl;
                    break;
                }
                OutFile<<x<<endl;
            }
            OutFile.close();
            cout<<"Ghi file thanh cong\n";
        }
        void readfile(string tenfile){
            ifstream inFile(tenfile);
            string x;
            while(getline(inFile, x)){
                cout<<x<<endl;
            }
            inFile.close();
            cout<<"Doc file thanh cong\n";
        }
        void writefileds(string tenfile){
            ofstream OutFile(tenfile);
            string x;
            OutFile<<slnv<<endl;
            for(int i = 0;i<slnv;i++){
                if(NV[i]->PhanLoai()=="LapTrinhVien"){
                    OutFile<<1<<endl;
                    OutFile<<NV[i]->Getmnv()<<endl;
                    OutFile<<NV[i]->Getht()<<endl;
                    OutFile<<NV[i]->Gettuoi()<<endl;
                    OutFile<<NV[i]->Getsdt()<<endl;
                    OutFile<<NV[i]->Getemail()<<endl;
                    OutFile<<NV[i]->Getluongcoban()<<endl;
                    OutFile<<((LapTrinhVien*)NV[i])->Getluongcoban()<<endl;
                } else{
                    OutFile<<2<<endl;
                    OutFile<<NV[i]->Getmnv()<<endl;
                    OutFile<<NV[i]->Getht()<<endl;
                    OutFile<<NV[i]->Gettuoi()<<endl;
                    OutFile<<NV[i]->Getsdt()<<endl;
                    OutFile<<NV[i]->Getemail()<<endl;
                    OutFile<<NV[i]->Getluongcoban()<<endl;
                }
            }
            OutFile.close();
            cout<<"Ghi file ds thanh cong \n";
        }
        void readfileds(string tenfile){
            int loai;
            string mnv, ht, email;
            int tuoi, sdt, soloi, sogiolamthem;
            double luongcoban;
            ifstream infile(tenfile);
            infile>>slnv;
            NV = new NhanVien*[slnv];
            for(int i = 0;i<slnv;i++){
                infile>>loai;
                infile.ignore();
                getline(infile, mnv);
                getline(infile, ht);
                infile>>tuoi;
                infile>>sdt;
                infile.ignore();
                getline(infile, email);
                infile>>luongcoban;
                if(loai==1){
                    infile>>sogiolamthem;
                    NV[i] = new LapTrinhVien(mnv, ht, tuoi, sdt, email, luongcoban, sogiolamthem);
                } else{
                    infile>>soloi;
                    NV[i] = new KiemChungVien(mnv, ht, tuoi, sdt, email, luongcoban, soloi);
                }
            }
            cout<<"luu file thanh cong\n";
        }
};
#endif