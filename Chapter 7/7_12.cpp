#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
template<class K, class V> class HashTable
{
    vector<vector<pair<K,V>>> items;
    int size;
    public:
    HashTable(int size):size(size){items.resize(size);}
    int gethash(string str)
    {
        return str.length()%size;
    }
    int gethash(int integer)
    {
        return integer%size;
    }
    bool put(K key,V value)
    {
        int index=gethash(key);
        if(items[index].empty())
        {
            items[index].push_back(make_pair(key,value));
            return true;
        }
        auto it=items[index].begin();
        for(;it!=items[index].end();it++)
            if((*it).first==key)
                break;
        if(it==items[index].end())
        {
            items[index].push_back(make_pair(key,value));
            return true;
        }
        else
            (*it).second=value;
        return false;
    }
    V get(K key)
    {
        int index=gethash(key);
        auto it=items[index].begin();
        for(;it!=items[index].end();it++)
            if((*it).first==key)
                break;
        if(it==items[index].end())
            return NULL;
        else
            return (*it).second;
    }
};
int main()
{
    HashTable<int,int> table(5);
    table.put(3,10);
    cout<<table.get(9);
}

