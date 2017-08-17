#include<iostream>
#include<ctime>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int mindif(vector<int> A,vector<int> B)
{
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0;i<10;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    for(int i=0;i<10;i++)
        cout<<B[i]<<" ";
    cout<<endl;
    int i=0;
    int j=0;
    int min;
    while(i!=A.size()||j!=B.size())
    {

        min=std::min(abs(A[i]-B[j]),min);
        if(A[i]<=B[j]&&i<A.size())
            i++;
        else if(B[j]<=A[i]&&j<B.size())
            j++;
        else if(j<B.size())
            j++;
        else
            i++;

    }
    cout<<min;
    return 0;
}
int main()
{
    srand(time(NULL));
    vector<int> A(10),B(10);
    for(int i=0;i<10;i++)
    {
        A[i]=rand()%500;
        B[i]=rand()%500;
    }
    mindif(A,B);
}
