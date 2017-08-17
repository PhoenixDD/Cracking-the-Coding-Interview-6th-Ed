#include<iostream>
#include<stack>
using namespace std;
template<class T> class Queue
{
    stack<T> old,recent;
    public:
    void push(T element)
    {
        recent.push(element);
    }
    void shift()
    {
        if(old.empty())
        {
            while(!recent.empty())
            {
                old.push(recent.top());
                recent.pop();
            }
        }
    }
    T front()
    {
        shift();
        return old.top();

    }
    T pop()
    {
        shift();
        old.pop();
    }
};
int main()
{
    Queue<int> q;
    q.push(5);q.push(6);q.push(7);q.push(8);
    cout<<q.front();
    q.pop();
}
