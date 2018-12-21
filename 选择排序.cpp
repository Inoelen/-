#include <cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
void print(int *a){                             //打印所得的数组的函数
    for(int i=0;i<100;i++)
     {
          printf("%d\t",a[i]);
          if((i+1)%10==0)
            printf("\n");
     }
}
int main(){
    int a[100],temp(0);
    srand(time(0));
     for(int i=0;i<100;i++)                //产生随机数组a[100]：1~100
    {
        a[i]=rand()%100+1;
    }

    for(int i=0;i<100;i++)
        for(int j=i+1;j<100;j++)
    {
        if(a[i]>a[j])                        //选择较小的数分别赋值
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    }

    print(a);                               //打印数组a[100]

    return 0;
}
