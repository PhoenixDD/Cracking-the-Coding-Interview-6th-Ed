#include<iostream>
#include<cstdlib>
#include<ctime>
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
Node* findloop(Node *head)
{
    Node *fastrunner=head,*slowrunner=head;
    do
    {
        fastrunner=fastrunner->Next->Next;
        slowrunner=slowrunner->Next;
    }while(fastrunner!=slowrunner);
    fastrunner=head;
    while(slowrunner!=fastrunner)
    {
        fastrunner=fastrunner->Next;
        slowrunner=slowrunner->Next;
    }
    cout<<fastrunner->data;
}
int main()
{
    Node *head=new Node(5);
    int i=30;
    Node *temp;
    temp=head;
    srand((int)time(0));
    while(--i)
    {
        temp->Next=new Node(rand()%100,temp);
        temp=temp->Next;
    }
    temp->Next=head->Next->Next->Next->Next->Next->Next;
    temp=head;
    cout<<"Data :\n";
    for(int i=0;i<32;i++)
    {
        cout<<temp->data<<",";
        temp=temp->Next;
    }
    findloop(head);

}
