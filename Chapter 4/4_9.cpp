#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
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
vector<int> outcomes;
void possible(vector<int> outcomes,int d,int n)
{
    if(pow(2,d)-1>n)
    {
        for(auto i:outcomes)
                cout<<i<<" ";
            cout<<endl;
        return;
    }
    int upto;
    if(pow(2,d)-1+pow(2,d)-n>0)
        upto=pow(2,d)-1+pow(2,d)-(pow(2,d)-1+pow(2,d)-n);
    else
        upto=pow(2,d)-1+pow(2,d);
    do
    {
        possible(outcomes,d+1,n);
    }while(next_permutation(outcomes.begin()+pow(2,d)-1,outcomes.begin()+upto));
}
int main()
{
    Node* Root;
    Root=new Node(50,new Node(20,new Node(1,new Node(0)),new Node(25)),new Node(55,new Node(54,new Node(51)),new Node(100)));
    outcomes.reserve(100);
    outcomes.push_back(1);outcomes.push_back(10);outcomes.push_back(17),outcomes.push_back(18),outcomes.push_back(1),outcomes.push_back(0),outcomes.push_back(5),outcomes.push_back(6),outcomes.push_back(2),outcomes.push_back(56);
    possible(outcomes,1,10);
}
