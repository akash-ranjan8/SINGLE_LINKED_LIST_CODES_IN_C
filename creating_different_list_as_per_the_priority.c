#include<stdio.h>
#include<stdlib.h>
struct node
{ int p;
  int d;
  struct node *next;
};
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
struct node *head4=NULL;
struct node *head5=NULL;
void create(struct node **head,int p, int d)
{ struct node *new=(struct node*)malloc(sizeof(struct node));
  new->p=p;
  new->d=d;
  new->next=NULL;
  if(*head=NULL)
  { *head=new;
  }
  else
  { struct node *t1=*head;
    while(t1->next!=NULL)
    { t1=t1->next;
    }
    t1->next=new;
  }
}
void display(struct node *head)
{ struct node *ptr=head;
  while(ptr!=NULL)
  { printf("%d,%d\t",ptr->p,ptr->d);
    ptr=ptr->next;
  }
}
void creating_separate_lists(struct node *head,int p)
{ struct node *t=head;
  while(t!=NULL)
  { if(t->p==1)
    { create(&head1,t->p,t->d);
    }
    else if(t->p==2)
    { create(&head2,t->p,t->d);
    }
    else if(t->p==3)
    { create(&head3,t->p,t->d);
    }
    else if(t->p==4)
    { create(&head4,t->p,t->d);
    }
    else if(t->p==5)
    { create(&head5,t->p,t->d);
    }
    t=t->next;
  }
}
int main()
{ int n,p,d,i;
  struct node *head=NULL;
  printf("enter the number of nodes\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the priority (1-5)\n");
    scanf("%d",&p);
    printf("enter the data\n");
    scanf("%d",&d);
    create(&head,p,d);
  }
  display(head);
  int e;
  printf("enter the priority whose data you want to separate\n");
  scanf("%d",&e);
  creating_separate_lists(head,e);
  if(e==1)
  { display(head1);
  }
  else if(e==2)
  { display(head2);
  }
  else if(e==3)
  { display(head3);
  }
  else if(e==4)
  { display(head4);
  }
  else if(e==5)
  { display(head5);
  }
  return 0;
}

