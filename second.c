#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main () {
char *args[]={"./EXEC",NULL};
execvp(args[0],args);
printf("END\n");
}
