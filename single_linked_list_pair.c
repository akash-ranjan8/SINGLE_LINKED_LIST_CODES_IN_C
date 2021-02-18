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
int pair(struct node *head1,struct node *head2,int x)
{ struct node *t1=head1;
  struct node *t2=head2;
  int c=0;
  while(t1!=NULL)
  { while(t2!=NULL)
    { if(t1->data+t2->data==x)
      { ++c;
      }
      t2=t2->next;
    }
    t1=t1->next;
  }
  return c;
}
int main()
{ int n1,n2,e1,e2;
  printf("enter the size of both the list\n");
  scanf("%d%d",&n1,&n2);
  struct node *head1=NULL;
  struct node *head2=NULL;
  printf("enter the data for list 1\n");
  for(int i=0;i<n1;++i)
  { scanf("%d",&e1);
    create(&head1,e1);
  }
  display(head1);
  printf("enter the data for list 2\n");
  for(int i=0;i<n2;++i)
  { scanf("%d",&e2);
    create(&head2,e2);
  }
  display(head2);
  int x;
  printf("enter the sum\n");
  scanf("%d",&x);
  int k=(head1,head2,x);
  printf("The no. of pairs: %d\n",k);
  return 0;
}
  
  
  
    
