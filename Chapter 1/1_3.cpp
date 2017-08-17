#include<iostream>
#include<algorithm>
using namespace std;
void urlify(string &str)
{
    int spcount=0;
    for(int i=0;i<str.length();i++)
        if(str[i]==' ')
            spcount++;
    str.resize(str.length()+2*spcount);
    for(int i=str.length()+2*spcount-1,j=str.length()-1;i>=0;i--,j--)
    {

        if(str[j]==' ')
        {
            str[i]='0';
            str[i-1]='2';
            str[i-2]='%';
            i-=2;
        }
        else
            str[i]=str[j];
    }
}
int main()
{
    string test;
    test.insert(0,"My boss is a doofus");
    urlify(test);
    cout<<test;
}
