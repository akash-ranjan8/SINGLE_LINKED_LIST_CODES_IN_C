#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *next;
};
struct node *head1=NULL;
struct node *head2=NULL;
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
void union1(struct node *head3,struct node *head4)
{ struct node *t1=head3;
  struct node *t2=head4;
  while(t1!=NULL & t2!=NULL)
  { if(t1->data!=t2->data)
    { create(&head1,t1->data);
      create(&head1,t2->data);
    }
    else if(t1->data==t2->data)
    { create(&head1,t1->data);
    }
    t1=t1->next;
    t2=t2->next;
  }
  display(head1);
}
void intersection(struct node *head3, struct node *head4)
{ struct node *t1=head3;
  struct node *t2=head4;
  while(t1!=NULL && t2!=NULL)
  { if(t1->data==t2->data)
    { create(&head2,t1->data);
    }
    t1=t1->next;
    t2=t2->next;
  }
  display(head2);
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
  printf("\nUNION\n");
  union1(head1,head2);
  printf("\nINTERSECTION\n");
  intersection(head1,head2);
  return 0;
}
