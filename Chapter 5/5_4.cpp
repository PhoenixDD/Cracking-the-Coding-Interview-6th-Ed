#include<iostream>
#include<bitset>
using namespace std;
int getnext(int number)
{
    int j=0,i;
    while(!(number&1<<j))
        j++;
    i=j;
    while(number&1<<j)
        j++;
    number|=1<<j;
    number&=~0<<j;
    number|=(1<<j-i-1)-1;
    bitset<11> binary(number);
    cout<<binary;
    return number;
}
int getprev(int number)
{
    int j=0,i;
    while(number&1<<j)
        j++;
    i=j;
    while(!(number&1<<j))
        j++;
    number&=~0<<j+1;
    number|=1<<j-1;
    number|=((1<<i)-1)<<j-i;
    bitset<11> binary(number);
    cout<<binary;
    return number;
}
int main()
{
    int number=14510;
    bitset<14> binary(number);
    cout<<binary<<endl;
    cout<<endl<<getnext(number)<<endl;
    cout<<endl<<getprev(number);
}
