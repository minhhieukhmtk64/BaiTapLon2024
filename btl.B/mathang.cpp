#include <bits/stdc++.h>
using namespace std;

class MatHang
{
private:
    string MaHang;
    string TenHang;
    string NhaSanXuat;

public:
    MatHang() {};
    MatHang(string id, string name, string pr)
    {
        MaHang = id;
        TenHang = name;
        NhaSanXuat = pr;
    }

    string getMaHang()
    {
        return MaHang;
    }

    void setMaHang(string tmp)
    {
        MaHang = tmp;
    }
    
    string getTenHang()
    {
        return TenHang;
    }

    void setTenHang(string tmp)
    {
        TenHang = tmp;
    }

    string getNSX()
    {
        return NhaSanXuat;
    }

    void setNSX(string tmp)
    {
        NhaSanXuat = tmp;
    }

    friend istream &operator>>(istream &is, MatHang &p)
    {
        cout << endl
             << "Nhap ma hang: ";
        getline(is, p.MaHang);
        cout << "Nhap ten hang: ";
        getline(is, p.TenHang);
        cout << "Nhap nha san xuat: ";
        getline(is, p.NhaSanXuat);
        return is;
    }

    friend ostream &operator<<(ostream &os, MatHang &p)
    {
        os << "Ma hang: " << p.MaHang << endl;
        os << "Ten hang: " << p.TenHang << endl;
        os << "Nha san xuat: " << p.NhaSanXuat << endl;
        return os;
    }
};