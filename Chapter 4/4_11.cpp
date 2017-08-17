#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int totalpaths=0;
unordered_map<int,int> hashsum;
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
void dfs(Node* root,int running,int sum)
{
    if(!root)
        return;
    running+=root->data;
    if(running==sum)
        totalpaths++;
    totalpaths+=hashsum[running-sum];
    hashsum[running]++;
    dfs(root->left,running,sum);
    dfs(root->right,running,sum);
    hashsum[running]--;
}
int main()
{
    Node *Root;
    Root=new Node(1,new Node(2,new Node(3,new Node(0)),new Node(-1,new Node(1))),new Node(3,new Node(-1,new Node(2,new Node(1))),new Node(1)));
    dfs(Root,0,3);
    cout<<totalpaths;

}
