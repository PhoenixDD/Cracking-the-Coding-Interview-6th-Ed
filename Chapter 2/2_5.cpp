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
Node* add(Node *head1,Node *head2)
{
    int temp=head1->data+head2->data;
    bool carry=false;
    if(temp>=10)
    {
        temp=temp%10;
        carry=true;
    }
    Node *sum=new Node(temp),*head=sum;
    head1=head1->Next;head2=head2->Next;
    while(head1||head2)
    {
        if(carry)
        {
            sum->Next=new Node(1,sum);
            carry=false;
        }
        else
            sum->Next=new Node(0,sum);
        sum=sum->Next;
        if(head2&&head1)
        {
            temp=head1->data+head2->data+sum->data;
            head1=head1->Next;
            head2=head2->Next;
        }
        else if(head2)
        {
            temp=head2->data+sum->data;
            head2=head2->Next;
        }
        else
        {
            temp=head1->data+sum->data;
            head1=head1->Next;
        }
        if(temp>=10)
        {
            sum->data=temp%10;
            carry=true;
        }
        else
            sum->data=temp;
    }
    if(carry)
        sum->Next=new Node(1,sum);
    cout<<endl;
    while(head)
    {
        cout<<head->data<<",";
        head=head->Next;
    }
}
int main()
{
    Node *head1=new Node(5),*head2=new Node(8);
    int i=5,j=5;
    Node *temp;
    temp=head1;
    srand((int)time(0));
    while(--i)
    {
        temp->Next=new Node(rand()%10,temp);
        temp=temp->Next;
    }
    temp=head2;
    while(--j)
    {
        temp->Next=new Node(rand()%10,temp);
        temp=temp->Next;
    }
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
    add(head1,head2);
}

