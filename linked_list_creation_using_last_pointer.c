#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *next;
};
struct node *head=NULL;
struct node *last=NULL;
int main()
{ int n,i;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  struct node *ptr,*curr;
  for(i=1;i<=n;++i)
  { curr=(struct node *)malloc(sizeof(struct node));
    curr->data=i;
    curr->next=NULL;
    if(head==NULL)
    { head=curr;
      last=curr;
    }
    else
    { last->next=curr;
      last=curr;
    }
   }
   ptr=head;
   while(ptr!=NULL)
   { printf("%d\t",ptr->data);
     ptr=ptr->next;
   }
   return 0;
}
  
