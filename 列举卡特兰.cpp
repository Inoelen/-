#include<cstdio>
using namespace std;
int n(0),sum(0),inbook[40],outbook[40];  //nΪ������sumΪ��ջ������ջ������飬��ջ�������
void fun(int *a,int j,int p,int q)
{
    if(p==n&&q==n)                       //��ջ���ͳ�ջ����Ϊ����
    {
        sum++;
        return;
    }
  //  printf("%d %d %d\n",j,p,q);
    a[j] = 1;                             //�о���ջ
    inbook[p] = p+1;                      //��ջ����1
    if(p>n||q>n||p<q)                    //��ջ���������������ջ���������������ջ��������ջ���˳��ݹ�
        return;
    fun(a,j+1,p+1,q);                     //��һ��

    a[j] = 0;                             //�оٳ�ջ
    outbook[q] = q+1;                      //��ջ����1
    if(p>n||q>n||p<q)                    //��ջ���������������ջ���������������ջ��������ջ���˳��ݹ�
        return;
    fun(a,j+1,p,q+1);                     //�ݹ�
    return;                               //����
}
int main()
{
       while(~scanf("%d",&n))
       {
           sum=0;
           int a[2*n];                      //��ջ��ջ��������
           fun(a,0,0,0);                    //�����ݹ�
           printf("%d\n",sum);              //���
       }

    return 0;
}
