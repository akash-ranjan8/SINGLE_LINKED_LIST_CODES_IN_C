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
void delete_last_occurence(int e)
{ struct node *t=head;
  int d=0,i=0,p[10];
  while(t!=NULL)
  { i++;
    if(t->data==e)
    { p[d]=i;
      ++d;
    }
    t=t->next;
  }
  int max=p[0];
  for(int j=0;j<d;++j)
  { if(max<p[j])
    { max=p[j];
    }
  }
  struct node *t1=head;
  while(t1!=NULL && i<max)
  { t1=t1->next;
  }
  struct node *temp=t1->next;
  t1->next=t1->next->next;
  free(temp);
}
int main()
{ int n,e,k;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  for(int i=0;i<n;++i)
  { printf("enter the element\n");
    scanf("%d",&e);
    create(e);
  }
  display();
  printf("ente the element\n");
  scanf("%d",&k);
  delete_last_occurence(k);
  display();
  return 0;
}
  
      
