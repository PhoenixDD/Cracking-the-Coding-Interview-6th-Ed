#include<iostream>
#include<queue>
using namespace std;
struct TNode
{
    int data;
    TNode* left=NULL,*right=NULL;
    TNode(int dat,TNode* lft=NULL,TNode* rgt=NULL)
    {
        data=dat;
        left=lft;
        right=rgt;
    }
};
struct Node
{
    int data;
    Node* Next=NULL,*Prev=NULL;
    Node(int dat,Node* nxt=NULL,Node* prev=NULL)
    {
        data=dat;
        Next=nxt;
        Prev=prev;
    }
};
vector<Node*> BFS(TNode* root)
{
    vector<Node*> lists;
    int counter=0;
    queue<TNode*> current,previous;
    current.push(root);
    lists.push_back(new Node(root->data));
    counter++;
    while(!current.empty()||!previous.empty()){
    if(!current.empty())
    {
        while(!current.empty())
        {
            TNode* node=current.front();
            current.pop();
            if(node->left)
            {
                previous.push(node->left);
                if(lists.size()<=counter)
                    lists.push_back(new Node(node->left->data));
                else
                    lists[counter]=new Node(node->left->data,lists[counter]);
            }
            if(node->right)
            {
                previous.push(node->right);
                if(lists.size()<=counter)
                    lists.push_back(new Node(node->right->data));
                else
                    lists[counter]=new Node(node->right->data,lists[counter]);
            }
        }
        counter++;
    }
    if(!previous.empty())
    {
        while(!previous.empty())
        {
            TNode* node=previous.front();
            previous.pop();
            if(node->left)
            {
                current.push(node->left);
                if(lists.size()<=counter)
                    lists.push_back(new Node(node->left->data));
                else
                    lists[counter]=new Node(node->left->data,lists[counter]);
            }
            if(node->right)
            {
                current.push(node->right);
                if(lists.size()<=counter)
                    lists.push_back(new Node(node->right->data));
                else
                    lists[counter]=new Node(node->right->data,lists[counter]);
            }
        }
        counter++;
    }
    }
    return lists;
}
int main()
{
    TNode* Root;
    Root=new TNode(50,new TNode(20,new TNode(1,new TNode(60)),new TNode(5)),new TNode(25,new TNode(16,new TNode(100)),new TNode(2)));
    vector<Node*> lists=BFS(Root);
    for(auto i:lists)
    {
        while(i)
        {
            cout<<i->data<<" ";
            i=i->Next;
        }
        cout<<endl;
    }
}
