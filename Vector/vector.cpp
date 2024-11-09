#include<bits/stdc++.h>
using namespace std;

template<class T>

class Vector{
    private:
        int size,space; // space la dung luong toi da cua vector
        T *a;
        void Expand(int newSpace){
            if(newSpace <= size) return;
            T* old=a;
            a=new T[newSpace];
            for(int i=0;i<size;i++){
                a[i]=old[i];
            }
            delete[] old;
            space=newSpace;
        }
    public:
        //Ham tao
        Vector(int n=100){
            size=0;
            space=n;
            a=newT[n];
        }

        //Ham huy
        ~Vector(){delete[] a}

        //Ham nap chong toan tu
        Vector<T>& operator=(Vector<T>& p){
           if(this != &p){
            delete[]a;
            this->size=p.size;
            this->space=p.space;
            a=new T[space];
            for(int i=0;i<size;i++){
                a[i]=p.a[i];
            }
        }
            return *this;
        }
        
        int size(){
            return size;
        }
        bool empty(){
            return size==0;
        }
        
        void Push_Back(T newElem){
            // Gap doi space neu vector day
            if(size == space) expand(2 * size);
            a[size]=newElem;
            size++;
        }
        void Pop_Back(){
            size--;
        }
        void insert(int pos, T newElem){
            if(size == space) expand(2*size);
            for(int i=size;i>pos;i--){
                a[i]=a[i-1];
            }
            a[pos]=newElem;
            size++;
        }
        void erase(int pos){
            for(int i=pos;i<size-1;i++){
                a[i]=a[i+1];
            }
            size--;
        }
        void clear(){
            size = 0;
        }
        T get(int pos){
            return a[pos];  
        }
};

int main(){
    Vector<int> a;
    for(int i=0;i<5;i++){
        a.Push_Back(i);
    }
    cout<<a.get(3);
}