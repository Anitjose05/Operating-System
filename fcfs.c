#include<stdio.h>
void main () 
{
   int n,i,j;
     double avgwait=0,avgtat=0;
     printf("Enter the number of processes: ");
     scanf("%d",&n);
     int btime[n],wtime[n],tattime[n];
     printf("Enter the burst time of the processes\n");
     for(i=0;i<n;i++) {
         printf("P%d Burst time: ",(i+1));
         scanf("%d",&btime[i]);
     }
     wtime[0]=0;
     for(i=0;i<n;i++) {
         wtime[i]=wtime[i-1]+btime[i-1];
         avgwait=avgwait+wtime[i];
     }
     avgwait=avgwait/n;
     for(i=0;i<n;i++) {
          tattime[i]=wtime[i]+btime[i];
          avgtat=avgtat+tattime[i];
     }
     avgtat=avgtat/n;
     printf("PID\tBT\tWT\tTAT\n");
     for(i=0;i<n;i++) {
          printf("P%d\t%d\t%d\t\%d\n",i+1,btime[i],wtime[i],tattime[i]);
     }
     printf("\n");
     printf("Average Waiting Time: %.2f\nAverage Turn Around Time: %.2f\n",avgwait,avgtat);
     printf("\n");
     printf("Gantt Chart\n");
     for(i=0;i<n;i++) {
          printf("---------");
     }
     printf("\n|  ");
     for(i=0;i<n;i++) {
          printf("  P%d   |",i+1);
     }
     printf("\n");
     for(i=0;i<n;i++) {
          printf("---------");
     }
     printf("\n0\t");
     int ctime=0;
     for(i=0;i<n;i++) {
          ctime=ctime+btime[i];
          printf("%d\t",ctime);
     }
     printf("\n");
}

