#include<iostream>
#include<bitset>
using namespace std;
string tostring(double number)
{
    if(number>1||number<0)
        return "ERROR";
    string num=".";
    while(number>0)
    {
        double r=number*2;
        if(r>=1)
        {
            num+="1";
            number=r-1;
        }
        else
        {
            num+="0";
            number=r;
        }

    }
    return num;
}
int main()
{
    double number=0.5;
}
