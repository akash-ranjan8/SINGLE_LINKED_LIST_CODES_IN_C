#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *next;
};
void create(struct node **head,int d)
{ struct node *curr;
  curr=(struct node*)malloc(sizeof(struct node));
  curr->data=d;
  curr->next=NULL;
  if(*head==NULL)
  { *head=curr;
  }
  else
  { struct node *t=*head;
    while(t->next!=NULL)
    { t=t->next;
    }
    t->next=curr;
    
    
  }
}
void display(struct node *head)
{ struct node *ptr=head;
  while(ptr!=NULL)
  { printf("%d\t",ptr->data);
    ptr=ptr->next;
  }
}
int main()
{ int n,i,k;
  struct node *head=NULL;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the value\n");
    scanf("%d",&k);
    create(&head,k);
  }
  display(head);
  return 0;
}
  
