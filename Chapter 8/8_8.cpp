#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
void Permute(unordered_map<char,int> map,string str,int remaining)
{
    if(remaining==0)
    {
        cout<<str<<endl;
        return;
    }
    for(auto &i:map)
    {
        if(i.second>0)
        {
            i.second--;
            Permute(map,str+i.first,remaining-1);
            i.second++;
        }
    }
}
int main()
{
    unordered_map<char,int> freq;
    string str="aaaa";
    freq.reserve(str.length());
    for(auto i:str)
        freq[i]++;
    Permute(freq,"",str.length());

}
