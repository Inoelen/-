#include<cstdio>
#include<cstring>
using namespace std;
static const int maxn = 100010;
long long add(char *a,char *b)
{
    long long m(0),n(0),x(1),sum1(0),sum2(0);
    m = strlen(a);
    n = strlen(b);
    for(int i=m-1;i>=0;i--)
    {
        if(a[i]<='9'&&a[i]>='0')
        {
            sum1 += (a[i] - '0')*x;
            x *= 16;
        }
        else if(a[i]=='-')
        {
          sum1 = sum1*(-1);
        }
        else if(a[i]=='+')
        {
          sum1 = sum1*(1);
        }
        else if(a[i]<='Z'&&a[i]>='A')
        {
            sum1 += (a[i] - '7')*x;
            x *= 16;
        }
        else
        {
            sum1 += (a[i] - 'W')*x;
            x *= 16;
        }
    }
    x = 1;
     for(int i=n-1;i>=0;i--)
    {
        if(b[i]<='9'&&b[i]>='0')
        {
            sum2 += (b[i] - '0')*x;
            x *= 16;
        }
        else if(b[i]=='-')
        {
          sum2 = sum2*(-1);
        }
          else if(b[i]=='+')
        {
          sum2 = sum2*(1);
        }
        else if(b[i]<='Z'&&b[i]>='A')
        {
            sum2 += (b[i] - '7')*x;
            x *= 16;
        }
        else
        {
            sum1 += (b[i] - 'W')*x;
            x *= 16;
        }
}
  return (sum1+sum2);
}
int main()
{
	char a[maxn],b[maxn],c[maxn];
	long long i;
	while(~scanf("%s %s",a,b))
    {
       i = add(a,b);
     if(i>=0)
       printf("%llX\n",i);
     else
      printf("-%llX\n",-i);
    }

		return 0;
}
