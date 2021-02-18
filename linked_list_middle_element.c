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
int middle(struct node *head)
{ struct node *ptr=head;
  int l=0;
  while(ptr!=NULL)
  { ++l;
    ptr=ptr->next;
  }
  struct node *t=head;
  int mid=l/2;
  for(int i=0;i<mid;++i)
  { t=t->next;
  }
  return t->data;
}
int main()
{ int n,e;
  struct node *head=NULL;
  printf("enter the size of list\n");
  scanf("%d",&n);
  printf("enter the elements\n");
  for(int i=0;i<n;++i)
  { scanf("%d",&e);
    create(&head,e);
  }
  display(head);
  int z=middle(head);
  printf("\nMiddle element is: %d\n",z);
  return 0;
}
  
  
