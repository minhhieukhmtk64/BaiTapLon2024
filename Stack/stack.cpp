#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Stack{
    private:
        int size;
        int space;
        T *elem;
    public:
        Stack(){
            size=space=0;
            elem=NULL;
        }
        ~Stack(){
            if(elem != NULL) delete[] elem;
        }
        int getSize(){
            return size;
        }
        bool empty(){
            return size==0;
        }
        T& top(){
            return elem[size-1];
        }
        void pop(){
            if(empty()) return;
            size--;
        }
        void clear(){
            size=0;
        }
        Stack<T>& operator=(Stack<T>& s){
            if(this == &s) return *this;
            this->size=s.size;
            this->space=s.space;
            if(elem != NULL) delete[]elem;
            elem = new T[space];
            for(int i=0;i<size;i++){
                elem=s.elem[i];
            }
            return *this;
        }
        
        void push(T val){ 
            if(size == space){
                space == size == 0 ? 1 : size*2;
                T* temp=new T[space];
                for(int i=0;i<size;i++){
                    temp[i]=elem[i];
                }
                if(elem!=NULL) delete[] elem;
                elem=temp;
            }
            elem[size] = val;
            size++; 
        }
        
};

int main(){
    Stack<int> st1;
    st1.push(0);
    st1.push(2);
    cout<<st1.getSize()<<endl;
}