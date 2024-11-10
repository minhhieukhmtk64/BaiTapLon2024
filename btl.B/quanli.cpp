#include <bits/stdc++.h>
#include "cuahang.cpp"
using namespace std;

class QuanLi
{
private:
    CuaHang ch;
    map<string, int> SoLuongMatHang;

public:
    QuanLi() {};
    void Doc();
    void Ghi();
    void Nhap_Mat_Hang();
    void Xuat_Mat_Hang();
    void Hien_Thi_Mat_Hang();
    void Thong_Ke();
};

// Phương thức đọc thông tin quản lí của cửa hàng từ file
void QuanLi::Doc()
{
    string name;
    cout << "Nhap ten file doc: ";
    getline(cin, name);
    ifstream infile(name);
    if (!infile)
    {
        cout << "Khong mo duoc tep !" << endl;
        return;
    }
    else
    {
        ch = CuaHang();
        SoLuongMatHang = map<string, int>();

        ch.Doc_File(name);
        Vector<HoaDon> hd = ch.Tra_Ve_Hoa_Don();
        for (int i = 0; i < hd.getSize(); i++)
        {
            if (hd[i].getLoaiHoaDon() == "Mua")
            {
                SoLuongMatHang[hd[i].getMaHang()] += hd[i].getSoLuongMuaBan();
            }
            else
            {
                SoLuongMatHang[hd[i].getMaHang()] -= hd[i].getSoLuongMuaBan();
            }
        }
        cout << "Doc du lieu thanh cong tu file !" << endl;
    }
}

// Phương thức ghi thông tin quản lí của cửa hàng ra file
void QuanLi::Ghi()
{
    ch.Ghi_File("output.txt");
    cout << "Ghi thanh cong du lieu ra file !" << endl;
}

// Phương thức nhập thêm mặt hàng
void QuanLi::Nhap_Mat_Hang()
{
    int h;
    cout << "Nhap so luong mat hang muon nhap them: ";
    cin >> h;
    cin.ignore();
    if (h <= 0)
    {
        cout << "Khong hop le !" << endl;
        return;
    }
    MatHang tmp;
    int soluong, gia;
    string mahang, mahoadon, ngaygiaodich;
    for (int i = 0; i < h; i++)
    {
        cout << "Nhap vao mat hang thu " << i + 1 << " muon nhap: ";
        cin >> tmp;
        cout << "Nhap so luong: ";
        cin >> soluong;
        cout << "Nhap gia mua: ";
        cin >> gia;
        cin.ignore();
        cout << "Nhap ngay giao dich: ";
        getline(cin, ngaygiaodich);

        mahoadon = "HD" + to_string(ch.Tra_Ve_Hoa_Don().getSize() + 1);

        HoaDon res(mahoadon, tmp.getMaHang(), "Mua", soluong, ngaygiaodich, gia);
        ch.Them_Hoa_Don(res);

        if (SoLuongMatHang.find(tmp.getMaHang()) == SoLuongMatHang.end())
        {
            ch.Them_Mat_Hang(tmp);
        }
        SoLuongMatHang[tmp.getMaHang()] += soluong;
    }
    cout << "Them mat hang thanh cong !" << endl;
}

// Phương thức xuất ra các mặt hàng
void QuanLi::Xuat_Mat_Hang()
{
    int h;
    Vector<MatHang> mh = ch.Tra_Ve_Hang();
    
    if(mh.Empty())
    {
        cout << "Kho hang rong !" << endl;
        return;
    }
    
    cout << "Nhap so luong mat hang muon xuat ra: ";
    cin >> h;
    cin.ignore();
    if (h <= 0)
    {
        cout << "Khong hop le !" << endl;
        return;
    }
    int soluong, gia;
    string mahoadon, mahang, ngaygiaodich;
    for (int i = 0; i < h; i++)
    {
        cout << "Nhap ma mat hang thu " << i + 1 << " muon xuat: ";
        getline(cin, mahang);
        if (SoLuongMatHang.find(mahang) == SoLuongMatHang.end())
        {
            cout << "Khong tim thay mat hang !" << endl;
            return;
        }

        cout << "Nhap so luong mat hang muon xuat: ";
        cin >> soluong;
        if (soluong > SoLuongMatHang[mahang])
        {
            cout << endl
                 << "So luong hang co ma hang " + mahang + " trong kho khong du !" << endl;
            return;
        }

        cout << "Nhap gia ban: ";
        cin >> gia;
        cin.ignore();
        cout << "Nhap ngay giao dich: ";
        getline(cin, ngaygiaodich);

        mahoadon = "HD" + to_string(ch.Tra_Ve_Hoa_Don().getSize() + 1);

        HoaDon res(mahoadon, mahang, "Ban", soluong, ngaygiaodich, gia);
        ch.Them_Hoa_Don(res);
        SoLuongMatHang[mahang] -= soluong;
    }
    cout << "Xuat mat hang thanh cong !" << endl;
}

// Phương thức hiển thị các mặt hàng có sẵn trong cửa hàng
void QuanLi::Hien_Thi_Mat_Hang()
{
    Vector<MatHang> mh = ch.Tra_Ve_Hang();
    cout << endl
         << "Danh sach mat hang hien con san pham: " << endl;
    cout << setfill('-');
    cout << setw(52) << "-" << endl;
    cout << setfill(' ');
    cout << "|";
    cout << left << setw(11) << "Ma Hang";
    cout << "|";
    cout << left << setw(20) << "Ten Hang";
    cout << "|";
    cout << left << setw(17) << "Nha San Xuat";
    cout << "|" << endl;
    for (int i = 0; i < mh.getSize(); i++)
    {
        if (SoLuongMatHang[mh[i].getMaHang()] > 0)
        {
            cout << "|";
            cout << left << setw(11) << ch.Tra_Ve_Hang()[i].getMaHang();
            cout << "|";
            cout << left << setw(20) << ch.Tra_Ve_Hang()[i].getTenHang();
            cout << "|";
            cout << left << setw(17) << ch.Tra_Ve_Hang()[i].getNSX();
            cout << "|" << endl;
        }
    }
    cout << setfill('-');
    cout << setw(52) << "-" << endl;
    cout << setfill(' ');
}

// Phương thức thống kê số lượng hàng tồn kho của mỗi mặt hàng
void QuanLi::Thong_Ke()
{
    Vector<MatHang> mh = ch.Tra_Ve_Hang();
    cout << endl
         << "Danh sach san pham ton kho: " << endl;
    cout << setfill('-');
    cout << setw(23) << "-" << endl;
    cout << setfill(' ');
    cout << "|";
    cout << left << setw(10) << "Ma Hang";
    cout << "|";
    cout << left << setw(10) << "So Luong";
    cout << "|" << endl;
    for (int i = 0; i < mh.getSize(); i++)
    {
        cout << "|";
        cout << left << setw(10) << mh[i].getMaHang();
        cout << "|";
        cout << left << setw(10) << SoLuongMatHang[mh[i].getMaHang()];
        cout << "|" << endl;
    }
    cout << setfill('-');
    cout << setw(23) << "-" << endl;
    cout << setfill(' ');
}
