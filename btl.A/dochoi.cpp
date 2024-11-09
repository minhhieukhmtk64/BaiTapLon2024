#include <bits/stdc++.h>
using namespace std;

class DoChoi
{
private:
    string MaDoChoi;
    string TenDoChoi; 
    float DonGia; 
    string PhanLoai; 
    int SoLuong; 

public:
    DoChoi(){}
    DoChoi(string mdc, string tdc, float dg, string pl, int sl)
    {
        MaDoChoi = mdc;
        TenDoChoi = tdc;
        DonGia = dg;
        PhanLoai = pl;
        SoLuong = sl;
    }
    string getMaDoChoi()
    {
        return MaDoChoi;
    }
    void setMaDoChoi(string mdc)
    {
        MaDoChoi = mdc;
    }
    string getTenDoChoi()
    {
        return TenDoChoi;
    }
    void setTenDoChoi(string tdc)
    {
        TenDoChoi = tdc;
    }
    float getDonGia()
    {
        return DonGia;
    }
    void setDonGia(float dg)
    {
        DonGia = dg;
    }
    string getPhanLoai()
    {
        return PhanLoai;
    }
    void setPhanLoai(string pl)
    {
        PhanLoai = pl;
    }
    int getSoLuong()
    {
        return SoLuong;
    }
    void setSoLuong(int sl)
    {
        SoLuong = sl;
    }
    friend istream &operator>>(istream &is, DoChoi &p)
    {
        cout << endl
             << "Nhap ma do choi: ";
        getline(is, p.MaDoChoi);
        cout << "Nhap ten do choi: ";
        getline(is, p.TenDoChoi);
        cout << "Nhap don gia: ";
        is >> p.DonGia;
        is.ignore();
        cout << "Nhap phan loai: ";
        getline(is, p.PhanLoai);
        cout << "Nhap so luong: ";
        is >> p.SoLuong;
        is.ignore();
        return is;
        
    }
    friend ostream &operator<<(ostream &os, DoChoi &p)
    {
        os << "Ma do choi: " << p.MaDoChoi << endl;
        os << "Ten do choi: " << p.TenDoChoi << endl;
        os << "Don gia: " << p.DonGia << endl;
        os << "Phan loai:  " << p.PhanLoai << endl;
        os << "So luong: " << p.SoLuong << endl;
        return os;
        
    }
    bool operator<(DoChoi a)
    {
        return this->SoLuong < a.SoLuong;
    }
};