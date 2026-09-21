#ifndef _ThuVien
#define _ThuVien
#include"Sach.h"
#include"ThamKhao.h"
#include"GiaoKhoa.h"
class ThuVien{
    private:
        Sach* sach[1000];
        int slsach;
    public:
        ~ThuVien(){};
        ThuVien(int slsach = 0): slsach(slsach){}
        void Nhap(){
            cout<<"Nhap so luong sach: ";
            cin>>slsach;
            int loai;
            for(int i = 0;i<slsach;i++){
                do{
                    cout<<"nhap 1: Giao Khoa - 2: Tham Khao";
                    cin>>loai;
                }while(loai<1 && loai>2);
                if(loai==1){
                    sach[i] = new GiaoKhoa;
                } else{
                    sach[i] = new ThamKhao;
                }
                sach[i]->Nhap();
            }
        }
        void XuatSachCuaNhaXuatBan(string k){
            for(int i = 0;i<slsach;i++){
                if(sach[i]->XuatBan()==k){
                    sach[i]->Xuat();
                    return;
                }
            }
            cout<<"Khong tim thay\n";
        }
        void Xuat(){
            for(int i = 0;i<slsach;i++){
                cout<<"sach thu "<<i+1<<endl;
                sach[i]->Xuat();
            }
            double stk = 0, sgk = 0, isgk = 0, istk = 0;
            for(int i = 0;i<slsach;i++){
                if(sach[i]->LoaiSach()=="GiaoKhoa"){
                    sgk+=sach[i]->ThanhTien();
                    isgk++;
                } else{
                    stk+=sach[i]->ThanhTien();
                    istk++;
                }
            }
            cout<<"Tong tien sach giao khoa la: "<<sgk<<endl;
            cout<<"Tong tien sach tham khao la: "<<stk<<endl;
            cout<<"Trung binh tien sach giao khoa la: "<<sgk/isgk<<endl;
            cout<<"Trung binh sach tham khao la: "<<stk/istk<<endl;
        }
};
#endif