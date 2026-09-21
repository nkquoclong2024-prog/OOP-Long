#ifndef N_QuanLi
#define N_QUanLi
#include"Sinhvien.h"
#include"CQ.h"
#include"LT.h"
class QuanLi
{
    private:
        sinhvien*SV[100];
        int slsv;
    public:
        ~QuanLi(){
            for(int i = 0;i<slsv;i++){
                delete SV[i];
            }
            delete[] SV;
        }
        QuanLi(int slsv = 0): slsv(slsv){}
        void Nhap(){
            int loai;
            cout<<"nhap so luong sinh vien\n";
            cin>>slsv;
            for(int i = 0;i<slsv;i++){
                cout<<"nhap loai sinh vien (1: chinh quy - 2: lien thong)\n";
                cin>>loai;
                while(loai<1 || loai>2){
                    cout<<"nhap lai loai chi 1 va 2\n";
                    cin>>loai;
                }
                if(loai==1){
                    SV[i] = new CQ;
                    SV[i]->Nhap();
                } else{
                    SV[i] = new LT;
                    SV[i]->Nhap();
                }
            }
        }
        void LietKeSVCQ_DRL100(){
            int t = 0;
            cout<<"Sinh vien chinh quy co DRL la 100 \n";
            for(int i = 0;i<slsv;i++){
                if(SV[i]->PhanLoai()=="CQ"){
                    if(((CQ*)SV[i])->GetDRL()==100){
                        SV[i]->Xuat();
                        t++;
                    }
                }
            }
            if(t==0) cout<<"Khong co sinh vien chinh quy nao DRL la 100\n";
        }
        void DemSVLT_KhongNghi(){
            int t= 0;
            cout<<"Sinh vien lien thong khong nghi buoi nao\n";
            for(int i = 0;i<slsv;i++){
                if(SV[i]->PhanLoai()=="LT"){
                    if(((LT*)SV[i])->GetSBV()==0){
                        SV[i]->Xuat();
                        t++;
                    }
                }
            }
            if(t==0) cout<<"Khong co sinh vien lien thong nao khong nghi buoi nao\n";
        }
        void Tong_HB(){
            double tong = 0;
            for(int i = 0;i<slsv;i++){
                tong+=SV[i]->Hocbong();
            }
            cout<<"tong hoc bong cap cho cac SV la: "<<tong<<endl;
        }
        void DTB_SVCQ_CoHB(){
            int tong = 0, t = 0;
            for(int i = 0;i<slsv;i++){
                if(SV[i]->PhanLoai()=="CQ" && SV[i]->Hocbong()>0){
                    tong+=SV[i]->Getdtb();
                    t++;
                }
            }
            if(t==0) cout<<"Khong co SVCQ nao co hoc bong\n";
            else cout<<"DTB cua SVCQ la: "<<tong/t<<endl;
        }
        bool SVLT_DTB_LonHon9(){
            for(int i = 0;i<slsv;i++){
                if(SV[i]->PhanLoai()=="LT" && SV[i]->Getdtb()>=9){
                    return true;
                }
            }
            return false;
        }
        void SVCQ_DTB_CaoNhat(){
            int t = -1;
            for(int i = 0;i<slsv;i++){
                if(SV[i]->PhanLoai()=="CQ"){
                    if(t==-1) t=i;
                    else if(SV[i]->Getdtb()>SV[t]->Getdtb()) t =i;
                }
            }
            if(t!=-1){
                cout<<"Sinh vien CQ co DTB cao nhat\n";
                SV[t]->Xuat();
            } else{
                cout<<"khong co SVCQ nao\n";
            }
        }
        void SapXep_Tang_Dan_Theo_MS(){
            sort(SV, SV+slsv);
        }
        void Them_1_SV_Moi(){
            cout<<"them 1 sinh vien moi\n";
            slsv++;
            int loai;
            cout<<"nhap loai sinh vien (1: chinh quy - 2: lien thong)\n";
            cin>>loai;
            while(loai<1 || loai>2){
                cout<<"nhap lai loai chi 1 va 2\n";
                cin>>loai;
            }
            if(loai==1){
                SV[slsv-1] = new CQ;
                SV[slsv-1]->Nhap();
            } else{
                SV[slsv-1] = new LT;
                SV[slsv-1]->Nhap();
            }
        }
        void Xoa_SV(){
            int loai;
            cout<<"nhap ma so muon xoa\n";
            cin>>loai;
            for(int i = 0;i<slsv;i++){
                if(SV[i]->Getms()==loai){
                    slsv--;
                    swap(SV[i],SV[slsv]);
                    cout<<"Da xoa\n";
                    break;
                }
            }
        }
        void TimKiemSV(){
            int loai;
            cout<<"Chon cac cach tim (1: ma so - 2: ho ten - 3: Khoa - 4: DTB - 5: hoc bong)\n";
            cin>>loai;
            int ms, t = 0;
            string ht, khoa;
            double dtb, hb;
            if(loai==1){
                cout<<"nhap ma so sinh vien can tim\n";
                cin>>ms;
                cout<<"sinh vien can tim theo mssv la: \n";
                for(int i = 0;i<slsv;i++){
                    if(SV[i]->Getms()==ms){
                        SV[i]->Xuat();
                        t++;
                        break;
                    }
                }
            } else if(loai==2){
                cout<<"nhap ho ten can tim\n";
                cin.ignore();
                getline(cin, ht);
                cout<<"sinh vien can tim theo ho ten  la: \n";
                for(int i = 0;i<slsv;i++){
                    if(SV[i]->Getht()==ht){
                        SV[i]->Xuat();
                        t++;
                        break;
                    }
                }
            } else if(loai==3){
                cout<<"nhap ten khoa can tim\n";
                cin.ignore();
                getline(cin, khoa);    
                cout<<"sinh vien can tim theo ten khoa la: \n";
                for(int i = 0;i<slsv;i++){
                    if(SV[i]->Getkhoa()==khoa){
                        SV[i]->Xuat();
                        t++;
                        break;
                    }
                }
            } else if(loai==4){
                cout<<"nhap diem trung binh can tim\n";
                cin>>dtb;  
                cout<<"sinh vien can tim theo diem trung binh la: \n";
                for(int i = 0;i<slsv;i++){
                    if(SV[i]->Getdtb()==dtb){
                        SV[i]->Xuat();
                        t++;
                        break;
                    }
                }
            } else if(loai==5){
                cout<<"nhap hoc bong can tim\n";
                cin>>hb;
                cout<<"sinh vien can tim theo hoc bong la: \n";
                for(int i = 0;i<slsv;i++){
                    if(SV[i]->Hocbong()==hb){
                        SV[i]->Xuat();
                        t++;
                        break;
                    }
                }
            }
            if(t==0) cout<<"khong co sinh vien can tim\n";
        }
        void Xuat(){
            for(int i = 0;i<slsv;i++){
                cout<<"SV thu "<<i+1<<endl;
                SV[i]->Xuat();
            }
        }
};
#endif