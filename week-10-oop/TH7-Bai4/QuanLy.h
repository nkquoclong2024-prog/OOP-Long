#ifndef quanly_h
#define quanly_h
#include"Giaodich.h"
#include"Giaodichcanhochungcu.h"
#include"Giaodichdat.h"
#include"Giaodichnhapho.h"
class QUANLY
{
    private:
        GIAODICH* giaodich[100];
        int slgd;
    public:
        ~QUANLY(){
            for(int i = 0;i<slgd;i++){
                delete giaodich[i];
            }
            delete[] giaodich;
        }
        QUANLY(int n = 0): slgd(n){}
        void Nhap(){
            int t;
            cout<<"nhap so luong giao dich\n";
            cin>>slgd;
            for(int i = 0;i<slgd;i++){
                cout<<"nhap cac lua chon cac loai giao dich sau (1: dat - 2: nha pho - 3: trung cu) la\n";
                cin>>t;
                while(t<1 || t>3){
                    cout<<"nhap cac lua chon cac loai giao dich sau (1: dat - 2: nha pho - 3: trung cu) la\n";
                    cin>>t;
                }
                if(t==1){
                    giaodich[i]= new GIAODICHDAT;
                    giaodich[i]->nhap();
                   
                } else if(t==2){
                    giaodich[i]= new GIAODICHNHAPHO;
                    giaodich[i]->nhap();
                } else{
                    giaodich[i]= new TRUNGCU;
                    giaodich[i]->nhap();
                }
            }
        }
        void Tong_SL_Tung_Loai(){
            int t1 = 0, t2 = 0, t3 = 0;
            for(int i = 0;i<slgd;i++){
                if(giaodich[i]->TENBATDONGSAN()=="DAT"){
                    t1++;
                } else if(giaodich[i]->TENBATDONGSAN()=="NHA PHO"){
                    t2++;
                } else{
                    t3++;
                }
            }
            cout<<"tong so luong giao dich cua dat la: "<<t1<<endl;
            cout<<"tong so luong giao dich cua nha pho la: "<<t2<<endl;
            cout<<"tong so luong giao dich cua trung cu la: "<<t3<<endl;
        }
        void TB_ThanhTien_GD_TC(){
            int t3 = 0, tong = 0;
             for(int i = 0;i<slgd;i++){
                if(giaodich[i]->TENBATDONGSAN()=="TRUNG CU"){
                    t3++;
                    tong+=giaodich[i]->GIA();
                }
            }
            if(t3!=0) cout<<"trung binh thanh tien cau giao dich can ho trung cu la: "<<tong/t3<<endl;
            else cout<<"khong co trung cu nao\n";
        }
        void GiaoDich_TP_CoGiaTriCaoNhat(){
            int tt = -1;
            for(int i = 0;i<slgd;i++){
                if(giaodich[i]->TENBATDONGSAN()=="NHA PHO"){
                    if(tt==-1) tt= i;
                    else if(giaodich[i]->GIA()>giaodich[tt]->GIA()) tt = i;
                }
            }
            if(tt!=-1){
                cout<<"giao dich nha pho co gia cao nhat la: \n";
                giaodich[tt]->xuat();
            } else cout<<"khong co giao dich nha pho nao\n";
        }
        void DS_GiaoDich_Cua_T12_N2024(){
            int t = 0;
            for(int i = 0;i<slgd;i++){
                if(giaodich[i]->Getmonth()==12 && giaodich[i]->Getyear()==2024){
                    t++;
                    if(t==1) cout<<"danh sach cac giao dich cua thang 12 nam 2024\n";
                    cout<<giaodich[i]->TENBATDONGSAN()<<"\t";
                    giaodich[i]->xuat();
                }
            }
            if(t==0) cout<<"khong co giao dich nao thuoc thang 12 nam 2024\n";
        }
        void Xuat(){
            for(int i =0;i<slgd;i++){
                cout<<"Giao dich thu "<<i+1<<endl;
                giaodich[i]->xuat();
            }
        }
};
#endif