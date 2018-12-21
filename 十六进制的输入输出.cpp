#include<cstdio>
using namespace std;
int main()
{
     long long a,b;
     while(~scanf("%llx %llx",&a,&b))
    {
     if((a+b)>=0)
     {
          printf("%llX\n",a+b);
     }

     else
      printf("-%llX\n",-(a+b));
    }
    return 0;
}
