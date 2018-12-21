#include<cstdio>
#include<iostream>
using namespace std;
void countbest(int **fa,int *w,int *v,int n,int m)
{
    for(int i=0;i<=m;i++)
    if(i<w[n-1])
        fa[n-1][i]=0;
    else
        fa[n-1][i]=v[n-1];
    for(int i=n-2;i>=0;i--)
        for(int j=0;j<=m;j++)
       {
            if(j<w[i])
            fa[i][j]=fa[i+1][j];
        else
        fa[i][j]=fa[i+1][j-w[i]]+v[i]>fa[i+1][j]?fa[i+1][j-w[i]]+v[i]:fa[i+1][j];
       }
}
void select(int **fa,int *x,int *w,int n,int m)
{
    int j = m;
    for (int i = 0; i < n -1; i ++)
        {
        if (fa[i][j] == fa[i + 1][j])
            x[i] = 0;
        else
        {
            x[i] = 1;
            j -= w[i];
        }
        x[n -1] = fa[n -1][j] ? 1 :0;
        }
}
void print(int **fa,int n,int m)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<=m;j++)
        cout << fa[i][j] << "   " ;
        cout << "\n";
}
int main()
{
      int n,m,sum(0);
    scanf("%d %d",&n,&m);
    int w[n],v[n],x[n]={0};
    int **fa=new int *[n];
    for(int i=0;i<n;i++)
        fa[i]= new int [m+1];
    for(int i=0;i<n;i++)
        scanf("%d %d",&w[i],&v[i]);

    countbest(fa,w,v,n,m);
    select(fa,x,w,n,m);

    for(int i=0;i<n;i++)
        if(x[i]==1)
          sum+=v[i];

      printf("%d",sum);
      return 0;
}

