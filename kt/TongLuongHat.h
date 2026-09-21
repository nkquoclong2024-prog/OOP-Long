#ifndef _TongLuongHat
#define _TongLuongHat
#include"HoaTriChuDong.h"
#include"LieuPhapMienDich.h"
#include<fstream>
class TongLuongHat
{
    private:
        Hat** dsHat;
        int slHat;
    public:
        ~TongLuongHat(){
            for(int i = 0;i<slHat;i++){
                delete dsHat[i];
            }
            delete[] dsHat;
            dsHat = nullptr;
        }
        TongLuongHat(int slhat = 0): slHat(slHat){}
        void Nhap(){
            cout<<"nhap tong so luong hat\n";
            cin>>slHat;
            int loai;
            dsHat = new Hat*[slHat];
            for(int i = 0;i<slHat;i++){
                cout<<"nhap 0 - hoa tri chu dong, 1 - lieu phap mien dich\n";
                cin>>loai;
                if(loai==0){
                    dsHat[i] = new HoaTriChuDong;
                    dsHat[i]->Nhap();
                } else{
                    dsHat[i] = new LieuPhapMienDich;
                    dsHat[i]->Nhap();
                }
            }
        }
        void Xuat(){
            cout<<"So hat dang co la\n";
            for(int i = 0;i<slHat;i++){
                cout<<"hat thu "<<i + 1<<endl;
                dsHat[i]->Xuat();
            }
        }
        void HatCoNangXuatGiaiPhongThuocManhNhatGioThu3(){
            if(slHat==0){
                cout<<"khong co hat nao\n";
                return;
            }
            int t = 0;
            for(int i  = 1;i<slHat;i++){
                if(dsHat[i]->NongDoThucTeChuKiThu(3)>dsHat[t]->NongDoThucTeChuKiThu(3)) t =i;
            }
            cout<<"hat co nang xuat giai phong thuoc manh nhat la\n";
            dsHat[t]->Xuat();
        }
        void RaSoat(){
            cout<<"cac hat bi loi la: \n";
            for(int i = 0;i<slHat;i++){
                if(dsHat[i]->PL()==0 && ((HoaTriChuDong*)dsHat[i])->GetTLSGDLHG()<=0) cout<<dsHat[i]->Getms()<<" ";
                else if(dsHat[i]->PL()==1 &&((LieuPhapMienDich*)dsHat[i])->GetGHCKSCTBMT()<=0) cout<<dsHat[i]->Getms()<<" ";
            }
        }
        void LuHoSo(string tenfile){
            ofstream Output(tenfile);
            Output<<slHat<<endl;
            for(int i = 0;i<slHat;i++){
                Output<<dsHat[i]->PL()<<endl;
                Output<<dsHat[i]->Getms()<<endl;
                Output<<dsHat[i]->Getslvmt()<<endl;
                for(int j = 0;j<dsHat[i]->Getslvmt();j++){
                    Output<<dsHat[i]->Getmmtds(j)<<endl;
                    Output<<dsHat[i]->Getlmds(j)<<endl;
                    Output<<dsHat[i]->Getnongdooxi(j)<<endl;
                }
                Output<<dsHat[i]->GetTHC()<<endl;
                Output<<dsHat[i]->GetLieuThuoc()<<endl;
                Output<<dsHat[i]->GetHSTTM()<<endl;
                if(dsHat[i]->PL()==0){
                    Output<<((HoaTriChuDong*)dsHat[i])->GetTLSGDLHG()<<endl;
                } else{
                    Output<<((LieuPhapMienDich*)dsHat[i])->GetGHCKSCTBMT()<<endl;
                }
            }
            Output.close();
            cout<<"Luu thanh cong\n";
        }
        void Docfile(string tenfile){
            string a = "",c = "";
            int b = 0, loai;
            double d = 0,e = 0;
            ifstream Input(tenfile);
            Input>>slHat;
            dsHat = new Hat*[slHat];
            for(int i = 0;i<slHat;i++){
                Input>>loai;
                if(loai==0){
                    double f;
                    Input.ignore();
                    getline(Input,a);
                    Input>>b;
                    dsHat[i] = new HoaTriChuDong(a);
                    for(int j = 0;j<b;j++){
                        string k; double x,y;
                        Input.ignore();
                        getline(Input, k);
                        Input>>x>>y;
                        dsHat[i]->Setds(k,x,y,j);
                    }
                    Input.ignore();
                    getline(Input, c);
                    Input>>d>>e>>f;
                    dsHat[i]->Set(a,b,c,d,e);
                    dsHat[i]->TD(f);
                } else{
                    double f;
                    Input.ignore();
                    getline(Input,a);
                    Input>>b;
                    dsHat[i] = new LieuPhapMienDich(a,b);
                    for(int j = 0;j<b;j++){
                        string k; double x,y;
                        Input.ignore();
                        getline(Input, k);
                        Input>>x>>y;
                        dsHat[i]->Setds(k,x,y,j);
                    }
                    Input.ignore();
                    getline(Input, c);
                    Input>>d>>e>>f;
                    dsHat[i]->Set(a,b,c,d,e);
                    dsHat[i]->TD(f);
                }
            }
            Input.close();
            cout<<"xuat thanh cong\n";
        }
};
#endif