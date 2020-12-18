//to check palindrome of linkedlist
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
void palindrome()
{ int a[10],k=0;
  struct node *ptr=head;
  while(ptr!=NULL)
  { a[k]=ptr->data;
    ++k;
    ptr=ptr->next;
  }
  int b[10],z=0;
  for(int i=k;i>=0;--i)
  { b[z]=a[i];
    ++z;
  }
  int c=0;
  for(int i=0;i<z;++i)
  { if(a[i]==b[i])
    { ++c;
    }
  }
  if(c==z)
  { printf("palindrome linkedlist\n");
  }
  else
  { printf("not a palindrome\n");
  }
}
int main()
{ int n,e;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  for(int i=0;i<n;++i)
  { printf("enter the element\n");
    scanf("%d",&e);
    create(e);
  }
  display();
  palindrome();
  return 0;
}
