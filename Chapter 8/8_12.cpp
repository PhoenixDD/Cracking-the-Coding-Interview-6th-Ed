#include<iostream>
#include<cmath>
using namespace std;
int rows[8]={0};
void queens(int col)
{
    if(col==8)
    {
        for(int i=0;i<8;i++)
            cout<<"("<<i+1<<","<<rows[i]+1<<")"<<" ";
        cout<<endl;
        return;
    }
    for(int row=0;row<8;row++)
    {
        int i;
        if(col>0)
        {
            for(i=0;i<col;i++)
            {
                if(rows[i]==row||abs(rows[i]-row)==abs(col-i))
                    break;
            }
        }
        if(i==col||col==0)
        {
            rows[col]=row;
            queens(col+1);
        }
    }
}
int main()
{
    queens(0);
}
