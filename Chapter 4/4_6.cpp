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
Node* findnode(Node* Root,int data)
{
    if(Root->data==data)
        return Root;
    else if(Root->data>data)
        findnode(Root->left,data);
    else
        findnode(Root->right,data);
}
int succ(Node* Root,int data)
{
    Node *begining=findnode(Root,data);
    begining=begining->right;
    while(begining->left)
        begining=begining->left;
    return begining->data;
}
int main()
{
    Node* Root;
    Root=new Node(50,new Node(20,new Node(1,new Node(0)),new Node(25)]j),new Node(55,new Node(54,new Node(51)),new Node(100)));
    cout<<succ(Root,25);
}

