#include<iostream>
#include<ctime>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> vec;
int bs(int left,int right,int element)
{
    int mid=(left+right)/2;
    if(vec[mid]==element)
        return mid;
    if(right<left)
        return -1;
    if(vec[mid]!=vec[left]&&vec[mid]!=vec[right])
    {
        if(element<vec[mid]&&element>=vec[left])
            return bs(left,mid-1,element);
        else
            return bs(mid+1,right,element);
    }
    else if(vec[mid]!=vec[right])
        return bs(mid+1,right,element);
    else if(vec[mid]!=vec[left])
        return bs(left,mid-1,element);
    else
    {
        int result=bs(left,mid-1,element);
        if(result==-1)
            result=bs(mid+1,right,element);
        return result;
    }
    return -1;
}
int main()
{
    srand(time(NULL));
    for(int i=0;i<10;i++)
        vec.push_back(rand()%100);
    sort(vec.begin(),vec.end());
    for(int i=0;i<10;i++)
        cout<<vec[i]<<" ";
    for(int i=0;i<4;i++)
        rotate(vec.begin(),vec.begin()+(rand()%10)+1,vec.end());
    cout<<endl;
    for(int i=0;i<10;i++)
        cout<<vec[i]<<" ";
    int element=vec[rand()%10];
    cout<<endl<<element<<endl;
    cout<<bs(0,vec.size()-1,element);
}
