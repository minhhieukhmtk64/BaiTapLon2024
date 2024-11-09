#include<bits/stdc++.h>
using namespace std;

template<class T>
class Stack{
    private:
        int size;
        int space;
        T *a;
        void Expand(int newspace){
            if(newspace <= size) return;
            else{
                T *temp=a;
                a=new T[newspace];
                for(int i=0;i<size;i++){
                    a[i]=temp[i];
                }
                if(temp) delete[] temp;
                space=newspace;
            }
        }
    public:
        Stack(){};
        Stack(int n1){
            size=0;
            space=n1;
            a=new T[n1];
        }
        int getSize(){
            return size;
        }
        int getSpace(){
            return space;
        }
        bool empty(){
            return size == 0;
        }
        T &getTop(){
            return a[size-1];
        }
        T getElem(int i){
            return a[i];
        }
        void Pop(){
            size--;
        }
        void Push(T val){
            if(size==space){
                if(size == 0) space=1;
                else Expand(size*2);
            }
            a[size]=val;
            size++;
        }
        void clear(){
            size=0;
        }
};

int main(){
    Stack<int> p(10);
    for(int i=0;i<5;i++){
        p.Push(i);
    }
    for(int i=0;i<5;i++){
        cout<<p.getElem(i)<<" ";
    }
    if(!p.empty()) cout<<endl<<"Stack khong rong !";
    else cout<<endl<<"Stack rong !";
}