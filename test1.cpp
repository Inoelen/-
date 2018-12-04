#include<cstdio>
#include<cstring>
using namespace std;
char tu[1000][1000];
int book[1000][1000],path[3][1000000],head(0),tail(0);
int n(0),m(0),px(0),py(0),flag(0),tn(0),tm(0);
int next[4][2]={{0,1},                    //向右走
                {1,0},                     //向下走
                {0,-1},                    //向左走
                {-1,0}};                   //向上走
inline int absolute(int x,int y)           //计算绝对值
{
    if(x-y>=0)
        return x-y;
    else
        return y-x;
}
void bfs(int x,int y,int step)
{
    for(int i=0;i<tail;i++)
    if(head>tail)
        return;
    int tx,ty,ax,ay;
    for(int k=0;k<4;k++)
    {
        tx = x+next[k][0];
        ty = y+next[k][1];
        ax = absolute(tx,px);
        ay = absolute(ty,py);
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&(ax+ay)>=step+1)
        {
            if(tu[tx][ty]=='E')
            {
                flag=1;
                return ;
            }
            if(tu[tx][ty]=='.'&&book[tx][ty]==0)
            {
                book[tx][ty]=1;
                path[0][tail] = tx;
                path[1][tail] = ty;
                path[2][tail] = step+1;
                tail++;
            }
        }
    }
    head++;
    bfs(path[0][head],path[1][head],path[2][head]);
    return;
}
void redirect()
{
    #ifdef LOCAL
      freopen("test1.txt","r",stdin);
    #endif // LOCAL
}
int main()
{
    redirect();
    while(~scanf("%d %d",&n,&m))
    {
        flag = 0;
        for(int i=0;i<tn;i++)
        {
            memset(book[i],0,sizeof(book[i]));
        }
        for(int i=0;i<3;i++)
            memset(path[i],0,sizeof(path[i]));
        head = 0;
        tail = 0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",&tu[i]);
            for(int j=0;j<m;j++)
            {
                if(tu[i][j]=='S')
                {
                   path[0][tail] = i;
                   path[1][tail] = j;
                   tail++;
                }
                if(tu[i][j]=='F')
                {
                    px = i;
                    py = j;
                }

            }
        }
        bfs(path[0][head],path[1][head],path[2][head]);

        if(flag==1)
            printf("PIG PIG PIG!\n");
         else
            printf("A! WO SI LA!\n");

    tn = n;
    tm = m;
    }

    return 0;
}
