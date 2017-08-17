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
Node* common(Node* head1,Node* head2)
{
    int counter=0;
    Node* temp=head1;
    while(temp)
    {
        counter++;
        temp=temp->Next;
    }
    temp=head2;
    while(temp)
    {
        counter--;
        temp=temp->Next;
    }
    cout<<counter;
    Node* temp1=head2;
    temp=head1;
    if(counter<0)
        while(counter++)
            temp1=temp1->Next;
    else if(counter>0)
        while(--counter)
            temp=temp->Next;
    while(temp&&temp1)
    {
        if(temp1==temp)
            break;
        temp=temp->Next;
        temp1=temp1->Next;
    }
    cout<<temp->data;
}
int main()
{
    Node *head1=new Node(5),*head2=new Node(8);
    int i=30,j=12;
    Node *temp;
    temp=head1;
    srand((int)time(0));
    while(--i)
    {
        temp->Next=new Node(rand()%50,temp);
        temp=temp->Next;
    }
    temp=head2;
    while(--j)
    {
        temp->Next=new Node(rand()%10,temp);
        temp=temp->Next;
    }
    temp->Next=head1->Next->Next->Next->Next->Next->Next->Next;
    temp=head1;
    cout<<"Data :\n";
    while(temp)
    {
        cout<<temp->data<<",";
        temp=temp->Next;
    }
    cout<<endl;
    temp=head2;
    while(temp)
    {
        cout<<temp->data<<",";
        temp=temp->Next;
    }
    common(head1,head2);
}

