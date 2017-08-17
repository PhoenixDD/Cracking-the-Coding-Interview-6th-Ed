#include<iostream>
#include<vector>
#include<algorithm>
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
bool checksubtree(Node *Root1,Node *Root2)
{
    if(!Root1&&!Root2)
        return true;
    else if(!Root1&&Root2)
        return false;
    else if(Root1&&!Root2)
        return true;
    else if(Root1->data!=Root2->data)
        return false;
    else
        return checksubtree(Root1->right,Root2->right)&&checksubtree(Root1->left,Root2->left);

}
bool check(Node *root1,Node *root2)
{
    if(!root1)
        return false;
    else if(root1->data==root2->data&&checksubtree(root1,root2))
        return true;
    else
        return check(root1->left,root2)||check(root1->right,root2);
}
int main()
{
    Node *Root1,*Root2;
    Root1=new Node(50,new Node(20,new Node(1,new Node(0)),new Node(25)),new Node(55,new Node(54,new Node(51)),new Node(100)));
    Root2=new Node(20,NULL,new Node(25,new Node(1)));
    cout<<check(Root1,Root2);
}
