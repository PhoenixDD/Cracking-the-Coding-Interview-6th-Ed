#include<iostream>
using namespace std;
int multiply(int a,int b)
{
    if(a==0)
        return 0;
    if(a==1)
        return b;
    int num1=multiply(a>>1,b);
    if(a&1)
        return num1+num1+b;
    return num1+num1;
}
int main()
{
    int a=100000,b=10000;
    cout<<multiply(b,a);
}
