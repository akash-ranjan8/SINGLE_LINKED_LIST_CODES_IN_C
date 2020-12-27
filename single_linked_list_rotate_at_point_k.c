//Rotate linkedlist
#include<stdio.h>
#include<stdlib.h>
struct node 
{ int data;
  struct node *next;
};
struct node *head1=NULL;
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
void rotate(struct node *head,int k)
{ struct node *t=head;
  int i;
  for(i=0;i<k;++i)
  { t=t->next;
  }
  create(&head1,(t->next)->data);
  create(&head1,(t->next->next)->data);
  struct node *t1=head;
  for(i=0;i<=k;++i)
  { create(&head1,t1->data);
    t1=t1->next;
  }
}
int main()
{ int n,e,i,k;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  struct node *head=NULL;
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&e);
    create(&head,e);
  }
  display(head);
  printf("enter the value of k\n");
  scanf("%d",&k);
  rotate(head,k);
  printf("new list\n");
  display(head1);
  return 0;
}
