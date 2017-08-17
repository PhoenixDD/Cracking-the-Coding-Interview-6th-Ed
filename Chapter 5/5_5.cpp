#include<iostream>
#include<bitset>
using namespace std;
int numofflips(int n1,int n2)
{
    int Xor=n1^n2,counter=0;
    while(Xor)
    {
        if(Xor&1)
            counter++;
        Xor>>=1;
    }
    return counter;
}
int main()
{
    int number1=14510,num2=19734;
    bitset<15> binary(number1);
    cout<<binary<<endl;
    binary=num2;
    cout<<binary<<endl;
    cout<<numofflips(number1,num2);
}
