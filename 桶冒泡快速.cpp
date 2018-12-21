#include<cstdio>
#include<cstring>
using namespace std;
void print(int *a,int n);
void reorder(int left,int right,int *a);
int main()
{
    int n;
    int temp;                              //ð�ݵ��м���
    scanf("%d",&n);
    int *a = new int[n];
   // int b[10];
   // int book[1001]={0};

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
     //   book[a[i]] += 1;
    }

  /*  for(int i=0;i<=1000;i++)                //����Ͱ����
        if(book[i]!=0)
        printf("%d ",i);
*/

 /*   for(int i=1;i<n;i++)                       //ð������
        for(int j=0;j<n-i;j++)
    if(a[j]>a[j+1])
    {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
    }    */                                      //ð�ݽ���

    reorder(0,n-1,a);
    print(a,n);

    return 0;

}
void print(int *a,int n)
{
    for(int i=0;i<n;i++)
        if(a[i]!=a[i-1])
        printf("%d  ",a[i]);
}
void reorder(int left,int right,int *a)         //����������
{
    if(left>=right)
        return;
    int i,j,temp,t;
    i = left;
    j = right;
    temp = a[left];

    while(i!=j){
        while(a[j]>=temp&&i<j)
            j--;
        while(a[i]<=temp&&i<j)
            i++;

        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    a[left] = a[j];
    a[j] = temp;

    reorder(left,j-1,a);
    reorder(j+1,right,a);

    return;
}
