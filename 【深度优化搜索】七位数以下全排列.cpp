#include<cstdio>
#include<cstdlib>
using namespace std;
int n(0),check[10000],mark[10],line(0);         //λ�����洢���飬������飬����±�
int length(int m)                              //����λ���ĺ���
{
   int t,n(0);                                  //�м���t��λ��x
   t = m;
    while(t!=0)
    {
       t=t/10;                                  //������ʱ��ʾλ��������
       n++;
    }
    return n;                                   //����λ��
}
void countPrint(int *a,int *b,int t,int n)
{
    if(t == n)                                  //���ÿһλ���г���ȫ�����
    {
      int s(0),temp(1);                           //���������м���
      for(int j=n-1;j>=0;j--)                               //�������г���������ֵ
      {
         s += a[b[j]]*temp;
         temp *= 10;
      }
        int k=0;
      for( ;k<line;k++)                               //�ж��Ƿ��Ѿ���������ֵ
      if(check[k]==s)
        break;
      if(k==line)                                         //kΪline��ֵ���ʾ�洢������û�����ֵ
     {
         check[line] = s;                               //�����ֵ
         line++;                                       //����±�ָ����һ��λ��
     }
    return;                                            //��һ�����н���
    }
   for(int i=0;i<n;i++)                               //��������
   {
       if(mark[i]==0)                               //�����������û��ʹ��
       {
        b[t] = i;
        mark[i] = 1;
        countPrint(a,b,t+1,n);
        mark[i] = 0;                               //���³�����һ��ֵʱ����ֵҪΪ��
       }
   }

}
int main()
{
    int m,t(1);                                         //mΪ���������t���м���������λ����n��ʾλ��
    scanf("%d",&m);
    n = length(m);
    printf("%d\n",n);                                         //��ȡ�����λ��

    int a[n],b[n],c[n];                                       //a[]���λ����b[]����ʾa[]���ܵ��������
    for(int i=0;i<n;i++)
    {
      a[i] = m/t%10;
      t *= 10;
    }
    t = 0;
    countPrint(a,b,t,n);
    for(int k=0;k<line;k++)                               //��ӡ������
        printf("%d\n",check[k]);


        system("pause");
    return 0;
}
