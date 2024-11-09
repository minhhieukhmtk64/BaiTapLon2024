#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node{
    private:
        T data;
        Node *next;
    public:
        Node(){}
        Node(T data1, Node<T> *head){
            data=data1;
            next=head;
        }
        void setData(T data1){
            data=data1;
        }
        T getData(){
            return data;
        }
        void setNext(Node<T> *head){
            next=head;
        }
        Node<T> *getNext(){
            return next;
        }
};

template<class T>
class Stack{
    private:
        int size;
        Node<T> *h;
    public:
        Stack(){};
        int getSize(){
            return size;
        }
        bool Empty(){
            return size == 0;
        }
        T &getTop(){
            return h->data;
        }
        void Pop(){
            if(size<=1){size=0;h=NULL;return;}
            h=h->getNext();
            size--;
        }
        void push(T x){
            h = new node<T>(x,h);
            size++;
        }
        
};
int main(){

}