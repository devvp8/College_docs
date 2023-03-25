#include<stdio.h>
#define MAX 9
#define INFINITY 9999

int g[MAX][MAX] = { { 0, 11, 0, 0, 0, 0, 0, 8, 0 },
                { 11, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

int min1(int d[],int v[],int n)
{
    int f=0,b[MAX];
    int m ,l=0;
    for(int i=0;i<MAX;i++)
    {
        if(v[i]==0)
        {m=d[i];
            break;
        }
    }
    for(int i=1;i<n;i++)
    {
        // printf("ag wei %d at %d with vis %d\n",d[i],i,v[i]);
        
        if(d[i]<=m && v[i]==0)
        {
            // printf("\nin if : ");
            // printf("ag wei %d at %d with vis %d\n",d[i],i,v[i]);
            m=d[i];
            {l=i;}
        }
        
    }
    // printf("pos %d min %d\n",l,m);

    
    for(int i=0;i<n;i++)
    {
        if(v[i]==1)
        {
            f=f+1;
        }
    }

    if(f==n)
    {
        return -1;
    }

    return l;
}

void mindist(int d[], int par[], int u, int v)
{
    if (g[u][v] != 0 && d[v] > d[u] + g[u][v])
    {
        d[v] = d[u] + g[u][v];
        par[v] = u;
    }
    return u;
}


int main()
{
int d[MAX],par[MAX],v[MAX]={0};
int x=0;
d[0]=0;
par[0]=-1;
for(int i=1;i<MAX;i++)
{d[i]=INFINITY;}
// printf("%d\n",min1(d,v,MAX));
// printf("\t%d\n",v[5]);

do
{
    // printf("\niter %d\n",x);
    if(v[x]==0)
    {
    for(int j=0;j<MAX;j++)
    {
        // printf("\tvis %d\t",v[x]);
        // printf("\n\t\t%d\n",g[x][j]);
        if(g[x][j]!=0)
        {
                // printf("hi");
                mindist(d,par,x,j);
                // for(int i=0;i<MAX;i++){printf("wei %d vis %d\t",d[i],v[i]);}
                // printf("\n");
        }
    }
    }
    v[x]=1;
    // printf("vischec %d",v[x]);
    
}while((x = min1(d,v,MAX))!=-1);


for(int i=0;i<MAX;i++)
{
   printf("%d %d %d\n",i,d[i],par[i]);
}
    
return 0;

}
