#include<iostream>
#include<string>
using namespace std;
int palinperm(string str)
{
    int check=0;
    for(int i=0;i<str.length();i++)
            check^=1<<str[i]-'a';
    if(!check||(check&check-1)==0)
        return 1;
    return 0;
}
int main()
{
    string test="tatcta";
    if(palinperm(test))
        cout<<"Yes";
    else
        cout<<"No";
}
