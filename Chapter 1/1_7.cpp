#include<iostream>
using namespace std;
void rotate90(int matrix[][5])
{
    for(int layer=0;layer<(sizeof(matrix[0])/sizeof(int))/2;layer++)
    {
        int last=sizeof(matrix[0])/sizeof(int)-layer-1;
        for(int i=layer;i<sizeof(matrix[0])/sizeof(int)-layer;i++)
        {
            int temp=matrix[layer][i];
            matrix[layer][i]=matrix[sizeof(matrix[0])/sizeof(int)-i-1][layer];
            matrix[sizeof(matrix[0])/sizeof(int)-i-1][layer]=matrix[last][sizeof(matrix[0])/sizeof(int)-i-1];
            matrix[last][sizeof(matrix[0])/sizeof(int)-i-1]=matrix[i][last];
            matrix[i][last]=temp;
        }
    }
    for(int i=0;i<sizeof(matrix[0])/sizeof(int);i++)
    {
        for(int j=0;j<sizeof(matrix[0])/sizeof(int);j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int test[][5]={{9,23,2,56,7},
                    {3,7,21,78,23},
                    {31,6,23,45,11},
                    {10,4,15,83,53},
                    {1,2,3,4,17}};
    rotate90(test);
}
