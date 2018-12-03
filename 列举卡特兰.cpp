#include<cstdio>
using namespace std;
int n(0),sum(0),inbook[40],outbook[40];  //n为车数，sum为出栈数，入栈标记数组，出栈标记数组
void fun(int *a,int j,int p,int q)
{
    if(p==n&&q==n)                       //入栈数和出栈数都为车数
    {
        sum++;
        return;
    }
  //  printf("%d %d %d\n",j,p,q);
    a[j] = 1;                             //列举入栈
    inbook[p] = p+1;                      //入栈数加1
    if(p>n||q>n||p<q)                    //入栈数超过车数，或出栈数超过车数，或出栈数超过入栈数退出递归
        return;
    fun(a,j+1,p+1,q);                     //下一步

    a[j] = 0;                             //列举出栈
    outbook[q] = q+1;                      //出栈数加1
    if(p>n||q>n||p<q)                    //入栈数超过车数，或出栈数超过车数，或出栈数超过入栈数退出递归
        return;
    fun(a,j+1,p,q+1);                     //递归
    return;                               //结束
}
int main()
{
       while(~scanf("%d",&n))
       {
           sum=0;
           int a[2*n];                      //入栈出栈总数操作
           fun(a,0,0,0);                    //函数递归
           printf("%d\n",sum);              //输出
       }

    return 0;
}
