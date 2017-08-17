#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
struct Node
{
    int data;
    Node* Next,*least=this;
    Node(int a,Node* nxt=NULL,Node* smallest=NULL):data(a),Next(nxt){least=smallest==NULL?least:smallest;}
}*top=NULL;
void push(int data)
{
    if(!top)
        top=new Node(data);
    else
        top=new Node(data,top,top->least->data<data?top->least:NULL);
}
int pop()
{
    if(top)
    {
        int data=top->data;
        Node* free=top;
        top=top->Next;
        delete free;
        return data;
    }
    return -1;
}
int main()
{
    int i=30;
    srand((int)time(0));
    while(--i)
    {
        int random=rand()%1000;
        cout<<random<<" ";
        push(random);
    }
    cout<<endl<<top->least->data;
    char c='y';
    while(c!='n')
    {
        cin>>c;
        pop();
        cout<<endl<<top->least->data;
    }
}
