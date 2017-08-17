#include<iostream>
#include<bitset>
using namespace std;
int insertion(int M,int N,int i,int j)
{
    int mask=~0<<j+1|(1<<i)-1;
    M&=mask;
    M|=N<<i;
    return M;
}
int main()
{
    int M=500,N=5,j=5,i=3;
    bitset<11> m(M),n(N),K(insertion(M,N,i,j));
    cout<<m<<" "<<n<<" "<<K;
}
