#include<iostream>
using namespace std;
int negative(int a)
{
    return ~a+1;
}
int multiply(int a,int b)
{
    int result=0;
    bool isneg=false;
    if(a<0&&b<0)
    {
        a=negative(a);
        b=negative(b);
    }
    else if(a<0)
    {
        a=negative(a);
        isneg=true;
    }
    else if(b<0)
    {
        b=negative(b);
        isneg=true;
    }
    for(int i=0;i<b;i++)
        result+=a;
    if(isneg)
        return negative(result);
    else
        return result;
}
int divide(int a,int b)
{
    int i=1;
    bool isneg=false;
    if(a<0&&b<0)
    {
        a=negative(a);
        b=negative(b);
    }
    else if(a<0)
    {
        a=negative(a);
        isneg=true;
    }
    else if(b<0)
    {
        b=negative(b);
        isneg=true;
    }
    while(multiply(b,i)!=a)
        i++;
    if(isneg)
        return negative(i);
    else
        return i;
}
int main()
{
    cout<<divide(-15,-3);
}
