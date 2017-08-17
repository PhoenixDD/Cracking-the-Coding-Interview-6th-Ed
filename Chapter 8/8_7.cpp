#include<iostream>
#include<string>
using namespace std;
string store;
void Permute(int start,string input)
{
    if(start==input.length())
    {
        cout<<input<<endl;
        return;
    }
    for (int i=start;i<input.length();i++)
    {
        swap(input[i], input[start]);
        Permute(start + 1, input);
        swap(input[i],input[start]);
    }
}
int main()
{
    Permute(0,"abc");
}
