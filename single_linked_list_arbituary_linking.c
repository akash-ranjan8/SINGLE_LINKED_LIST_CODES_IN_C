#include<stdio.h>
#include<stdlib.h>
struct node 
{ int data;
  struct node *next;
  struct node *a;
};
struct node *head=NULL;
void create(int d)
{ struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->next=NULL;
  new->a=NULL;
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
void linking(int n)
{ struct node *t=head;
  int v[n];
  for(int k=0;k<n;++k)
  { v[k]=0;
  }
  int i=0;
  while(t!=NULL && i<n)
  { 
    if(t->data<(t->next)->data && v[i]==0)
    { t->a=t->next;
      v[i]=1;
      ++i;
      t=t->next;
    }
    else
    { continue;
    }
  }
  struct node *t1=head; 
  while(t1->next!=NULL)
  { t1=t1->next;
  }
  if(t1->data<head->data)
  { t1->a=head;
  }
}
int main()
{ int n,e;
  printf("enter the number of nodes\n");
  scanf("%d",&n);
  printf("ente  the list data\n");
  for(int i=0;i<n;++i)
  { printf("enter the data %d\n",i+1);
    scanf("%d",&e);
    create(e);
  }
  display();
  linking(n);
  printf("list is as follows\n");
  display();
  return 0;
}
    
    
