#include<iostream>
#include<vector>
using namespace std;
merge(vector<int> &unsorted,int beg,int middle,int end)
{
    vector<int> left(middle-beg+1),right(end-middle);
    for(int i=0,j=beg;j<=middle;j++,i++)
        left[i]=unsorted[j];
    for(int i=0,j=middle+1;j<=end;j++,i++)
        right[i]=unsorted[j];
    int i=0,j=0,k=beg;
    while(i<left.size()&&j<right.size())
    {
        if(left[i]<=right[j])
        {
            unsorted[k]=left[i];
            i++;
            k++;
        }
        else
        {
            unsorted[k]=right[j];
            j++;
            k++;
        }
    }
    while(j<right.size())
    {
        unsorted[k]=right[j];
        k++;j++;
    }
    while(i<left.size())
    {
        unsorted[k]=left[i];
        k++;i++;
    }
}
void mergesort(vector<int> &unsorted,int beg,int end)
{
    if(beg<end)
    {
        mergesort(unsorted,beg,(beg+end)/2);
        mergesort(unsorted,(beg+end)/2+1,end);
        merge(unsorted,beg,(beg+end)/2,end);
    }
}
int main()
{
    vector<int> vec(10);
    for(int i=0;i<10;i++)
        cin>>vec[i];
    mergesort(vec,0,vec.size()-1);
    for(int i=0;i<10;i++)
        cout<<vec[i]<<" ";
}
