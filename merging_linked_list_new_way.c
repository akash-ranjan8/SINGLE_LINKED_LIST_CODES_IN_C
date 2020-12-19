#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *next;
};
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
void merge(struct node *head1,struct node *head2);
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
void divide_list(struct node *head,int n)
{ struct node *t=head;
  for(int i=0;i<(n/2);++i)
  { create(&head1,t->data);
    t=t->next;
  }
  for(int i=(n/2);i<n;++i)
  { create(&head2,t->data);
    t=t->next;
  }
  merge(head1,head2);
}
void merge(struct node *head1,struct node *head2)
{ struct node *t1=head1;
  struct node *t2=head2;
  while(t1!=NULL && t2!=NULL)
  { create(&head3,t1->data);
    create(&head3,t2->data);
    t1=t1->next;
    t2=t2->next;
  }
  display(head3);
}
int main()
{ int n,e,k;
  struct node *head=NULL;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  for(int i=0;i<n;++i)
  { printf("enter the element\n");
    scanf("%d",&e);
    create(&head,e);
  }
  display(head);
  printf("final list\n");
  divide_list(head,n);
  return 0;
}
