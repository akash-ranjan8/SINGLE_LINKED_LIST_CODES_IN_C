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
void delete_at_end()
{ //t1 for one pointer previous than t
  struct node *t=head;
  struct node *t1=NULL;
  while(t->next!=NULL)
  { t1=t;
    t=t->next;
  }
  t1->next=NULL;
  free(t);
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
  delete_at_end();
  printf("\n");
  display();
  return 0;
}
