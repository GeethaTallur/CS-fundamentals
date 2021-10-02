#include <iostream>
#include<climits>
using namespace std;
int findMinVertex(bool *visited,int *weights,int n)
{
    int min=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (min==-1 || weights[i]<weights[min]))
        {
            min=i;
        }
    }
    return min;
}
void prims(int **edges,int n)
{
    int *parent =new int[n];
    int *weights =new int[n];
    bool*visited =new bool[n];
    
    for(int i=1;i<n;i++)
    {
        visited[i]=false;
        weights[i]=INT_MAX;
    }
    parent[0]=-1;
    weights[0]=0;
    for(int i=0;i<n-1;i++)
    {
    int minVertex=findMinVertex(visited,weights,n);
    visited[minVertex]=true;
    for(int j=0;j<n;j++)
    {
        if(!visited[j] && edges[minVertex][j]!=0)
        {
            if(edges[minVertex][j] + weight[minVertex]<weights[j])
            {
                weights[j]=edges[minVertex][j] + weight[minVertex];
            }
        }
    }
    }
    for(int i=1;i<n;i++)
           cout<<i<<" "<<i<<" "<<weights[i]<<endl;
   
}
int main()
{   int f,s,weight;
    int n,e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++)
    {   
       edges[i]=new int[n];
       for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    
    for(int j=0;j<e;j++)
    {
       cin>>f>>s>>weight;
       edges[f][s]=weight;
       edges[s][f]=weight;
    }
    cout<<endl;
    prims(edges,n);
    
}
