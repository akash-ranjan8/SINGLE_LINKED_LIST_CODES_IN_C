#include<stdio.h>
#include<stdlib.h>
struct node 
{ int data;
  struct node *next;
};
void create(struct node **head,int d)
{ struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=d;
  new->next=NULL;
  if(*head==NULL)
  { *head=new;
  }
  else
  { struct node *t=*head;
    while(t->next!=NULL)
    { t=t->next;
    }
    t->next=new;
  }
}
void display(struct node *head)
{ struct node *ptr=head;
  while(ptr!=NULL)
  { printf("%d\t",ptr->data);
    ptr=ptr->next;
  }
}
void triplet_sum(struct node *head1,struct node *head2,struct node *head3,int s)
{ struct node *t1,*t2,*t3;
  t1=head1;
  t2=head2;
  t3=head3;
  while(t1!=NULL && t2!=NULL && t3!=NULL)
  { if((t1->data+t2->data+t3->data)==s)
    { printf("%d, %d, %d",t1->data,t2->data,t3->data);
    }
    t1=t1->next;
    t2=t2->next;
    t3=t3->next;
  }
}
int main()
{ int n,e;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  int i;
  struct node *head1,*head2,*head3;
  head1=NULL;
  head2=NULL;
  head3=NULL;
  printf("enter the list1\n");
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&e);
    create(&head1,e);
  }
  printf("enter the list2\n");
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&e);
    create(&head2,e);
  }
  printf("enter the list3\n");
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&e);
    create(&head3,e);
  }
  printf("list1\n");
  display(head1);
  printf("list2\n");
  display(head2);
  printf("list3\n");
  display(head3);
  int s;
  printf("enter the target\n");
  scanf("%d",&s);
  triplet_sum(head1,head2,head3,s);
  return 0;
}
