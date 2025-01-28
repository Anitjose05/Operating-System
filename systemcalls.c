 #include<sys/types.h>
 #include<unistd.h>
 #include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>
 void main () {
  pid_t childid=fork();
  if (childid==0) {
  printf("Child is created\n ");
  printf("Child id=%d\n",getpid());
  printf("Parent id=%d\n",getppid());
  }
  if (childid>0) {
  printf("Parent and Child is successfully created\n");
  printf("Child process id:%d\n",childid);
  printf("Parent process id:%d\n",getpid());
  wait(NULL);
  printf("Child process is terminate and parent is moved from running state to waiting state");
  }
  if (childid<0) {
  printf("Child is not created");
  }
  exit (0);
  }
