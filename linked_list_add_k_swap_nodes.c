#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *next;
};
struct node *head=NULL;
void create(int d)
{ struct node *new=(struct node*)malloc(sizeof(struct node));
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
void display(int k)
{ struct node *ptr=head;
  while(ptr!=NULL)
  { printf("%d\t",ptr->data+k);
    ptr=ptr->next;
  }
}
void display1()
{ struct node *ptr=head;
  while(ptr!=NULL)
  { printf("%d\t",ptr->data);
    ptr=ptr->next;
  }
}
//swapping k1 and k2 nodes in linked list
void swap(int k1,int k2)
{ struct node *t1,*t2,*n1,*n2,*p;
  n1=NULL;
  n2=NULL;
  t1=head;
  t2=head;
  while(t1->data!=k1)
  { n1=t1;
    t1=t1->next;
  }
  while(t2->data!=k2)
  { n2=t2;
    t2=t2->next;
  }
  if(n1!=NULL)
  { n1->next=t2;
  }
  if(n2!=NULL)
  { n2->next=t1;
  }
  p=t1->next;
  t1->next=t2->next;
  t2->next=p;
}
int main()
{ int n,d,k,k1,k2;
  printf("enter the number of nodes\n");
  scanf("%d",&n);
  for(int i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&d);
    create(d);
  }
  printf("enter the value to be added\n");
  scanf("%d",&k);
  display(k);
  printf("enter the values to be swapped\n");
  scanf("%d%d",&k1,&k2);
  swap(k1,k2);
  display1();
  return 0;
}
