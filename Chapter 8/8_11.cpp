#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> denoms;
long long change(int V,int i)
{
    if(i==denoms.size()-1)
        return 1;
    int current=denoms[i];
    long long ways=0;
    for(int j=0;j*current<=V;j++)
        ways+=change(V-j*current,i+1);
    return ways;
}
int main()
{
    int n,m;
    cin>>n>>m;
    denoms.resize(m);
    for(int i=0;i<m;i++)
        cin>>denoms[i];
    sort(denoms.begin(),denoms.end(),greater<long long>());
    for(int i=0;i<m;i++)
        cout<<denoms[i];
    cout<<change(n,0);
}
