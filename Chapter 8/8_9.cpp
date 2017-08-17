#include<iostream>
#include<string>
using namespace std;
void paranthesis(int left,int right,string str)
{
    if(left==0&&right==0)
    {
        cout<<str<<endl;
        return;
    }
    else if(left<0||right<left)
        return;
    else
    {
        str+="(";
        paranthesis(left-1,right,str);
        str.pop_back();
        str+=")";
        paranthesis(left,right-1,str);
    }

}
int main()
{
    paranthesis(2,2,"");
}
