#include<bits/stdc++.h>
using namespace std;

template <class T>
class Vector{
    private:
        int size, space;
        T *a;
        // Ham tang dung luong mang a;
        void Expand(int newspace){
            if(newspace <= size) return;
            else{
                T *odd=a; // Tao 1 mang moi bang mang a;
                a = new T[newspace]; //tang kich thuoc cho mang a;
                for(int i=0;i<size;i++){ //Copy data tu mang odd sang mang a;
                    a[i]=odd[i];
                }
                delete[] odd; // xoa mang odd;
                space=newspace; // cap nhat khong gian toi da moi;
            }
        }
    public:
        Vector(){};
        Vector(int n1){
            size=0;
            space=n1;
            a=new T[n1];
        }
        ~Vector(){delete[] a;}
        
        T getElem(int i){
            return a[i];
        }
        int getSpace(){
            return space;
        }
        int getSize(){
            return size;
        }
         bool empty(){
            return size == 0;
        }
        Vector<T>& operator=(Vector<T>& p){
           if(this != &p){ //Neu 2 vector khac nhau;
            delete[] a;
            this->size=p.size;
            this->space=p.space;
            a=new T[space];
            for(int i=0;i<size;i++){
                a[i]=p.a[i];
            }
        }
        return *this;
        }
        void Push_Back(T elem){
            if(size==space){
                if(size == 0) space=1;
                else Expand(size * 2);
            }
            a[size]=elem;
            size++;
        }
        void Pop_Back(){
            size--;
        }
        void Insert(int pos, T elem){
            if(size == space){
                if (size == 0) space = 1;
                else Expand(size * 2);
            }
            for(int i=size;i>pos;i--){
                a[i]=a[i-1];
            }
            a[pos]=elem;
            size++;
        }
        void Erase(int pos){
            for(int i=pos;i<size-1;i++){
                a[i]=a[i+1];
            }
            size--;
        }
        void XoaThiSinh(int sobaodanh){
            int pos;
            for(int i=0;i<size;i++){
                if(a[i].SBD == sobaodanh){
                    pos = i;
                    Erase(pos);
                    break;
                }
            }
        }
        void HienThiVector(){
            for(int i=0;i<size;i++){
                cout<<a[i]<<endl;
            }
        }
        void HienThi(int sobaodanh){
            for(int i=0;i<size;i++){
                if(a[i].SBD == sobaodanh){
                    cout<<a[i];
                    break;
                }
            }
        }
        
};

template<class T>
class Iterator{
    private:
        T *curr;
    public:
        Iterator(T *c=0){curr=0;}
        Iterator<T> &operator=(Iterator<T> &it){
            this->curr=it->curr;
            return *this;
        }
        Iterator<T> operator++(){
            curr--;
            return curr;
        }
};

class ThiSinh{
    public:
        int SBD;
        string HoTen;
        int NamSinh;
        string GioiTinh;
        int Diem;

        ThiSinh(){};
        ThiSinh(int number, string name, int year, string gender, int point){
            SBD=number;
            HoTen=name;
            NamSinh=year;
            GioiTinh=gender;
            Diem=point;
        }
        
        friend istream& operator>>(istream& is, ThiSinh& p){
            is>>p.SBD;
            is.ignore();
            getline(is,p.HoTen);
            is>>p.NamSinh;
            is.ignore();
            getline(is,p.GioiTinh);
            is>>p.Diem;
            return is;
        }
        friend ostream& operator<<(ostream& os, ThiSinh& p){
            os<<"So Bao Danh: "<<p.SBD<<endl;
            os<<"Ho Ten: "<<p.HoTen<<endl;
            os<<"Nam Sinh: "<<p.NamSinh<<endl;
            os<<"Gioi Tinh: "<<p.GioiTinh<<endl;
            os<<"Diem: "<<p.Diem<<endl;
            return os;
        }
        void HienThiThiSinh(){
            cout << "SBD: " << SBD << ", Ho Ten: " << HoTen
             << ", Nam Sinh: " << NamSinh << ", Gioi Tinh: " << GioiTinh
             << ", Diem: " << Diem << endl;
        }
        // int getSBD(){
        //     return SBD;
        // }
        // string getName(){
        //     return HoTen;
        // }
        // int getYear(){
        //     return NamSinh;
        // }
        // string getGender(){
        //     return GioiTinh;
        // }
        // int getPoint(){
        //     return Diem;
        // }

};
int main(){
    //Doc danh sach tu file
    ifstream ip("input.txt");
    int n; ip>>n;
    Vector<ThiSinh> p(n);
    ThiSinh a[n];
    for(int i=0;i<n;i++){
        ip>>a[i];
        p.Push_Back(a[i]);
    }
    ip.close();
    p.Push_Back(ThiSinh(6,"Le Dinh Huan",2000,"Nam",2)); // Bo sung vao cuoi
    p.XoaThiSinh(3); // Xoa thi sinh khi biet so bao danh
    cout<<"Danh sach thi sinh sau khi xoa: "<<endl;
    p.HienThiVector();
    cout<<"Thong tin thi sinh can tim: "<<endl;
    p.HienThi(2);
    
}