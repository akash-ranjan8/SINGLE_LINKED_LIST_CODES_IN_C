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
void swap(int *a,int *b)
{ int t;
  t=*a;
  *a=*b;
  *b=t;
}
void swap_nodes(struct node *head)
{ struct node *t=head;
  while(t!=NULL && t->next!=NULL)
  { swap(&t->data,&(t->next)->data);
    t=t->next->next;
  }
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
  swap_nodes(head);
  printf("\nnew nodes set\n");
  display(head);
  return 0;
}
