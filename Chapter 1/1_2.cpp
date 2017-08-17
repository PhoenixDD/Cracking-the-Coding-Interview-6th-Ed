#include<iostream>
#include<algorithm>
using namespace std;
int isperm1(string str1,string str2)
{
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    if(!str1.compare(str2))
        return 1;
    return 0;
}
int isperm2(string str1,string str2)
{
    int check[256]={0};
    for(int i=0;i<str1.length();i++)
        check[str1[i]]++;
    for(int i=0;i<str2.length();i++)
    {
        check[str2[i]]--;
        if(check[str2[i]]<0)
            return 0;
    }
    return 1;
}
int main()
{
    string test1="klftscza",test2="altfsczk";
    if(isperm1(test1,test2))
        cout<<"Yes";
    else
        cout<<"No";
    if(isperm2(test1,test2))
        cout<<"Yes";
    else
        cout<<"No";
}

