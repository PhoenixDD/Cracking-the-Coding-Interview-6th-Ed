#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    int number;
    bool visited=false;
    Node* Next=NULL;
    Node(int num)
    {
        number=num;
    }
};
bool checkpath(vector<Node*> *adjlist,int from,int to)
{
    if(from==to)
            return true;
    if((*adjlist)[from])
    {
        cout<<from<<" ";
        Node *temp=(*adjlist)[from];
        while(temp)
        {
            checkpath(adjlist,temp->number,to))
                return true;+
            temp=temp->Next;
        }
        cout<<endl;
    }
    return false;
}
int main()
{
    vector<Node*> adjlist(12);
    int from,to;
    for(int i=0;i<18;i++)
    {
        cin>>from>>to;
        if(adjlist[from])
        {
            Node *temp=adjlist[from];
            while(temp->Next)
                temp=temp->Next;
            temp->Next=new Node(to);
        }
        else
            adjlist[from]=new Node(to);
    }
    for(int i=0;i<12;i++)
    {
        Node* temp=adjlist[i];
        while(temp)
        {
            cout<<temp->number<<"->";
            temp=temp->Next;
        }
        cout<<endl;
    }
    cin>>from;
    cin>>to;
    if(checkpath(&adjlist,from,to))
        cout<<"yes";
}
