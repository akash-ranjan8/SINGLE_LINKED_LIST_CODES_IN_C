#include<stdio.h>
#include<stdlib.h>
struct node 
{ int data;
  struct node *next;
};
void create(struct node **head,int d)
{ struct node *new;
  new=(struct node *)malloc(sizeof(struct node));
  new->data=d;
  new->next=NULL;
  if(*head==NULL)
  { *head=new;
  }
  else
  { struct node *t=*head;
    while(t->next!=NULL)
    { t=t->next;
    }
    t->next=new;
  }
}
void display(struct node *head)
{ struct node *ptr=head;
  while(ptr!=NULL)
  { printf("%d\t",ptr->data);
    ptr=ptr->next;
  }
}
void traverse_M_leaving_N(struct node *head,int m,int n)
{ struct node *t=head;
  struct node *t1;
  int i,j;
  while(t)
  { for(i=1;i<m,t!=NULL;++i)
    { t=t->next;
    }
    if(t==NULL)
    { return;
    }
    t1=t->next;
    for(j=1;j<=n,t1!=NULL;++j)
    { struct node *temp=t1;
      t1=t1->next;
      free(temp);
    }
    t->next=t1;
    t=t1;
  }
  
}
int main()
{ int n,e;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  struct node *head=NULL;
  for(int i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&e);
    create(&head,e);
  }
  display(head);
  int m,n1;
  printf("enter the value of m,n\n");
  scanf("%d%d",&m,&n1);
  traverse_M_leaving_N(head,m,n1);
  printf("\n New List\n");
  display(head);
  return 0;
}
  

  
