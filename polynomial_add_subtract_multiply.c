#include<stdio.h>
#include<stdlib.h>
struct node
{ int coeff;
  int exp1;
  struct node *next;
};
struct node *head3=NULL;
struct node *head4=NULL;
struct node *head5=NULL;
struct node *head6=NULL;
void simplyify(struct node *head);
void create(struct node **head,int c,int e)
{ struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->coeff=c;
  new->exp1=e;
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
  { printf("%dx^%d+",ptr->coeff,ptr->exp1);
    ptr=ptr->next;
  }
}
void add(struct node *head1, struct node *head2)
{ struct node *t1=head1;
  struct node *t2=head2;
  while(t1!=NULL && t2!=NULL)
  { if(t1->exp1==t2->exp1)
    { create(&head3,t1->coeff+t2->coeff,t1->exp1);
    }
    t1=t1->next;
    t2=t2->next;
  }
  while(t1!=NULL)
  { create(&head3,t1->coeff,t1->exp1);
    t1=t1->next;
  }
  while(t2!=NULL)
  { create(&head3,t2->coeff,t2->exp1);
    t2=t2->next;
  }
  display(head3);
}
void subtract(struct node *head1,struct node *head2)
{ struct node *t1=head1;
  struct node *t2=head2;
  while(t1!=NULL && t2!=NULL)
  { if(t1->exp1==t2->exp1)
    { if(t1->coeff>t2->coeff)
      {
         create(&head4,t1->coeff-t2->coeff,t1->exp1);
      }
      else
      { 
         create(&head4,t2->coeff-t1->coeff,t1->exp1);
      }
    }
    t1=t1->next;
    t2=t2->next;
  }
  while(t1!=NULL)
  { create(&head4,t1->coeff,t1->exp1);
    t1=t1->next;
  }
  while(t2!=NULL)
  { create(&head4,t2->coeff,t2->exp1);
    t2=t2->next;
  }
  display(head4);
}
void multiply(struct node *head1,struct node *head2)
{ struct node *t1=head1;
  struct node *t2=head2;
  while(t1!=NULL && t2!=NULL)
  { create(&head5,t1->coeff*t2->coeff,t1->exp1+t2->exp1);
    t1=t1->next;
    t2=t2->next;
  }
  simplyify(head5);
}
void simplyify(struct node *head)
{ struct node *t=head;
  struct node *t1=head->next;
  while(t!=NULL)
  { while(t1!=NULL)
    { if(t->exp1==t1->exp1)
      { create(&head6,t1->coeff+t->coeff,t1->exp1);
      }
      t1=t1->next;
    }
    t=t->next;
  }
  while(t!=NULL)
  { create(&head6,t->coeff,t1->exp1);
    t=t->next;
  }
  display(head6);
}
int main()
{ int n1,n2;
  struct node *head1=NULL;
  struct node *head2=NULL;
  printf("enter the size of polynomial1 and polynomial2\n");
  scanf("%d%d",&n1,&n2);
  int c1,e1,c2,e2;
  printf("enter the polynomial1\n");
  for(int i=0;i<n1;++i)
  { printf("enter data\n");
    scanf("%d%d",&c1,&e1);
    create(&head1,c1,e1);
  }
  printf("enter the 2nd polynomial\n");
  for(int i=0;i<n2;++i)
  { printf("enter the data\n");
    scanf("%d%d",&c2,&e2);
    create(&head2,c2,e2);
  }
  printf("\nADDITION\n");
  add(head1,head2);
  printf("\nSUBTRACTION\n");
  subtract(head1,head2);
  printf("\nMULTIPLICATION\n");
  multiply(head1,head2);
  return 0;
}
  
  
  
