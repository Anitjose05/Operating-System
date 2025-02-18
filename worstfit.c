#include<stdio.h>
void main()
{
  int memblk,limit,i,j;
  printf("Enter the no:of memory blocks:");
  scanf("%d",&memblk);
  printf("Enter the no:of process:");
  scanf("%d",&limit);
  struct memory {
    int size,alloc;
  } m[memblk];
  struct process  {
   int psize,flag;
  } p[limit];
  printf("Enter the size of memory block\n");
  for(i=0;i<memblk;i++)  {
   scanf("%d",&m[i].size);
   m[i].alloc=0;
  }
  for(i=0;i<memblk;i++)  {
   for(j=i+1;j<memblk;j++)  {
      if(m[i].size<=m[j].size)  {
        int temp=m[i].size;
        m[i].size=m[j].size;
        m[j].size=temp;
      }
    }
  }
  printf("Enter the size of the processes\n");
  for(i=0;i<limit;i++) {
   scanf("%d",&p[i].psize);
   p[i].flag=0;
  }
  printf("\nProcess\tProcess Size\tBlocks\t\n");
  for(i=0;i<limit;i++)  {
   for(j=0;j<memblk;j++)  {
    if(p[i].flag==0)  {
     if(p[i].psize<=m[j].size)  {
      if(m[j].alloc==1)  {
       continue;
      }
      else  {
      m[j].alloc=1;
      p[i].flag=1;
      printf("\n%d\t%d\t\t%d\n",i,p[i].psize,m[j].size);
      }
    }
   } 
  }
 }
 for(i=0;i<limit;i++)  {
  if(p[i].flag==0)  {
   printf("There is no space for process %d of process size %d & it is in waiting state!!!\n",i,p[i].psize);
  }
 }
}
