#include <bits/stdc++.h>
#include "quanli.cpp"
using namespace std;

int main()
{
    cout << "------------------------MENU-------------------------" << endl;
    cout << "   1. Doc thong tin quan li cua cua hang tu file." << endl;
    cout << "   2. Ghi thong tin quan li cua cua hang vao file." << endl;
    cout << "   3. Nhap them cac mat hang." << endl;
    cout << "   4. Xuat ra cac mat hang." << endl;
    cout << "   5. Hien thi toan bo danh sach mat hang hien co." << endl;
    cout << "   6. Thong ke so luong mat hang ton cua moi mat hang." << endl;
    cout << "   0. Thoat chuong trinh." << endl;
    cout << "-----------------------------------------------------" << endl;

    QuanLi ql;
back:
    while (true)
    {
        int key;
        cout << endl
             << "Nhap chuc nang: ";
        cin >> key;
        cin.ignore();
        switch (key)
        {
        case 1:
            cout << endl
                 << "1. Doc thong tin quan li cua cua hang tu file." << endl;
            ql.Doc();
            break;
        case 2:
            cout << endl
                 << "2. Ghi thong tin quan li cua cua hang vao file." << endl;
            ql.Ghi();
            break;
        case 3:
            cout << endl
                 << "3. Nhap them cac mat hang." << endl;
            ql.Nhap_Mat_Hang();
            break;
        case 4:
            cout << endl
                 << "4. Xuat ra cac mat hang." << endl;
            ql.Xuat_Mat_Hang();
            break;
        case 5:
            cout << endl
                 << "5. Hien thi toan bo danh sach mat hang hien co." << endl;
            ql.Hien_Thi_Mat_Hang();
            break;
        case 6:
            cout << endl
                 << "6. Thong ke so luong mat hang ton cua moi mat hang." << endl;
            ql.Thong_Ke();
            break;
        case 0:
            cout << endl
                 << "Da thoat chuong trinh !" << endl;
            exit(0);
            break;
        default:
            cout << endl
                 << "Vui long nhap lai !" << endl;
            goto back;
        }
    }
}