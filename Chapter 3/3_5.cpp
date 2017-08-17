#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stack>
using namespace std;
void Sort(stack<int> &s)
{
    stack<int> s1;
    while(!s.empty())
    {
        int temp=s.top();s.pop();
        while(!s1.empty()&&s1.top()>temp)
        {
            s.push(s1.top());
            s1.pop();
        }
        s1.push(temp);
    }
    while(!s1.empty())
    {
        s.push(s1.top());
        s1.pop();
    }
}
int main()
{
    stack<int> s;
    int i=30;
    srand((int)time(0));
    while(--i)
    {
        int random=rand()%1000;
        cout<<random<<" ";
        s.push(random);
    }
    cout<<endl<<s.top()<<endl;
    Sort(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
