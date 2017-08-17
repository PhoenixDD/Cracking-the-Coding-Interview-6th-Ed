#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;
merge(vector<int> &A,vector<int> &B)
{
    int i=2,j=B.size()-1,k=A.size()-1;
    while(i>=0&&j>=0)
    {
        if(A[i]>B[j])
            A[k--]=A[i--];
        else
            A[k--]=B[j--];
    }
    while(i>=0)
        A[k--]=A[i--];
    while(j>=0)
        A[k--]=B[j--];
}
int main()
{
    srand(time(NULL));
    vector<int> A(10),B(7);
    for(int i=0;i<10;i++)
    {
        if(i<3)
            A[i]=rand()%1000;
        if(i<B.size())
            B[i]=rand()%1000;
    }
    sort(A.begin(),A.begin()+3);
    sort(B.begin(),B.end());
    for(int i=0;i<3;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;
    merge(A,B);
    for(int i=0;i<10;i++)
    {
        cout<<A[i]<<" ";
    }

}
