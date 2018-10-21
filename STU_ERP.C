#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
struct rec
{
 int rno,sem,hno;
 long int pin;
 char name[20],branch[20],father[20],city[20],state[20],country[20],street[20],town[20];
 struct rec *next;
};
typedef struct rec node;
node *start;
int i,num;
void create(node *);
void insert(node *);
void deletion(node *);
void updation(node *);
void display(node *);
void report(node *);
int main()
{
int run=1,ch;
start=(node *)malloc(sizeof(node));
printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
printf("\n");
printf("\t\tWelcome to the Student ERP System\n");
printf("\n");
printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
printf("\n");
while(run==1)
{
 printf("\n-----------$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--------------\n");
 printf("\n");
 printf("\t1. Create new Record\t\t\t 2. Display\n");
 printf("\t3. Insert Record\t\t\t 4. Update\n");
 printf("\t5. Delete Record\t\t\t 6. Exit\n");
 printf("\t7. Report Writing");
 printf("\n");
 printf("\n-----------$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$-------------\n");
 printf("\nEnter your choice");
 scanf("%d",&ch);
 switch(ch)
 {
   case 1:
   {
	create(start);
	break;
   }
   case 2:
   {
	display(start);
	break;
   }
   case 3:
   {
	insert(start);
	break;
   }
   case 4:
   {
	updation(start);
	break;
   }
   case 5:
   {
	deletion(start);
	break;
	}
	case 6:
	{
	 run=0;
	 break;
	}
	case 7:
	{
	 report(start);
	 break;
	}
  }
}
getch();
}
void create(node * ptr)
{
	  char ch;
	  num=0;
	  printf("\nPress 'n' for exiting");
	  ch=getchar();
	if(ch=='n')
	{
	 printf("\n Exiting");
	 exit(1);
	}
	do
	{
	  printf("\nEnter the roll no");
	  scanf("%d",&ptr->rno);
	  printf("\nEnter the name");
	  scanf("%s",ptr->name);
	  printf("\nEnter the branch");
	  scanf("%s",ptr->branch);
	  printf("\nEnter the semester");
	  scanf("%d",&ptr->sem);
	  printf("\nEnter the father's name");
	  scanf("%s",ptr->father);
	  printf("\nEnter the house no");
	  scanf("%d",&ptr->hno);
	  printf("\nEnter the street");
	  scanf("%s",ptr->street);
	  printf("\nEnter the town");
	  scanf("%s",ptr->town);
	  printf("\nEnter the city");
	  scanf("%s",ptr->city);
	  printf("\nEnter the state");
	  scanf("%s",ptr->state);
	  printf("\nEnter the country");
	  scanf("%s",ptr->country);
	  printf("\nEnter the pincode");
	  scanf("%ld",&ptr->pin);
	  fflush(stdin);
	  printf("\ny/n");
	  ch=getchar();
	  if(ch=='y')
		 {
		  ptr->next=(node*)malloc(sizeof(node));
		  ptr=ptr->next;
		 }
		 num++;
	 }while(ch=='y');
	 ptr->next=NULL;
	 printf("\nTotal nodes=%d\n",num);
}
void display(node * ptr)
{
	 while(ptr!=NULL)
	{
	  printf("\nRno:%d",ptr->rno);
	  printf("\nName:%s",ptr->name);
	  printf("\nBranch:%s",ptr->branch);
	  printf("\nSem:%d",ptr->sem);
	  printf("\nPincode:%ld",ptr->pin);
	  printf("\nFather name:%s",ptr->father);
	  printf("\nHno:%d",ptr->hno);
	  printf("\nStreet:%s",ptr->street);
	  printf("\nTown:%s",ptr->town);
	  printf("\nCity:%s",ptr->city);
	  printf("\nState:%s",ptr->state);
	  printf("\nCountry:%s",ptr->country);
	  ptr=ptr->next;
	}
}
void insert(node *ptr)
{
 node *new1;
 int i,roll;
 new1=(node *)malloc(sizeof(node));
 printf("\nEnter roll number after which you want to insert[press 0 for first node]");
 scanf("%d",&roll);

	  if(roll==0)
	  {
	   new1->next=start;
	   start=new1;
	  }
	  else
	{
	  while(ptr!=NULL)
	  {
	  if(ptr->rno==roll)
	  {
		 if(ptr->next==NULL)
		 {
		  new1->next=NULL;
		  ptr->next=new1;
		 }
		 else
		 {
		 new1->next=ptr->next;
		 ptr->next=new1;
		 }
		 break;
	  }
		ptr=ptr->next;
	  }
	   if(ptr==NULL)
	  {
		printf("\nNode doesn't exist");
		getch();
		exit(1);
	  }
	  printf("\nEnter the roll no");
	   scanf("%d",&new1->rno);
	  printf("\nEnter the name");
	  scanf("%s",new1->name);
	  printf("\nEnter the branch");
	  scanf("%s",new1->branch);
	  printf("\nEnter the semester");
	  scanf("%d",&new1->sem);
	  printf("\nEnter the father's name");
	  scanf("%s",new1->father);
	  printf("\nEnter the house no");
	  scanf("%d",&new1->hno);
	  printf("\nEnter the street");
	  scanf("%s",new1->street);
	  printf("\nEnter the town");
	  scanf("%s",new1->town);
	  printf("\nEnter the city");
	  scanf("%s",new1->city);
	  printf("\nEnter the state");
	  scanf("%s",new1->state);
	  printf("\nEnter the country");
	  scanf("%s",new1->country);
	  printf("\nEnter the pincode");
	  scanf("%ld",&new1->pin);
	}
}
void deletion(node *ptr)
{
  node *prev;
  int x;
  printf("\nEnter the roll_no you want to delete");
  scanf("%d",&x);
  while(ptr->rno!=x && ptr!=NULL)
  {
   prev=ptr;
   ptr=ptr->next;
  }
  if(ptr==NULL)
  printf("\nRoll number you want to delete does not exist");
  else
  {
	  if(start->rno==x)
	  start=start->next;
	  else if(ptr->next==NULL)
	  prev->next=NULL;
	  else
	  prev->next=ptr->next;
	  free(ptr);
  }
}
void updation(node *ptr)
{
int roll,ch;
printf("\nEnter the rno whose details are to be updated");
scanf("%d",&roll);
while(ptr!=NULL && ptr->rno!=roll)
{
 ptr=ptr->next;
}
if(ptr==NULL)
{
printf("\nNo such roll no exists");
exit(1);
}
printf("\nEnter the detail you want to update");
	  printf("\n 1. Name");
	  printf("\n 2. Branch");
	  printf("\n 3. Semester");
	  printf("\n 4. Father's name");
	  printf("\n 5. House no");
	  printf("\n 6. Street");
	  printf("\n 7. Town");
	  printf("\n 8. City");
	  printf("\n 9. State");
	  printf("\n 10. Country");
	  printf("\n 11. Pincode");
	  scanf("%d",&ch);
	  switch(ch)
	  {
		 case 1:
		 {
		  printf("\nEnter the name");
		  scanf("%s",ptr->name);
		  break;
		 }
		 case 2:
		 {
		  printf("\nEnter the branch");
		  scanf("%s",ptr->branch);
		  break;
		 }
		 case 3:
		 {
		  printf("\nEnter the semester");
		  scanf("%d",&ptr->sem);
		  break;
		 }
		 case 4:
		 {
		  printf("\nEnter the father");
		  scanf("%s",ptr->father);
		  break;
		 }
		 case 5:
		 {
		  printf("\nEnter the hno");
		  scanf("%d",&ptr->hno);
		  break;
		 }
		  case 6:
		 {
		  printf("\nEnter the street");
		  scanf("%s",ptr->street);
		  break;
		 }
		 case 7:
		 {
		  printf("\nEnter the town");
		  scanf("%s",ptr->town);
		  break;
		 }
		 case 8:
		 {
		  printf("\nEnter the city");
		  scanf("%s",ptr->city);
		  break;
		 }
		 case 9:
		 {
		  printf("\nEnter the state");
		  scanf("%s",ptr->state);
		  break;
		 }
		 case 10:
		 {
		  printf("\nEnter the country");
		  scanf("%s",ptr->country);
		  break;
		 }
		 case 11:
		 {
		  printf("\nEnter the pin");
		  scanf("%ld",&ptr->pin);
		  break;
		 }
		 default:
		 {
		  printf("\nWrong field entered");
		  break;
		 }
	  }
}
void report(node *ptr)
{
	  int i,flag=1;
	  while(flag==1)
	{
	  printf("\n 1. Name");
	  printf("\n 2. Branch");
	  printf("\n 3. Semester");
	  printf("\n 4. Father's name");
	  printf("\n 5. House no");
	  printf("\n 6. Street");
	  printf("\n 7. Town");
	  printf("\n 8. City");
	  printf("\n 9. State");
	  printf("\n 10. Country");
	  printf("\n 11. Pincode");
	  printf("\n 12. Roll_no");
	  printf("\n 13. exit");
	  printf("\nEnter the field number you want to search by");
	  scanf("%d",&i);
	  switch(i)
	  {
		case 1:
		{
		  char name1[20];int flag2=0;
		  printf("\nEnter the name you want to search");
		  scanf("%s",&name1);
		   while(ptr!=NULL)
		   {
			if(strcmp(ptr->name,name1)==0)
			{
			printf("\nRno:%d",ptr->rno);
			printf("\nName:%s",ptr->name);
			printf("\nBranch:%s",ptr->branch);
			printf("\nSem:%d",ptr->sem);
			printf("\nPincode:%ld",ptr->pin);
			printf("\nFather name:%s",ptr->father);
			printf("\nHno:%d",ptr->hno);
			printf("\nStreet:%s",ptr->street);
			printf("\nTown:%s",ptr->town);
			printf("\nCity:%s",ptr->city);
			printf("\nState:%s",ptr->state);
			printf("\nCountry:%s",ptr->country);
			flag2=1;
			}
			ptr=ptr->next;
		   }
		   if(flag2==0)
		   {
		   printf("\nRecord does not exist");
		   break;
		   }
		   break;
		}
		case 2:
		{
		char branch1[20];int flag2=0;
		  printf("\nEnter the branch you want to search");
		  scanf("%s",&branch1);
		   while(ptr!=NULL)
		   {
			if(strcmp(ptr->branch,branch1)==0)
			{
			printf("\nRno:%d",ptr->rno);
			printf("\nName:%s",ptr->name);
			printf("\nBranch:%s",ptr->branch);
			printf("\nSem:%d",ptr->sem);
			printf("\nPincode:%ld",ptr->pin);
			printf("\nFather name:%s",ptr->father);
			printf("\nHno:%d",ptr->hno);
			printf("\nStreet:%s",ptr->street);
			printf("\nTown:%s",ptr->town);
			printf("\nCity:%s",ptr->city);
			printf("\nState:%s",ptr->state);
			printf("\nCountry:%s",ptr->country);
			flag2=1;
			}
			ptr=ptr->next;
		   }
		   if(flag2==0)
		   {
		   printf("\nRecord does not exist");
		   break;
		   }
		   break;
		}
		case 3:
		{
		 int sem1,flag2=0;
		  printf("\nEnter the sem you want to search");
		  scanf("%d",&sem1);
		  while(ptr!=NULL)
		 {
		   if(ptr->sem==sem1)
		   {
			printf("\nRno:%d",ptr->rno);
			printf("\nName:%s",ptr->name);
			printf("\nBranch:%s",ptr->branch);
			printf("\nSem:%d",ptr->sem);
			printf("\nPincode:%ld",ptr->pin);
			printf("\nFather name:%s",ptr->father);
			printf("\nHno:%d",ptr->hno);
			printf("\nStreet:%s",ptr->street);
			printf("\nTown:%s",ptr->town);
			printf("\nCity:%s",ptr->city);
			printf("\nState:%s",ptr->state);
			printf("\nCountry:%s",ptr->country);
			flag2=1;
		   }
		   ptr=ptr->next;
		  }
		  if(flag2==0)
		  {
		   printf("\nRecord does not  exist");
		   break;
		  }
		   break;
		}
		case 4:
		{
		  char name1[20];int flag2=0;
		  printf("\nEnter the father's name you want to search");
		  scanf("%s",&name1);
		  while(ptr!=NULL)
		 {
		   if(strcmp(ptr->father,name1)==0)
		   {
			printf("\nRno:%d",ptr->rno);
			printf("\nName:%s",ptr->name);
			printf("\nBranch:%s",ptr->branch);
			printf("\nSem:%d",ptr->sem);
			printf("\nPincode:%ld",ptr->pin);
			printf("\nFather name:%s",ptr->father);
			printf("\nHno:%d",ptr->hno);
			printf("\nStreet:%s",ptr->street);
			printf("\nTown:%s",ptr->town);
			printf("\nCity:%s",ptr->city);
			printf("\nState:%s",ptr->state);
			printf("\nCountry:%s",ptr->country);
			flag2=1;
		   }
		   ptr=ptr->next;
		  }
		  if(flag2==0)
		  {
		   printf("\nRecord doesn not exist");
			break;
		  }
		   break;
		}
		case 5:
		{
		  int name1,flag2=0;
		  printf("\nEnter the hno you want to search");
		  scanf("%d",&name1);
		  while(ptr!=NULL)
		 {
		   if(ptr->hno==name1)
		   {
			printf("\nRno:%d",ptr->rno);
			printf("\nName:%s",ptr->name);
			printf("\nBranch:%s",ptr->branch);
			printf("\nSem:%d",ptr->sem);
			printf("\nPincode:%ld",ptr->pin);
			printf("\nFather name:%s",ptr->father);
			printf("\nHno:%d",ptr->hno);
			printf("\nStreet:%s",ptr->street);
			printf("\nTown:%s",ptr->town);
			printf("\nCity:%s",ptr->city);
			printf("\nState:%s",ptr->state);
			printf("\nCountry:%s",ptr->country);
			flag2=1;
		   }
		   ptr=ptr->next;
		  }
		  if(flag2==0)
		  {
		   printf("\nRecord does not exist");
			break;
		  }
		   break;
		}
		case 6:
		{
		 char name1[20];int flag2=0;
		  printf("\nEnter the street you want to search");
		  scanf("%s",&name1);
		  while(ptr!=NULL)
		 {
		   if(strcmp(ptr->street,name1)==0)
		   {
			printf("\nRno:%d",ptr->rno);
			printf("\nName:%s",ptr->name);
			printf("\nBranch:%s",ptr->branch);
			printf("\nSem:%d",ptr->sem);
			printf("\nPincode:%ld",ptr->pin);
			printf("\nFather name:%s",ptr->father);
			printf("\nHno:%d",ptr->hno);
			printf("\nStreet:%s",ptr->street);
			printf("\nTown:%s",ptr->town);
			printf("\nCity:%s",ptr->city);
			printf("\nState:%s",ptr->state);
			printf("\nCountry:%s",ptr->country);
			flag2=1;
		   }
		   ptr=ptr->next;
		  }
		  if(flag2==0)
		  {
		   printf("\nRecord does not exist");
			break;
		  }
		   break;
		}
		case 7:
		{
		 char name1[20];int flag2=0;
		  printf("\nEnter the town you want to search");
		  scanf("%s",&name1);
		  while(ptr!=NULL)
		 {
		   if(strcmp(ptr->town,name1)==0)
		   {
			printf("\nRno:%d",ptr->rno);
			printf("\nName:%s",ptr->name);
			printf("\nBranch:%s",ptr->branch);
			printf("\nSem:%d",ptr->sem);
			printf("\nPincode:%ld",ptr->pin);
			printf("\nFather name:%s",ptr->father);
			printf("\nHno:%d",ptr->hno);
			printf("\nStreet:%s",ptr->street);
			printf("\nTown:%s",ptr->town);
			printf("\nCity:%s",ptr->city);
			printf("\nState:%s",ptr->state);
			printf("\nCountry:%s",ptr->country);
			flag2=1;
		   }
		   ptr=ptr->next;
		  }
		  if(flag2==0)
		  {
		   printf("\nRecord doesn not exist");
			break;
		  }
		   break;
		}
		case 8:
		{
		 char name1[20];int flag2=0;
		  printf("\nEnter the city you want to search");
		  scanf("%s",&name1);
		  while(ptr!=NULL)
		 {
		   if(strcmp(ptr->city,name1)==0)
		   {
			printf("\nRno:%d",ptr->rno);
			printf("\nName:%s",ptr->name);
			printf("\nBranch:%s",ptr->branch);
			printf("\nSem:%d",ptr->sem);
			printf("\nPincode:%ld",ptr->pin);
			printf("\nFather name:%s",ptr->father);
			printf("\nHno:%d",ptr->hno);
			printf("\nStreet:%s",ptr->street);
			printf("\nTown:%s",ptr->town);
			printf("\nCity:%s",ptr->city);
			printf("\nState:%s",ptr->state);
			printf("\nCountry:%s",ptr->country);
			flag2=1;
		   }
		   ptr=ptr->next;
		  }
		  if(flag2==0)
		  {
		   printf("\nRecord does not exist");
			break;
		  }
		   break;
		}
		case 9:
		{
		 char name1[20];int flag2=0;
		  printf("\nEnter the state you want to search");
		  scanf("%s",&name1);
		  while(ptr!=NULL)
		 {
		   if(strcmp(ptr->state,name1)==0)
		   {
			printf("\nRno:%d",ptr->rno);
			printf("\nName:%s",ptr->name);
			printf("\nBranch:%s",ptr->branch);
			printf("\nSem:%d",ptr->sem);
			printf("\nPincode:%ld",ptr->pin);
			printf("\nFather name:%s",ptr->father);
			printf("\nHno:%d",ptr->hno);
			printf("\nStreet:%s",ptr->street);
			printf("\nTown:%s",ptr->town);
			printf("\nCity:%s",ptr->city);
			printf("\nState:%s",ptr->state);
			printf("\nCountry:%s",ptr->country);
			flag2=1;
		   }
		   ptr=ptr->next;
		  }
		  if(flag2==0)
		  {
		   printf("\nRecord does not exist");
			break;
		  }
		   break;
		}
		case 10:
		{
		char name1[20];int flag2=0;
		  printf("\nEnter the country you want to search");
		  scanf("%s",&name1);
		  while(ptr!=NULL)
		 {
		   if(strcmp(ptr->country,name1)==0)
		   {
			printf("\nRno:%d",ptr->rno);
			printf("\nName:%s",ptr->name);
			printf("\nBranch:%s",ptr->branch);
			printf("\nSem:%d",ptr->sem);
			printf("\nPincode:%ld",ptr->pin);
			printf("\nFather name:%s",ptr->father);
			printf("\nHno:%d",ptr->hno);
			printf("\nStreet:%s",ptr->street);
			printf("\nTown:%s",ptr->town);
			printf("\nCity:%s",ptr->city);
			printf("\nState:%s",ptr->state);
			printf("\nCountry:%s",ptr->country);
			flag2=1;
		   }
		   ptr=ptr->next;
		  }
		  if(flag2==0)
		  {
		   printf("\nRecord does not exist");
			break;
		  }
		   break;
		}
		case 11:
		{
		 long int name1,flag2=0;
		  printf("\nEnter the pin you want to search");
		  scanf("%ld",&name1);
		  while(ptr!=NULL)
		 {
		   if(ptr->pin==name1)
		   {
			printf("\nRno:%d",ptr->rno);
			printf("\nName:%s",ptr->name);
			printf("\nBranch:%s",ptr->branch);
			printf("\nSem:%d",ptr->sem);
			printf("\nPincode:%ld",ptr->pin);
			printf("\nFather name:%s",ptr->father);
			printf("\nHno:%d",ptr->hno);
			printf("\nStreet:%s",ptr->street);
			printf("\nTown:%s",ptr->town);
			printf("\nCity:%s",ptr->city);
			printf("\nState:%s",ptr->state);
			printf("\nCountry:%s",ptr->country);
			flag2=1;
		   }
		   ptr=ptr->next;
		  }
		  if(flag2==0)
		  {
		   printf("\nRecord does not exist");
			break;
		  }
		   break;
		}
		case 12:
		{
		 int name1,flag2=1;
		  printf("\nEnter the roll_no you want to search");
		  scanf("%d",&name1);
		  while(ptr!=NULL)
		 {
		   if(ptr->rno==name1)
		   {
			printf("\nRno:%d",ptr->rno);
			printf("\nName:%s",ptr->name);
			printf("\nBranch:%s",ptr->branch);
			printf("\nSem:%d",ptr->sem);
			printf("\nPincode:%ld",ptr->pin);
			printf("\nFather name:%s",ptr->father);
			printf("\nHno:%d",ptr->hno);
			printf("\nStreet:%s",ptr->street);
			printf("\nTown:%s",ptr->town);
			printf("\nCity:%s",ptr->city);
			printf("\nState:%s",ptr->state);
			printf("\nCountry:%s",ptr->country);
			flag2=1;
		   }
		   ptr=ptr->next;
		 }
			if(flag2==0)
			{
			printf("\nRecord does not exist");
			break;
		   }
		   break;
		}
		case 13:
		{
		flag=0;
		break;
		}
	  }
	}
}
