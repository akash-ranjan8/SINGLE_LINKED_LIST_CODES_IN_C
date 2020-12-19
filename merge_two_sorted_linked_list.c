//merging two linkedlist
#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *next;
};
struct node *head=NULL;
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
void merge(struct node *head1, struct node *head2)
{ struct node *t1=head1;
  struct node *t2=head2;
  while(t1!=NULL && t2!=NULL)
  { if(t1->data>t2->data)
    { create(&head,t2->data);
    }
    else
    { create(&head,t1->data);
    }
    t1=t1->next;
    t2=t2->next;
  }
  while(t1!=NULL)
  { create(&head,t1->data);
    t1=t1->next;
  }
  while(t2!=NULL)
  { create(&head,t2->data);
    t2=t2->next;
  }
}
int main()
{ int n1,n2;
  struct node *head1=NULL;
  struct node *head2=NULL;
  printf("enter the the size of both linkedlist\n");
  scanf("%d%d",&n1,&n2);
  int i,e1,e2;
  printf("enter the data for linkedlist1\n");
  for(i=0;i<n1;++i)
  { printf("enter the data\n");
    scanf("%d",&e1);
    create(&head1,e1);
  }
  printf("enter the data for linkedlist2\n");
  for(i=0;i<n2;++i)
  { printf("enter the data\n");
    scanf("%d",&e2);
    create(&head2,e2);
  }
  merge(head1,head2);
  printf("the resultant list\n");
  display(head);
  return 0;
}
