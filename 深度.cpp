#include<cstdio>
#include<cstring>
using namespace std;
int  n(0),m(0),flag(0),px(0),py(0),tn(0),tm(0);
char tu[1000][1000],book[1000][1000];     //�洢ͼ�ͱ��ͼ
int next[4][2]={{0,1},                    //������
                {1,0},                     //������
                {0,-1},                    //������
                {-1,0}};                   //������
inline int absolute(int x,int y)           //�������ֵ
{
    if(x-y>=0)
        return x-y;
    else
        return y-x;
}
void dfs(int x,int y,int step)            //�����������
{
    int tx(0),ty(0);
     for(int i=0;i<4;i++)                  //�ĸ�������һ��
     {
         tx = x+next[i][0];
         ty = y+next[i][1];
        if(tx<0||tx>n-1||ty<0||ty>m-1)     //����ͼ�������õ������
            continue;

        int ax,ay;
        ax = absolute(tx,px);              //����õ����ɽ�ľ���
        ay = absolute(ty,py);
        if((ax+ay)<step+1||tu[tx][ty]=='#')     //���С�ڻ�ɽ��չ�ķ�Χ����ײǽ
            continue;                        //�����õ������
        if((ax+ay)==step+1)                 //�պ�����һ�λ�ɽ�緢�ĵ�
        {
            if(tu[tx][ty]!='E')             //���ǳ����������õ�
                continue;
        }
          if(tu[tx][ty]=='E')               //�ߵ��˳���
         {
             flag = 1;                      //���߳��������˳�����
             return;
         }
         if(tu[tx][ty]=='.'&&book[tx][ty]==0) //����ߵĵ���ƽ����û���߹�
         {
             book[tx][ty] = 1;            //��Ǹõ�
             dfs(tx,ty,step+1);               //�����ߣ�
             book[tx][ty] = 0;                  //ȡ����ǳ�����������
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
    while(~scanf("%d %d",&n,&m))             //����ͼ�ĳ���
    {
        flag = 0;                             //����flag
        for(int i=0;i<tn;i++)
        {
            memset(book[i],0,tm);                  //����ͼ�ͱ������
        }
    int startx(0),starty(0);
    for(int i=0;i<n;i++)
    {
            scanf("%s",&tu[i]);
            for(int j=0;j<m;j++)
            {
                 if(tu[i][j]=='S')           //��¼��ʼ��
            {
                 startx = i;
                 starty = j;
                 book[i][j] = 1;
            }
            if(tu[i][j]=='F')                 //��¼��ɽ��
            {
                px = i;
                py = j;
                book[i][j] = 1;
            }
            }

    }
    dfs(startx,starty,0);                      //��ʼ����

    if(flag==1)                                //�ж��Ƿ��߳��Թ�
        printf("PIG PIG PIG!\n");
    else
        printf("A! WO SI LA!\n");

        tn = n;                                 //��¼����n��m�´�ѭ��ǰ��գ�
        tm = m;
    }

        return 0;
}
