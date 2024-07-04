#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"
void acceptMatrixValues(int** m, int len)
{
    for (int i = 0; i < len; i++)               
    {
        for (int j = 0; j < len; j++)
        {
            scanf("%d", &m[i][j]);
        }
        
    }
 
}

int isTherePath(int** m, int i, int j){
    if(m[i][j]!=0)
    {
        return m[i][j];
    }
    int w=weightOfShortestPath(m,i,j,MATRIX_SIZE);    
    return (w==0? -1: w);
     
}

int weightOfShortestPath(int m[][MATRIX_SIZE], int ver1, int ver2, const int len)                    
{
      int dist[len][len];                 
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            dist[i][j]=0;
        }
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (m[i][j]>0)
            {
                dist[i][j]=m[i][j];
            }
        
        }
    }

    for(int k=1;k<len;k++)
    {
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                if(i!=j)
                {
                    if(dist[i][j]==0||dist[i][j]>(dist[i][k]+dist[k][j]))
                        {
                            dist[i][j]=dist[i][k]+dist[k][j]; 
                        }
                }
            }
        }
    }
    return dist[ver1][ver2]==0? -1: dist[ver1][ver2];
}