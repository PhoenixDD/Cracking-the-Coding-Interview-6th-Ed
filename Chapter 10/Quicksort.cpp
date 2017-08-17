#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &unsorted,int left,int right)
{
    int i=left,j=right-1;
    while(i<j)
    {
        while(i<=j&&unsorted[i]<=unsorted[right])i++;
        while(i<=j&&unsorted[j]>unsorted[right])j--;
        if(i<j)
            swap(unsorted[i],unsorted[j]);
    }
    swap(unsorted[i],unsorted[right]);
    return i;
}
void quicksort(vector<int> &unsorted,int left,int right)
{
    if(left<right)
    {
        int index=partition(unsorted,left,right);
        quicksort(unsorted,left,index-1);
        quicksort(unsorted,index+1,right);
    }
}
int main()
{
    vector<int> vec(10);
    for(int i=0;i<10;i++)
        cin>>vec[i];
    quicksort(vec,0,vec.size()-1);
    for(int i=0;i<10;i++)
        cout<<vec[i]<<" ";
}
