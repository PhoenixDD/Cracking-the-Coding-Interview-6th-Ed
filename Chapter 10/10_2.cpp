#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<string> A;
    A.push_back("ABC");A.push_back("ZYX");A.push_back("CAB");A.push_back("XYZ");A.push_back("BCA");
    unordered_map<string,vector<string>> a;
    for(auto i:A)
    {
        string item=i;
        sort(i.begin(),i.end());
        string key=i;
        a[key].push_back(item);
    }
    int k=0;
    for(auto i:a)
    {
        for(auto j:i.second)
            A[k++]=j;
    }
    for(auto i:A)
        cout<<i<<endl;
}
