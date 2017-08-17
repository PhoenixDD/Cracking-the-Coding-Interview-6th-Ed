#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    Node* left=NULL,*right=NULL;
    Node(int dat,Node* lft=NULL,Node* rgt=NULL)
    {
        data=dat;
        left=lft;
        right=rgt;
    }
};
bool isbinary(Node *Root,int Min,int Max)
{
    if(!Root)
        return true;
    if(Root->data>Max||Root->data<Min)
        return false;
    return isbinary(Root->left,Min,Root->data)&&isbinary(Root->right,Root->data,Max);
}
int main()
{
    Node* Root;
    Root=new Node(50,new Node(20,new Node(1,new Node(0)),new Node(25)),new Node(55,new Node(54,new Node(50)),new Node(100)));
    cout<<isbinary(Root,INT_MIN,INT_MAX);
}
