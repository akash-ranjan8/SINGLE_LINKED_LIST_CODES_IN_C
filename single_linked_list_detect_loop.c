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
int detect_loop(struct node *head)
{ struct node *t1=head;
  struct node *t2=head;
  while(t1!=NULL && t2!=NULL &&t2->next!=NULL)
  { t1=t1->next;
    t2=t2->next->next;
    if(t1==t2)
    { return 1;
    }
  }
  return 0;
}
int main()
{ struct node *head=NULL;
  int n,e;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  for(int i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&e);
    create(&head,e);
  }
  display(head);
  detect_loop(head);
  return 0;
}
