#include<iostream>
#include<ctime>
#include<vector>
using namespace std;
int getpondsize(vector<vector<int>>&matrix,int i,int j)
{
    if(i>=matrix.size()||j>=matrix[0].size()||i<0||j<0||matrix[i][j]==-1||matrix[i][j]!=0)
        return 0;
    else
    {
        matrix[i][j]=-1;
        int total=1+getpondsize(matrix,i+1,j)+getpondsize(matrix,i,j+1)+getpondsize(matrix,i-1,j)+getpondsize(matrix,i,j-1)+getpondsize(matrix,i+1,j+1)+getpondsize(matrix,i-1,j-1);
        return total;
    }
}
int main()
{
    srand(time(NULL));
    vector<vector<int>> matrix;
    matrix.resize(4);
    for(int i=0;i<4;i++)
        matrix[i].resize(4);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            matrix[i][j]=rand()%2;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            int total=getpondsize(matrix,i,j);
            if(total)
                cout<<total<<" ";

        }
    }
}
