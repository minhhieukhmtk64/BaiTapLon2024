#include <bits/stdc++.h>
#include "dochoi.cpp"
using namespace std;

class QuanLi
{
private:
    list<DoChoi> Mon;

public:
    void Nhap();
    void Xuat();
    void SapXepGia();
    void Them();
    void TimKiem();
    void Tren20();
    void Xoa();
    void ThayDoi();
};

void QuanLi::Nhap()
{
    Mon.clear();
    int n;
back:
    cout << "Nhap so luong do choi: ";
    cin >> n;
    cin.ignore();
    if (n <= 0)
    {
        cout << "Khong hop le !" << endl;
        goto back;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            DoChoi a;
            cin >> a;
            Mon.push_back(a);
        }
        cout << endl
             << "Nhap thanh cong !" << endl;
    }
}

void QuanLi::Xuat()
{
    cout << setfill('-');
    cout << setw(83) << "-" << endl;
    cout << setfill(' ');
    cout << "|";
    cout << left << setw(11) << "Ma Do Choi";
    cout << "|";
    cout << left << setw(20) << "Ten Do Choi";
    cout << "|";
    cout << left << setw(17) << "Don Gia";
    cout << "|";
    cout << left << setw(17) << "Phan Loai";
    cout << "|";
    cout << left << setw(12) << "So Luong";
    cout << "|" << endl;
    list<DoChoi>::iterator dc;
    for (dc = Mon.begin(); dc != Mon.end(); dc++)
    {
        DoChoi tmp = *dc;
        cout << "|";
        cout << left << setw(11) << tmp.getMaDoChoi();
        cout << "|";
        cout << left << setw(20) << tmp.getTenDoChoi();
        cout << "|";
        cout << left << setw(17) << tmp.getDonGia();
        cout << "|";
        cout << left << setw(17) << tmp.getPhanLoai();
        cout << "|";
        cout << left << setw(12) << tmp.getSoLuong();
        cout << "|" << endl;
    }
    cout << setfill('-');
    cout << setw(83) << "-" << endl;
    cout << setfill(' ');
}

bool SoSanhGia(DoChoi a, DoChoi b)
{
    return a.getDonGia() < b.getDonGia();
}

void QuanLi::SapXepGia()
{
    if (Mon.empty())
    {
        cout << "Khong co san pham nao trong danh sach !" << endl;
        return;
    }
    Mon.sort(SoSanhGia);
    cout << endl
         << "Sap xep thanh cong !" << endl;
}

void QuanLi::Them()
{
    string madochoi;
    cout << "Nhap ma do choi moi: ";
    cin.ignore();
    getline(cin, madochoi);

    DoChoi tmp;
    list<DoChoi>::iterator res = Mon.begin();
    while (res != Mon.end())
    {
        tmp = *res;
        if (madochoi == tmp.getMaDoChoi())
        {
            cout << "Do choi co ma " << madochoi << " da co san trong cua hang !" << endl;
            return;
        }
        res++;
    }

    string tendochoi, phanloai;
    float dongia;
    int soluong;

    cout << "Nhap ten do choi moi: ";
    getline(cin, tendochoi);
    cout << "Nhap don gia: ";
    cin >> dongia;
    cin.ignore();
    cout << "Nhap phan loai: ";
    getline(cin, phanloai);
    cout << "Nhap so luong: ";
    cin >> soluong;
    cin.ignore();

    if(soluong <= 0)
    {
        cout << "So luong khong hop le !" << endl;
        return;
    }

    DoChoi b(madochoi, tendochoi, dongia, phanloai, soluong);

back:
    cout << endl
         << "Chen vao vi tri bat ky ?" << endl
         << "1.Co------------------------------2.Khong" << endl;

    int check;
    cout << "Tra loi: ";
    cin >> check;
    if (check == 1)
    {
        int pos;
        cout << "Nhap vi tri muon chen: ";
        cin >> pos;
        list<DoChoi>::iterator dc = Mon.begin();

        if(pos < 0)
        {
            cout << "Vi tri chen khong hop le !" << endl;
            return;
        }

        for (int i = 1; i < pos; i++)
        {
            dc++;
        }
        Mon.insert(dc, b);
        cout << endl
             << "Them do choi thanh cong !" << endl;
    }
    else if (check == 2)
    {
        Mon.push_back(b);
        cout << endl
             << "Them do choi thanh cong !" << endl;
    }
    else
    {
        cout << "Khong hop le !" << endl;
        goto back;
    }
}

void QuanLi::TimKiem()
{
    int cnt = 0;
    string name;
    cout << endl
         << "Nhap phan loai muon tim kiem: ";
    cin.ignore();
    getline(cin, name);
    list<DoChoi>::iterator dc;
    cout << setfill('-');
    cout << setw(83) << "-" << endl;
    cout << setfill(' ');
    cout << "|";
    cout << left << setw(11) << "Ma Do Choi";
    cout << "|";
    cout << left << setw(20) << "Ten Do Choi";
    cout << "|";
    cout << left << setw(17) << "Don Gia";
    cout << "|";
    cout << left << setw(17) << "Phan Loai";
    cout << "|";
    cout << left << setw(12) << "So Luong";
    cout << "|" << endl;
    for (dc = Mon.begin(); dc != Mon.end(); dc++)
    {
        DoChoi tmp;
        tmp = *dc;
        if (name.compare(tmp.getPhanLoai()) == 0)
        {
            cout << "|";
            cout << left << setw(11) << tmp.getMaDoChoi();
            cout << "|";
            cout << left << setw(20) << tmp.getTenDoChoi();
            cout << "|";
            cout << left << setw(17) << tmp.getDonGia();
            cout << "|";
            cout << left << setw(17) << tmp.getPhanLoai();
            cout << "|";
            cout << left << setw(12) << tmp.getSoLuong();
            cout << "|" << endl;
            cnt++;
        }
    }
    if (cnt == 0)
    {
        cout << "|";
        cout << left << setw(11) << "Trong !";
        cout << "|";
        cout << left << setw(20) << "Trong !";
        cout << "|";
        cout << left << setw(17) << "Trong !";
        cout << "|";
        cout << left << setw(17) << "Trong !";
        cout << "|";
        cout << left << setw(12) << "Trong !";
        cout << "|" << endl;
        cout << setfill('-');
        cout << setw(83) << "-" << endl;
        cout << setfill(' ');
    }
    else
    {
        cout << setfill('-');
        cout << setw(83) << "-" << endl;
        cout << setfill(' ');
    }
}

void QuanLi::Tren20()
{
    int cnt = 0;
    cout << setfill('-');
    cout << setw(83) << "-" << endl;
    cout << setfill(' ');
    cout << "|";
    cout << left << setw(11) << "Ma Do Choi";
    cout << "|";
    cout << left << setw(20) << "Ten Do Choi";
    cout << "|";
    cout << left << setw(17) << "Don Gia";
    cout << "|";
    cout << left << setw(17) << "Phan Loai";
    cout << "|";
    cout << left << setw(12) << "So Luong";
    cout << "|" << endl;
    list<DoChoi>::iterator dc;
    for (dc = Mon.begin(); dc != Mon.end(); dc++)
    {
        DoChoi tmp;
        tmp = *dc;
        if (tmp.getSoLuong() > 20)
        {
            cout << "|";
            cout << left << setw(11) << tmp.getMaDoChoi();
            cout << "|";
            cout << left << setw(20) << tmp.getTenDoChoi();
            cout << "|";
            cout << left << setw(17) << tmp.getDonGia();
            cout << "|";
            cout << left << setw(17) << tmp.getPhanLoai();
            cout << "|";
            cout << left << setw(12) << tmp.getSoLuong();
            cout << "|" << endl;
            cnt++;
        }
    }
    if (cnt == 0)
    {
        cout << "|";
        cout << left << setw(11) << "Trong !";
        cout << "|";
        cout << left << setw(20) << "Trong !";
        cout << "|";
        cout << left << setw(17) << "Trong !";
        cout << "|";
        cout << left << setw(17) << "Trong !";
        cout << "|";
        cout << left << setw(12) << "Trong !";
        cout << "|" << endl;
        cout << setfill('-');
        cout << setw(83) << "-" << endl;
        cout << setfill(' ');
    }
    else
    {
        cout << setfill('-');
        cout << setw(83) << "-" << endl;
        cout << setfill(' ');
    }
}

void QuanLi::Xoa()
{
    string ops;
    int cnt = 0;
    cout << "Nhap ma do choi muon xoa: ";
    cin.ignore();
    getline(cin, ops);
    list<DoChoi>::iterator dc;
    for (dc = Mon.begin(); dc != Mon.end(); dc++)
    {
        DoChoi tmp = *dc;
        if (tmp.getMaDoChoi() == ops)
        {
            Mon.erase(dc);
            cnt++;
            cout << endl
                 << "Xoa thanh cong !" << endl;
            break;
        }
    }
    if (cnt == 0)
        cout << endl
             << "Khong tim thay do choi muon xoa !" << endl;
}

void QuanLi::ThayDoi()
{
    string ops;
    int cnt = 0;
    cout << "Nhap ma do choi muon thay doi thong tin: ";
    cin.ignore();
    getline(cin, ops);
    list<DoChoi>::iterator dc;
    for (dc = Mon.begin(); dc != Mon.end(); dc++)
    {
        DoChoi tmp = *dc;
        if (tmp.getMaDoChoi() == ops)
        {
            cin >> *dc;
            cnt++;
            cout << endl
                 << "Thay doi thanh cong !" << endl;
            break;
        }
    }
    if (cnt == 0)
        cout << endl
             << "Khong tim thay do choi muon thay doi !" << endl;
}
