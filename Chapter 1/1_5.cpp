#include<iostream>
#include<string>
using namespace std;
int oneaway(string str1,string str2)
{
    string stra=str1.length()<=str2.length()?str1:str2,strb=str1.length()<=str2.length()?str2:str1;
    bool oneedit=false;
    for(int i=0,j=0;i<stra.length()&&j<strb.length();i++,j++)
    {
        if(stra[i]!=strb[j])
        {
            if(!oneedit&&stra.length()==strb.length())
                oneedit=true;
            else if(stra.length()==strb.length())
                return 0;
            else
            {
                if(i!=j)
                    return 0;
                i++;
            }
        }
    }
    return 1;
}
int main()
{
    string test1="pllae",test2="ptlae";
    if(oneaway(test1,test2))
        cout<<"yes";
    else
        cout<<"No";
}
