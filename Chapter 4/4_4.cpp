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
int getheight(Node* Root)
{
    if(!Root)
        return -1;
    int left=getheight(Root->left);
    int right=getheight(Root->right);
    return left-right;

}
int isbalanced(Node *Root)
{
    if(!Root->right&&!Root->left)
        return 1;
    if(Root->left&&Root->right)
        return abs(isbalanced(Root->left)-isbalanced(Root->right))+1;
    else if(Root->right)
        return isbalanced(Root->right)+1;
    else
        return isbalanced(Root->left)+1;
}
int main()
{
    Node* Root;
    Root=new Node(50,new Node(20,new Node(21,new Node(60,new Node(5)))),new Node(25,new Node(16,new Node(100)),new Node(20)));
    cout<<isbalanced(Root)<<" "<<getheight(Root);
}
