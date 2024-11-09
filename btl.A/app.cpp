#include <bits/stdc++.h>
#include "quanli.cpp"

class App
{
public:
    void Menu()
    {
        cout << "       CHUONG TRINH QUAN LI CUA HANG DO CHOI" << endl;
        cout << "------------------------MENU-------------------------" << endl;
        cout << "   1. Nhap danh sach do choi." << endl;
        cout << "   2. In danh sach do choi." << endl;
        cout << "   3. Sap xep danh sach do choi theo Gia." << endl;
        cout << "   4. Them 1 do choi moi vao danh sach." << endl;
        cout << "   5. Tim kiem do choi theo Phan Loai." << endl;
        cout << "   6. In ra danh sach do choi co So Luong hon 20 mon." << endl;
        cout << "   7. Xoa do choi theo Ma Do Choi." << endl;
        cout << "   8. Thay doi thong tin do choi theo Ma Do Choi." << endl;
        cout << "   0. Thoat chuong trinh." << endl;
        cout << "-----------------------------------------------------" << endl;
    }
    void XuLyMenu()
    {
        QuanLi toy;
    back:
        while (true)
        {
            int key;
            cout << endl
                 << "* Nhap chuc nang: ";
            cin >> key;
            switch (key)
            {
            case 1:
                cout << endl
                     << "1. Nhap danh sach do choi." << endl;
                toy.Nhap();
                break;
            case 2:
                cout << endl
                     << "2. In danh sach do choi." << endl;
                toy.Xuat();
                break;
            case 3:
                cout << endl
                     << "3. Sap xep danh sach theo Gia." << endl;
                toy.SapXepGia();
                break;
            case 4:
                cout << endl
                     << "4. Them 1 do choi moi vao danh sach." << endl;
                toy.Them();
                break;
            case 5:
                cout << endl
                     << "5. Tim kiem do choi theo Phan Loai." << endl;
                toy.TimKiem();
                break;
            case 6:
                cout << endl
                     << "6. In ra danh sach do choi co So Luong hon 20 mon." << endl;
                toy.Tren20();
                break;
            case 7:
                cout << endl
                     << "7. Xoa do choi theo Ma Do Choi." << endl;
                toy.Xoa();
                break;
            case 8:
                cout << endl
                     << "8. Thay doi thong tin do choi theo Ma Do Choi." << endl;
                toy.ThayDoi();
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
};
