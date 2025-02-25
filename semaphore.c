#include<stdio.h>
#include<stdlib.h>
int mutex=1,x=0,empty=3;
int wait(int s)  {
  s--;
  return s;
}
int signal(int s){
  s++;
  return s;
}
void producer() {
  mutex=wait(mutex);
  x=signal(x);
  empty=wait(empty);
  mutex=signal(mutex);
}
void consumer()  {
  mutex=wait(mutex);
  x=wait(x);
  empty=signal(empty);
  mutex=signal(mutex);
}
void main()  {
  int ch,choice=1;
  while(choice==1)  {
    printf("Enter choice: 1.producer 2.consumer 3.exit\n");
    scanf("%d",&ch);
    switch(ch) {
      case 1: {
        if(mutex==1 && empty!=0){
          producer();
          printf("Produced an item %d successfully...\n",x);
        }
        else
        printf("BUFFER FULL!!!\n");
        break;
      }
      case 2:{
         if(mutex==1 && x!=0){
           consumer();
            printf("Consumed an item %d successfully...\n",x);
         }
         else
         printf("BUFFER EMPTY!!!\n");
         break;
      }
      case 3:{
           printf("Exiting Program...\n");
           exit(0);           
           break;
      }
      default :{
      printf("Wrong choice!!!\n");
      break;
     }
   }
 }
}
