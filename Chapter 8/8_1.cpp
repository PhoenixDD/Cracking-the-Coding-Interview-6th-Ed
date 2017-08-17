#include<iostream>
using namespace std;
#define N 5
int counter=0;
int hops[]={1,2,3};
int memo[N];
void countsteps(int N)
{
    if(N==1)
    {
        counter++;
        return;
    }
    for(int i=0;i<3;i++)
    {
        if(memo[i]!=-1)
            counter++;
        else if(N>hops[i])
            countsteps(N-hops[i]);
    }
    return;
}
int main()
{
    for(int i=0;i<N;i++)
        memo[i]=-1;
    countsteps(N);
    cout<<counter<<endl;
}
