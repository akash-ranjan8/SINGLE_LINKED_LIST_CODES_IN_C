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
void delete(int k)
{ struct node *prev,*curr;
  curr=head;
  while(curr!=NULL && curr->data!=k)
  { prev=curr;
    curr=curr->next;
  }
  prev->next=curr->next;
  free(curr);
}
int main()
{ int i,n,k,e;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the elements\n");
    scanf("%d",&k);
    create(k);
  }
  display();
  printf("enter the element to be deleted\n");
  scanf("%d",&e);
  delete(e);
  display();
  return 0;
}
