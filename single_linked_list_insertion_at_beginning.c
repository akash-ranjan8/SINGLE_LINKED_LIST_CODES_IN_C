#include<stdio.h>
#include<stdlib.h>
struct node 
{ int data;
  struct node *next;
};
struct node *head=NULL;
void create(int d)
{ struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=d;
  new->next=NULL;
  if(head==NULL)
  { head=new;
  }
  else
  { struct node *t=head;
    while(t->next!=NULL)
    { t=t->next;
    }
    t->next=new;
  }
}
void display()
{ struct node *ptr=head;
  while(ptr!=NULL)
  { printf("%d\t",ptr->data);
    ptr=ptr->next;
  }
}
void insert_at_beginning(int k)
{ struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=k;
  newnode->next=NULL;
  if(head!=NULL)
  { newnode->next=head;
    head=newnode;
  }
}
int main()
{ int n,i,k;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&k);
    create(k);
  }
  display();
  int m;
  printf("enter the data to be inserted at the beginning of the list\n");
  scanf("%d",&m);
  insert_at_beginning(m);
  display();
  return 0;
}



