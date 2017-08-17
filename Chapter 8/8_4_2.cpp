#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> pset;
stack<int> print;
void powersets(int psetidx,bool ins)
{
    if(psetidx==pset.size()-1)
    {
        if(ins)
            print.push(pset[psetidx]);
        if(!print.empty())
        {
            stack<int> temp=print;
            while(!temp.empty())
            {
                cout<<temp.top();
                temp.pop();
            }
            cout<<endl;
        }
        if(!print.empty()&&ins)
            print.pop();
        return;
    }
    else
    {
        if(ins)
            print.push(pset[psetidx]);
        powersets(psetidx+1,true);
        powersets(psetidx+1,false);
        if(!print.empty()&&ins)
            print.pop();
    }
}
int main()
{
    pset.push_back(1);
    pset.push_back(2);
    pset.push_back(3);
    powersets(0,true);
    powersets(0,false);
}
