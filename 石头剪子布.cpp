//关于石头剪子布的玩法代码，string类比较难受
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

int main()
{
    int m(0),n;
    char str[10],a('y');
    srand(int(time(NULL)));
    while(scanf("%s",&str))
    {
      n=1;
      m=rand()%3+1;
        if(!strcmp(str,"stone"))
          n=1;
        else if(!strcmp(str,"paper"))
          n=2;
        else if(!strcmp(str,"scissors"))
          n=3;
        else
          {
              printf("please input again\n");
              continue;
          }
      switch(n)
        {
       case 1:
           {  if(m==1)
               printf("the computer's output is \"stone\"\nand no winner\n");
              else if(m==2)
               printf("the computer's output is \"paper\"\nand you lose\n");
              else
               printf("the computer's output is \"scissors\"\nand you win\n");
               break;
           }
       case 2:
           {  if(m==1)
               printf("the computer's output is \"stone\"\nand you win\n");
              else if(m==2)
               printf("the computer's output is \"paper\"\nand no winner\n");
              else
               printf("the computer's output is \"scissors\"\nand you lose\n");
               break;}
       case 3:
           {  if(m==1)
               printf("the computer's output is \"stone\"\nand you lose\n");
              else if(m==2)
               printf("the computer's output is \"paper\"\nand you win\n");
              else
               printf("the computer's output is \"scissors\"\nand no winner\n");
               break;}
        }

   }
    return 0;
}
