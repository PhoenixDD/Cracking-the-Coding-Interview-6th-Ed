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
Node* remdups(Node *head)
{
    unordered_set<int> duplicate_check;
    Node *temp=head;
    while(temp)
    {
        if(duplicate_check.find(temp->data)==duplicate_check.end())
            duplicate_check.insert(temp->data);
        else
        {
            temp->Prev->Next=temp->Next;
        }
        temp=temp->Next;
    }
    temp=head;
    cout<<endl<<"Data After:\t";
    while(temp)
    {
        cout<<temp->data<<",";
        temp=temp->Next;
    }
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
    cout<<"Data Before:\t";
    while(temp)
    {
        cout<<temp->data<<",";
        temp=temp->Next;
    }
    remdups(head);
}
