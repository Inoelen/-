#include<cstdio>
using namespace std;
int n(0);
int sum(0),b[20];
int fun(int n)
{
   if(n==0||n==1)
    return 1;

    if(b[n]!=0)
    return b[n];

   int a(0);
   for(int i=0;i<n;i++)
   {
       a += fun(i)*fun(n-1-i);
   }
    b[n] = a;
    return a;
}
int main()
{
       while(~scanf("%d",&n))
      {
        sum = fun(n);
       printf("%d\n",sum);
      }
    return 0;
}
