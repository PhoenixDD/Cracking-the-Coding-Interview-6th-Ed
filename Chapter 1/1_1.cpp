#include<iostream>
#include<algorithm>
using namespace std;
int isunique1(string str)
{
    sort(str.begin(),str.end());
    for(int i=0;i<str.length()-1;i++)
    {
        if(str[i]==str[i+1])
            return 0;
    }
    return 1;
}
int isunique2(string str)
{
    int check=0;
    for(int i=0;i<str.length();i++)
    {
        if(check&1<<(str[i]-'a'))
            return 0;
        else
        {
            check|=1<<(str[i]-'a');
        }
    }
    return 1;
}
int main()
{
    string test="dlftscza";
    if(isunique1(test))
        cout<<"Yes";
    else
        cout<<"No";
    if(isunique2(test))
        cout<<"Yes";
    else
        cout<<"No";
}
