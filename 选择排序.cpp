#include <cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
void print(int *a){                             //��ӡ���õ�����ĺ���
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
     for(int i=0;i<100;i++)                //�����������a[100]��1~100
    {
        a[i]=rand()%100+1;
    }

    for(int i=0;i<100;i++)
        for(int j=i+1;j<100;j++)
    {
        if(a[i]>a[j])                        //ѡ���С�����ֱ�ֵ
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    }

    print(a);                               //��ӡ����a[100]

    return 0;
}
