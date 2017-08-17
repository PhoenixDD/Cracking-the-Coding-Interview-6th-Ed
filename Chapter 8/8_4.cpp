#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int> powerset;
void getsubsets()
{
    for(int i=0;i<pow(2,powerset.size());i++)
    {
        for(int j=0;j<powerset.size();j++)
        {
            if(i&1<<j)
                cout<<powerset[j];
        }
        cout<<endl;
    }
}
int main()
{
    powerset.resize(4);
    powerset[0]=2;
    powerset[1]=3;
    powerset[2]=4;
    powerset[3]=1;
    getsubsets();
}
