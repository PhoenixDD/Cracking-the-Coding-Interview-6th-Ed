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
Node* ins(int arr[],int strt,int en)
{
    if(strt<=en)
    {
        Node *root=new Node(arr[(strt+en)/2]);
        root->left=ins(arr,strt,(strt+en)/2-1);
        root->right=ins(arr,(strt+en)/2+1,en);
        return root;
    }
    else
        return NULL;
}
int main()
{
    int arr[]={1,12,18,21,27,31,36,48,50};
    Node *root=ins(arr,0,8);
    cout<<root->right->left->data;
    while(root)
    {
        cout<<root->data;
        root=root->right;
    }
}
