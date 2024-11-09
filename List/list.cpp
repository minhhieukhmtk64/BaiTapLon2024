#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node{
    private:
        T data;
        Node *next;
    public:
        Node(){
            data = 0;
            next = NULL;
        }
        Node (T val, Node<T> *head=NULL){
            data = val;
            next = head;
        }
        void SetData(T newdata){
            data=newdata;
        }
        T GetData(){
            return data;
        }
        void SetNext(Node<T> newNext=NULL){
            next = newNext;
        }
        Node<T> *GetNext(){
            return next;
        }
};

template <class T>
class Single_List{
    private:
        Node<T> *header;
        Node<T> *trailer;
        int size;
    public:
    Single_List(){
        header = trailer = NULL;
        size = 0;
    }
    int GetSize(){
        return size;
    }
    bool Empty(){
        return size==0;
    }

    //Lay gia tri node dau
    T &Front(){
        return header->GetData();
    }
    //Lay gia tri node cuoi
    T &Back(){
        return trailer->GetData();
    }
    void Push_Front(T elem){
        
    }
};

int main(){
    Node<int> B(1), A(2,&B);
    cout<<B.GetNext();

}