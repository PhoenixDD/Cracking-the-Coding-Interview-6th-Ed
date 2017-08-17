#include<iostream>
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
Node* LCA(Node *Root,Node *A, Node *B)
{
    if(Root==NULL)
        return NULL;
    if(Root==A||Root==B)
        return Root;
    Node* left=LCA(Root->left,A,B);
    Node* right=LCA(Root->right,A,B);
    if(left&&right)
        return Root;
    else if(!left)
        return right;
    else if(!right)
        return left;

}
int main()
{
    Node* Root;
    Root=new Node(50,new Node(20,new Node(1,new Node(0)),new Node(25)),new Node(55,new Node(54,new Node(51)),new Node(100)));
    cout<<LCA(Root,findnode(Root,54),findnode(Root,100))->data;
}
