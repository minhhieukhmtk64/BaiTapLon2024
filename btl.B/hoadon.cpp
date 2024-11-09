#include <bits/stdc++.h>
using namespace std;

class HoaDon
{
private:
    string MaHoaDon;
    string MaHang;
    string LoaiHoaDon;
    int SoLuongMuaBan;
    string NgayMuaBan;
    int Gia;

public:
    HoaDon() {};
    HoaDon(string id_iv, string id_it, string type, int qtt, string day, int pr)
    {
        MaHoaDon = id_iv;
        MaHang = id_it;
        LoaiHoaDon = type;
        SoLuongMuaBan = qtt;
        NgayMuaBan = day;
        Gia = pr;
    }

    string getMaHoaDon()
    {
        return MaHoaDon;
    }

    void setMaHoaDon(string tmp)
    {
        MaHoaDon = tmp;
    }

    string getMaHang()
    {
        return MaHang;
    }

    void setMaHang(string tmp)
    {
        MaHang = tmp;
    }

    string getLoaiHoaDon()
    {
        return LoaiHoaDon;
    }

    void setLoaiHoaDon(string tmp)
    {
        LoaiHoaDon = tmp;
    }

    int getSoLuongMuaBan()
    {
        return SoLuongMuaBan;
    }

    void setSoLuongMuaBan(int tmp)
    {
        SoLuongMuaBan = tmp;
    }

    string getNgayMuaBan()
    {
        return NgayMuaBan;
    }

    void setNgayMuaBan(string tmp)
    {
        NgayMuaBan = tmp;
    }

    int getGia()
    {
        return Gia;
    }

    void setGia(int tmp)
    {
        Gia = tmp;
    }

    friend istream &operator>>(istream &is, HoaDon &p)
    {
        cout << "Nhap ma hoa don: ";
        getline(is, p.MaHoaDon);
        cout << "Nhap ma hang: ";
        getline(is, p.MaHang);
        cout << "Nhap loai hoa don: ";
        getline(is, p.LoaiHoaDon);
        cout << "Nhap so luong mua ban: ";
        is >> p.SoLuongMuaBan;
        is.ignore();
        cout << "Nhap ngay mua ban: ";
        getline(is, p.NgayMuaBan);
        cout << "Nhap gia: ";
        is >> p.Gia;
        is.ignore();
        return is;
    }

    friend ostream &operator<<(ostream &os, HoaDon &p)
    {
        os << "Ma hoa don: " << p.MaHoaDon << endl;
        os << "Ma hang: " << p.MaHang << endl;
        os << "Loai hoa don: " << p.LoaiHoaDon << endl;
        os << "So luong mua ban: " << p.SoLuongMuaBan << endl;
        os << "Ngay mua ban: " << p.NgayMuaBan << endl;
        os << "Gia: " << p.Gia << endl;
        return os;
    }
};
