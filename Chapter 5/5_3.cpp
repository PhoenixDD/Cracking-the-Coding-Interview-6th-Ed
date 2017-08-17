#include<iostream>
#include<bitset>
using namespace std;
void contiguous(int number)
{
    int j=0,sequence=0,sequence0=0,maxl=0;
    while(j<sizeof(number)*8)
    {

        if(number&1<<j)
            sequence++;
        else
        {
            sequence0=sequence;
            sequence=0;
        }
        maxl=max(sequence0+sequence+1,maxl);
        j++;
        cout<<maxl;
    }
}
int main()
{
    int number=14510;
    bitset<11> binary(number);
    cout<<binary<<endl;
    contiguous(number);
}
