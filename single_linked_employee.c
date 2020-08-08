#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct personal
{ char name[100];
  int emp_no;
  char se;
  float salary;
  struct personal *next;
};
struct personal *head=NULL;
void create(char n[100],int e, char s,float sa)
{ struct personal *new;
  new=(struct personal*)malloc(sizeof(struct personal));
  strcpy(new->name,n);
  new->emp_no=e;
  new->se=s;
  new->salary=sa;
  new->next=NULL;
  new->next=NULL;
  if(head==NULL)
  { head=new;
  }
  else
  { struct personal *t;
    t=head;
    while(t->next!=NULL)
    { t=t->next;
    }
    t->next=new;
  }
}
void display()
{ struct personal *ptr;
  ptr=head;
  while(ptr!=NULL)
  { printf("NAME: %s\n",ptr->name);
    printf("EMPLOYEE ID: %d\n",ptr->emp_no);
    printf("SEX: %d\n",ptr->se);
    printf("SALARY: %f\n",ptr->salary);
    ptr=ptr->next;
  }
}
int main()
{ int n1,i;
  char n[100],s;
  int e;
  float sa;
  printf("enter the no. of employess\n");
  scanf("%d",&n1);
  for(i=0;i<n1;++i)
  {  printf("enter the details\n");
     fgets(n,sizeof(n),stdin);
     scanf("%d",&e);
     scanf("%c",&s);
     scanf("%f",&sa);
     create(n,e,s,sa);
     display();
  }
  return 0;
}

  
