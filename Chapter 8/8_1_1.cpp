#include<iostream>
#include<vector>
using namespace std;
vector<int> memo;
int countsteps(int N)
{
    if(N==1)
        return memo[N]=1;
    else if(N<=0)
        return 0;
    else if(memo[N]!=-1)
            return memo[N];
    else
        return memo[N]=countsteps(N-1)+countsteps(N-2)+countsteps(N-3);
}
int main()
{
    int N=5;
    memo.resize(N+1,-1);
    cout<<countsteps(N);
}
