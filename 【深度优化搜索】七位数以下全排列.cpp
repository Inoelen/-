#include<cstdio>
#include<cstdlib>
using namespace std;
int n(0),check[10000],mark[10],line(0);         //位数，存储数组，标记数组，标记下标
int length(int m)                              //返回位数的函数
{
   int t,n(0);                                  //中间量t和位数x
   t = m;
    while(t!=0)
    {
       t=t/10;                                  //等于零时表示位数都除尽
       n++;
    }
    return n;                                   //返回位数
}
void countPrint(int *a,int *b,int t,int n)
{
    if(t == n)                                  //如果每一位排列尝试全部完成
    {
      int s(0),temp(1);                           //排列数、中间量
      for(int j=n-1;j>=0;j--)                               //计算排列出来的数字值
      {
         s += a[b[j]]*temp;
         temp *= 10;
      }
        int k=0;
      for( ;k<line;k++)                               //判断是否已经产生过该值
      if(check[k]==s)
        break;
      if(k==line)                                         //k为line的值则表示存储数组里没有这个值
     {
         check[line] = s;                               //存入该值
         line++;                                       //标记下标指向下一个位置
     }
    return;                                            //这一次排列结束
    }
   for(int i=0;i<n;i++)                               //进行排列
   {
       if(mark[i]==0)                               //如果排列数还没有使用
       {
        b[t] = i;
        mark[i] = 1;
        countPrint(a,b,t+1,n);
        mark[i] = 0;                               //重新尝试下一个值时，该值要为零
       }
   }

}
int main()
{
    int m,t(1);                                         //m为输入的数，t是中间量产生各位数，n表示位数
    scanf("%d",&m);
    n = length(m);
    printf("%d\n",n);                                         //获取并输出位数

    int a[n],b[n],c[n];                                       //a[]存各位数，b[]来表示a[]可能的排序组合
    for(int i=0;i<n;i++)
    {
      a[i] = m/t%10;
      t *= 10;
    }
    t = 0;
    countPrint(a,b,t,n);
    for(int k=0;k<line;k++)                               //打印所得数
        printf("%d\n",check[k]);


        system("pause");
    return 0;
}
