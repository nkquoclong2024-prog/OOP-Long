#ifndef _nongtrai
#define _nongtrai
#include"Thu.h"
#include"Cho.h"
#include"Meo.h"
#include"Vit.h"
#include"Ran.h"
class NongTrai{
    private:
        Thu*thu[100];
        int slthu;
    public:
        ~NongTrai(){
            for(int i = 0;i<slthu;i++){
                delete thu[i];
            }
        }
        NongTrai(int slthu = 0): slthu(slthu){}
        void Nhap(){
            int loai;
            cout<<"Nhap so luong thu: ";
            cin>>slthu;
            for(int i = 0;i<slthu;i++){
                cout<<"Nhap thu thu "<<i+1<<endl;
                do{
                    cout<<"Nhap loai(1: cho - 2: meo - 3: vit - 4: ran): ";
                    cin>>loai;
                } while(loai<1 || loai>4);
                if(loai==1){
                    thu[i]=new Cho;
                } else if(loai==2){
                    thu[i]=new Meo;
                } else if(loai==3){
                    thu[i]=new Vit;
                } else if(loai==4){
                    thu[i]=new Ran;
                }
                thu[i]->Nhap();
            }
        }
        void Xuat(){
            if(slthu==0)
                cout<<"Nong trai chua co thu\n";
            else
                for(int i = 0;i<slthu;i++){
                    cout<<i+1<<"\t";
                    thu[i]->Xuat();
                }
        }
        void Lien_ke_meo_an_duoi_1_kg_ca(){
            int dem = 0;
            for(int i = 0;i<slthu;i++)
                if(thu[i]->GetLoai()=="Meo" && ((Meo*)thu[i])->GetCa()<1){
                    thu[i]->Xuat();
                    dem++;
                }
            if(dem==0)
                cout<<"Nong trai khong co con meo nao an duoi 1 kg ca\n";
        }

};
#endif