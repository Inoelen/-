#include<cstdio>
#include<cstring>
using namespace std;
int  n(0),m(0),flag(0),px(0),py(0),tn(0),tm(0);
char tu[1000][1000],book[1000][1000];     //存储图和标记图
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
void dfs(int x,int y,int step)            //深度优先搜索
{
    int tx(0),ty(0);
     for(int i=0;i<4;i++)                  //四个方向走一遍
     {
         tx = x+next[i][0];
         ty = y+next[i][1];
        if(tx<0||tx>n-1||ty<0||ty>m-1)     //超出图则跳过该点继续走
            continue;

        int ax,ay;
        ax = absolute(tx,px);              //计算该点与火山的距离
        ay = absolute(ty,py);
        if((ax+ay)<step+1||tu[tx][ty]=='#')     //如果小于火山扩展的范围或者撞墙
            continue;                        //跳过该点继续走
        if((ax+ay)==step+1)                 //刚好在这一次火山喷发的点
        {
            if(tu[tx][ty]!='E')             //不是出口则跳过该点
                continue;
        }
          if(tu[tx][ty]=='E')               //走到了出口
         {
             flag = 1;                      //有走出方案，退出函数
             return;
         }
         if(tu[tx][ty]=='.'&&book[tx][ty]==0) //如果走的点是平地且没有走过
         {
             book[tx][ty] = 1;            //标记该点
             dfs(tx,ty,step+1);               //继续走；
             book[tx][ty] = 0;                  //取消标记尝试其他方向
         }
     }

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
    while(~scanf("%d %d",&n,&m))             //输入图的长宽
    {
        flag = 0;                             //重置flag
        for(int i=0;i<tn;i++)
        {
            memset(book[i],0,tm);                  //重置图和标记数组
        }
    int startx(0),starty(0);
    for(int i=0;i<n;i++)
    {
            scanf("%s",&tu[i]);
            for(int j=0;j<m;j++)
            {
                 if(tu[i][j]=='S')           //记录起始点
            {
                 startx = i;
                 starty = j;
                 book[i][j] = 1;
            }
            if(tu[i][j]=='F')                 //记录火山点
            {
                px = i;
                py = j;
                book[i][j] = 1;
            }
            }

    }
    dfs(startx,starty,0);                      //开始搜索

    if(flag==1)                                //判断是否走出迷宫
        printf("PIG PIG PIG!\n");
    else
        printf("A! WO SI LA!\n");

        tn = n;                                 //记录本次n，m下次循环前清空；
        tm = m;
    }

        return 0;
}
