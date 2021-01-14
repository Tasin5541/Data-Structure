#include<stdio.h>

int move=0;

void hanoi(int num,char i,char j,char k);

void main()
{
  int n;
  printf("Enter the no. of disks : ");
  scanf("%d",&n);
  if(n<1)
     printf("\nThere's nothing to move.");
  else
  {
      printf("\nSimulation : \n");
      hanoi(n,'I','J','K');
      printf("\n\ntotal moves : %d\n",move);
  }
}

void hanoi(int num,char i,char j,char k)
{
  char stack[50],stack_i[50],stack_j[50],stack_k[50],stkadd[50],temp;
  int top,add;
  top=NULL;
  one:
	if(num==1)
	{
	  printf("\nMove top disk from %c to %c ",i,k);
	  move++;
	  goto four;
	}
  two:
	top=top+1;
	stack[top]=num;
	stack_i[top]=i;
	stack_j[top]=j;
	stack_k[top]=k;
	stkadd[top]=3;
	num=num-1;
	i=i;
	temp=j;
	j=k;
	k=temp;
	goto one;
  three:
	printf("\nMove top disk from %c to %c ",i,k);
	move++;
	top=top+1;
	stack[top]=num;
	stack_i[top]=i;
	stack_j[top]=j;
	stack_k[top]=k;
	stkadd[top]=5;
	num=num-1;
	temp=i;
	i=j;
	j=temp;
	k=k;
	goto one;
  four:
	if(top==NULL)
	  return;
	num=stack[top];
	i=stack_i[top];
	j=stack_j[top];
	k=stack_k[top];
	add=stkadd[top];
	top=top-1;
	if(add==3)
	  goto three;
	else if(add==5)
	  goto four;
}
