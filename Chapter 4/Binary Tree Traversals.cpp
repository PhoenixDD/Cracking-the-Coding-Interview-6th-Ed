#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    bool visited=false;
    Node* left=NULL,*right=NULL;
    Node(int dat,Node* lft=NULL,Node* rgt=NULL)
    {
        data=dat;
        left=lft;
        right=rgt;
    }
};
void inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<",";
        inorder(root->right);
    }
}
void preorder(Node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<",";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<",";
    }
}
void DFS(Node* root)
{
    if(root)
    {
        cout<<root->data<<",";
        root->visited=true;
        if(root->left&&!root->left->visited)
            DFS(root->left);
        if(root->right&&!root->right->visited)
            DFS(root->right);
    }
}
void BFS(Node* root)
{
    queue<Node*> bfs;
    bfs.push(root);
    while(!bfs.empty())
    {
        Node* node=bfs.front();
        bfs.pop();
        cout<<node->data<<",";
        if(node->left)
            bfs.push(node->left);
        if(node->right)
            bfs.push(node->right);
    }
}
int main()
{
    Node* Root;
    Root=new Node(50,new Node(20,new Node(1,new Node(60)),new Node(5)),new Node(25,new Node(16,new Node(100)),new Node(2)));
    inorder(Root);
    cout<<endl;
    preorder(Root);
    cout<<endl;
    postorder(Root);
    cout<<endl;
    DFS(Root);
    cout<<endl;
    BFS(Root);
}

