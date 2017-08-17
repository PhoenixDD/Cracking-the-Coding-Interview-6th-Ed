#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<vector<bool>> grid(5,vector<bool>(7,true));
struct pair_hash
{
    size_t operator()(const std::pair<int,int> &p) const
    {
        return p.first*31+p.second;
    }
};
unordered_set<pair<int,int>,pair_hash> points_rejected;
bool findpath(pair<int,int> pos)
{
    if(pos.first>grid.size()-1)
        return false;
    else if(pos.second>grid[0].size()-1)
        return false;
    else if(pos.second==grid[0].size()-1&&pos.first==grid.size()-1)
        return true;
    else if(!grid[pos.first][pos.second])
    {
        points_rejected.insert(pos);
        return false;
    }
    else if(points_rejected.find(pos)!=points_rejected.end())
        return false;
    else
    {
        if(findpath(make_pair(pos.first+1,pos.second))||findpath(make_pair(pos.first,pos.second+1)))
        {
            cout<<pos.first<<" "<<pos.second<<endl;
            return true;
        }
    }
    points_rejected.insert(pos);
    return false;
}
int main()
{
    grid[4][5]=0;
    points_rejected.reserve(7*5);
    findpath(pair<int,int>(0,0));
}
