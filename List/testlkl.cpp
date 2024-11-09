#include<bits/stdc++.h>
using namespace std;

//Node
template<class T>

class Node{
    private:
        T data;
        Node *next;
    public:
        Node(){};
        //Tao node moi
        Node(T x, Node<T> *head=NULL){
            data=x;
            next=head;
        }

        //Gan gia tri cua x cho thuoc tinh data
        void SetData(T x){
            data=x;
        }

        //Gan dia chi cho thuoc tinh next
        void SetNext(Node<T> *head=NULL){
            next=head;
        }

        //Tra lai phan tu luu tru trong Node
        T GetData(){
            return data;
        }

        //Tra lai dia chi nut ke tiep
        Node<T> *GetNext(){
            return next;
        }
};

//Bo lap cua Node
template<class P>

class iterator{
    private:
        Node<P> *curr; //con tro tro vao node hien tai
    public:
        iterator(){ curr = NULL; }
        iterator(Node<T> *p){
            curr = p;
        }
        // Tra ve dia chi cua curr
        Node<P> *GetCurr(){
            return curr;
        }

        // Nap chong toan tu =
        iterator<P>& operator=(iterator &p){
            this->curr=p.GetCurr();
            return *this;
        }

        //Kiem tra 

};

main(){
    Node<int> A, B(1), C(2,&B);
    B.SetNext(&A);
    A.SetData(10);
    Node<int> *D= new Node<int>(9,&C);
    for(Node<int> *it = D; it!=NULL;it=it->GetNext()){
        cout<<it->GetData()<<"\t";
    }
	
}