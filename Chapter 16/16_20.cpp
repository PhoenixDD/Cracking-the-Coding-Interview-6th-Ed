#include<iostream>
#include<vector>
using namespace std;
vector<string> t9;
void words(int num,string str)
{
    if(num==0)
    {
        count++;
        for(int i=str.length()-1;i>=0;i--)
            cout<<str[i];
        cout<<endl;
        return;
    }
    for(auto i:t9[num%10])
        words(num/10,str+i);
}
int main()
{
    t9.push_back("");
    t9.push_back("");
    t9.push_back("abc");
    t9.push_back("def");
    t9.push_back("ghi");
    t9.push_back("jkl");
    t9.push_back("mno");
    t9.push_back("pqrs");
    t9.push_back("tuv");
    t9.push_back("wxyz");
    words(8733,"");
}
