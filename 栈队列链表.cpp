#include <cstdio>
#include<cstring>
using namespace std;
struct dui_lie                                 //队列
{
    int a[1000],head,tail;
};
struct zhan                                //栈
{
    int a[1000],top;
};
struct node                                //链表节点
{
    int a;
    struct node *next;
};
int main()
{
   /* dui_lie yi_hao;                     栈和队列的使用
     yi_hao.tail = 0;
     yi_hao.head = 0;
    zhan er_hao;
    er_hao.top = 0;
    for(int i=0;i<5;i++)
    {
         scanf("%d",&yi_hao.a[yi_hao.tail]);
         yi_hao.tail++;
         scanf("%d",&er_hao.a[er_hao.top]);
         er_hao.top++;
    }
   while(er_hao.top--)
   {
       printf("%d,%d\n",yi_hao.a[er_hao.top],er_hao.a[er_hao.top]);
   }*/

   int a;
   node *head,*p,*t;                      //建立头节点，分节点以及中间节点
   head = NULL;
   for(int i=0;i<5;i++)
   {
       scanf("%d",&a);
       p = new node ;
       p->a = a;
       p->next = NULL;
       if(head==NULL)
        head = p;
       else
        t->next = p;

        t = p;
   }

    t = head;
   while(t!=NULL)
   {
       printf("%d\n",t->a);
       t = t->next;
   }
    return 0;
}
