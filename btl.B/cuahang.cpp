#include <bits/stdc++.h>
#include "vector.cpp"
#include "mathang.cpp"
#include "hoadon.cpp"
using namespace std;

class CuaHang
{
private:
    Vector<MatHang> a;
    Vector<HoaDon> b;

private: 
    // Hàm đọc file mặt hàng
    void Doc_File_MH(ifstream &file)
    {
        int SoMatHang;
        string id, name, pr;
        file >> SoMatHang;
        file.ignore();
        for (int i = 0; i < SoMatHang; i++)
        {
            getline(file, id);
            getline(file, name);
            getline(file, pr);
            a.Push_Back(MatHang(id, name, pr));
        }
    }

    // Hàm đọc file hoá đơn
    void Doc_File_HD(ifstream &file)
    {
        int SoHoaDon;
        int qtt, pr;
        string id_iv, id_it, type, day;
        file >> SoHoaDon;
        file.ignore();
        for (int i = 0; i < SoHoaDon; i++)
        {
            getline(file, id_iv);
            getline(file, id_it);
            getline(file, type);
            file >> qtt;
            file.ignore();
            getline(file, day);
            file >> pr;
            file.ignore();
            b.Push_Back(HoaDon(id_iv, id_it, type, qtt, day, pr));
        }
    }

    // Hàm ghi file mặt hàng
    void Ghi_File_MH(ofstream &file)
    {
       file << endl << "-----Danh sach mat hang----- " << endl;
        for (int i = 0; i < a.getSize(); i++)
        {
           file << endl
                  << "Ma hang: " << a[i].getMaHang() << endl;
            file << "Ten hang: " << a[i].getTenHang() << endl;
            file << "Nha san xuat: " << a[i].getNSX() << endl;
        }
    }

    // Hàm ghi file hoá đơn
    void Ghi_File_HD(ofstream &file)
    {
        file << endl << "-----Danh sach hoa don----- " << endl;
        for (int i = 0; i < b.getSize(); i++)
        {
            file << endl
                  << "Ma hoa don: " << b[i].getMaHoaDon() << endl;
            file << "Ma hang: " << b[i].getMaHang() << endl;
            file << "Loai hoa don: " << b[i].getLoaiHoaDon() << endl;
            file << "So luong: " << b[i].getSoLuongMuaBan() << endl;
            file << "Ngay mua ban: " << b[i].getNgayMuaBan() << endl;
            file << "Gia: " << b[i].getGia() << endl;
        }
    }

public:
    CuaHang(){};
    void Doc_File(string file);
    void Ghi_File(string file);
    void Them_Mat_Hang(MatHang tmp);
    void Them_Hoa_Don(HoaDon tmp);
    Vector<MatHang> Tra_Ve_Hang();
    Vector<HoaDon> Tra_Ve_Hoa_Don();
};

// Hàm đọc thông tin quản lí của cửa hàng từ file
void CuaHang::Doc_File(string file)
{
    ifstream infile(file);
    Doc_File_MH(infile);
    Doc_File_HD(infile);
}

// Hàm ghi thông tin quản lí của cửa hàng ra file
void CuaHang::Ghi_File(string file)
{
    ofstream outfile(file);
    Ghi_File_MH(outfile);
    Ghi_File_HD(outfile);
}

// Hàm thêm 1 mặt hàng
void CuaHang::Them_Mat_Hang(MatHang tmp)
{
    a.Push_Back(tmp);
}

// Hàm thêm 1 hoá đơn
void CuaHang::Them_Hoa_Don(HoaDon tmp)
{
    b.Push_Back(tmp); 
}

// Hàm trả về danh sách mặt hàng
Vector<MatHang> CuaHang::Tra_Ve_Hang()
{
    return a;
}

// Hàm trả về danh sách hoá đơn
Vector<HoaDon> CuaHang::Tra_Ve_Hoa_Don()
{
    return b;
}