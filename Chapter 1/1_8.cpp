#include<iostream>
using namespace std;
void zero(int matrix[3][5])
{
    for(int i=0;i<sizeof(matrix)/sizeof(matrix[0]);i++)
    {
        for(int j=0;j<sizeof(matrix[0])/sizeof(int);j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    for(int i=0;i<sizeof(matrix)/sizeof(matrix[0]);i++)
    {
        if(matrix[i][0]==0)
             for(int j=0;j<sizeof(matrix[0])/sizeof(int);j++)
             {
                 matrix[i][j]=0;
             }
    }
    for(int j=0;j<sizeof(matrix[0])/sizeof(int);j++)
    {
        if(matrix[0][j]==0)
             for(int i=0;i<sizeof(matrix[0])/sizeof(int);i++)
             {
                 matrix[i][j]=0;
             }
    }
    for(int i=0;i<sizeof(matrix)/sizeof(matrix[0]);i++)
    {
        for(int j=0;j<sizeof(matrix[0])/sizeof(int);j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int test[3][5]={{21,34,0,12,9},
                    {0,34,10,3,9},
                    {1,90,50,3,7}};
    zero(test);
}
