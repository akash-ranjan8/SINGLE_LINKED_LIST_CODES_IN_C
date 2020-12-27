#include<stdio.h>
#include<stdlib.h>
struct node
{ int coeff;
  int exp1;
  int exp2;
  struct node *next;
};
struct node *head=NULL;
void create(int c,int e1,int e2)
{ struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->coeff=c;
  new->exp1=e1;
  new->exp2=e2;
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
  { printf("%dx^%dy^%d + ",ptr->coeff,ptr->exp1,ptr->exp2);
    ptr=ptr->next;
  }
}
int main()
{ int n,e1,e2,c,i;
  printf("enter the no. of terms\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d%d%d",&c,&e1,&e2);
    create(c,e1,e2);
  }
  display();
  return 0;
}
  
