//reverse in series of k in linked list
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
struct node *reverse(struct node *head,int k)
{ struct node *curr,*next,*prev;
  curr=head;
  next=NULL;
  prev=NULL;
  int c=0;
  while(curr!=NULL && c<k)
  { next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    ++c;
  }
  if(next!=NULL)
  { head->next=reverse(next,k);
  }
  return prev;
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
  head=reverse(head,k);
  printf("new list\n");
  display(head);
  return 0;
}
