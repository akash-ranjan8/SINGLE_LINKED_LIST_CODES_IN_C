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
void delete_alternate(struct node *head)
{ struct node *t1=head;
  struct node *t2=head->next;
  while(t1!=NULL && t2!=NULL)
  { t1->next=t2->next;
    free(t2);
    t1=t1->next;
    if(t1!=NULL)
    { t2=t1->next;
    }
  }
}
int main()
{ int n,e;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  int i;
  struct node *head=NULL;
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&e);
    create(&head,e);
  }
  display(head);
  printf("\nnewlist\n");
  delete_alternate(head);
  display(head);
  return 0;
}
