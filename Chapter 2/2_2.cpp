#include<iostream>
#include<cstdlib>
#include<ctime>
#include<unordered_set>
using namespace std;
struct Node
{
    int data;
    Node* Next;
    Node* Prev;
    Node(int a,Node* pr=NULL,Node* nxt=NULL)
    {
        data=a;
        Next=nxt;
        Prev=pr;
    }
};
Node* kth(Node *head,int k)
{
    Node *temp=head,*kth=head;
    int counter=0;
    while(temp)
    {
        if(counter>k)
            kth=kth->Next;
        counter++;
        temp=temp->Next;
    }
    cout<<endl<<kth->data;

}
int main()
{
    Node *head=new Node(50);
    int i=30;
    Node *temp;
    temp=head;
    srand((int)time(0));
    while(--i)
    {
        temp->Next=new Node(rand()%50,temp);
        temp=temp->Next;
    }
    temp=head;
    cout<<"Data :\t";
    while(temp)
    {
        cout<<temp->data<<",";
        temp=temp->Next;
    }
    kth(head,10);
}

