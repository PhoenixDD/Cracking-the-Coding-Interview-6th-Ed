#include<iostream>
#include<vector>
using namespace std;
vector<int> vec;
int findind(int beg,int end)
{
    int mid=(end+beg)/2;
    cout<<beg<<" "<<end<<endl;
    if(vec[mid]==mid)
        return mid;
    if(beg>end)
        return -1;
    int left=findind(beg,min(mid-1,vec[mid]));
    if(left!=-1)
        return left;
    int right=findind(max(vec[mid],mid+1),end);
    if(right!=-1)
        return right;
    return -1;
}
int main()
{
    vec.resize(10);
    vec[0]=1;
    vec[1]=2;
    vec[2]=3;
    vec[3]=3;
    vec[4]=6;
    vec[5]=6;
    vec[6]=7;
    vec[7]=8;
    vec[8]=9;
    vec[9]=10;
    cout<<findind(0,9);
}
