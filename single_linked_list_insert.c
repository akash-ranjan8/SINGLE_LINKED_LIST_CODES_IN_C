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
void insert(int k,int m)
{ if(m<=0)
  { printf("wrong data\n");
  }
  int l=0;
  struct node *t=head;
  while(t!=NULL)
  { ++l;
    t=t->next;
  }
  if(m>l+1)
  { printf("wrong data\n");
  }
  else
  { struct node *prev=head;
    int c=1;
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=k;
    new->next=NULL;
    while(c<m-1)
    { prev=prev->next;
      ++c;
    }
    new->next=prev->next;
    prev->next=new;
  }
}
int main()
{ int n,i,k,e,z;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&k);
    create(k);
  }
  display();
  printf("enter the element and its position\n");
  scanf("%d%d",&e,&z);
  insert(e,z);
  printf("\n");
  display();
  return 0;
}
    
  
