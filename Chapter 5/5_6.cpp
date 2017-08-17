#include<iostream>
#include<bitset>
using namespace std;
int swapodev(int number)
{
    return ((number&0xaaaa)>>1|(number&0x5555)<<1);
}
int main()
{
    int number=14510;
    bitset<15> binary(number);
    cout<<binary<<endl;
    binary=swapodev(number);
    cout<<binary;
}

