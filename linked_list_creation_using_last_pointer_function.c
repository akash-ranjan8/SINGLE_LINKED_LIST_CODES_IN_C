#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *next;
};
struct node *head=NULL;
struct node *last=NULL;
void create(int d)
{ struct node *curr;
  curr=(struct node*)malloc(sizeof(struct node));
  curr->data=d;
  curr->next=NULL;
  if(head==NULL)
  { head=curr;
    last=curr;
  }
  else
  { last->next=curr;
    last=curr;
  }
}
void display()
{ struct node *ptr=head;
  while(ptr!=NULL)
  { printf("%d\t",ptr->data);
    ptr=ptr->next;
  }
}
int main()
{ int n,i,k;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the element\n");
    scanf("%d",&k);
    create(k);
  }
  display();
  return 0;
} 
