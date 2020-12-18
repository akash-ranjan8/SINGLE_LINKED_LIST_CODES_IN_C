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
void delete(int n,int m)
{ struct node *t=head;
  while(t->data!=m)
  { t=t->next;
  }
  struct node *t1=t->next;
  for(int i=0;i<n;++i)
  { struct node *temp=t1;
    t1=t1->next;
    free(temp);
  }
  t->next=t1;
  t=t1;
}
int main()
{ int n,m,n1,e;
  printf("enter the number of nodes\n");
  scanf("%d",&n1);
  for(int i=0;i<n1;++i)
  { printf("enter the element\n");
    scanf("%d",&e);
    create(e);
  }
  display();
  printf("enter the element and size upto to which wanted to delete\n");
  scanf("%d%d",&m,&n);
  delete(n,m);
  display();
  return 0;
}
  
  
  
  
