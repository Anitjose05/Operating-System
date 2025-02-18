#include <stdio.h>
void main() {
    int n, i, j, temp, time = 0,wtime[n],ttime[n];
    float avgwt=0,avgtt=0; 
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], tt[n], p[n];
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Burst Time for P%d: ", p[i]);
        scanf("%d", &bt[i]);
    }    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }
    wt[0] = 0; 
    for (i = 1; i < n; i++)
      {
        wt[i] = wt[i - 1] + bt[i - 1];
        avgwt+=wtime[i];
      }
  avgwt/=n;
  
        

    for (i = 0; i < n; i++)
      {
        tt[i] = wt[i] + bt[i];
        avgtt+=ttime[i];
      }
  avgtt/=n;
  printf("Average waiting time = %f\n",avgwt);
  printf("Average turn around time = %f\n",avgtt);

   
    printf("\nP\tBT\tWT\tTT");
    for (i = 0; i < n; i++)
        printf("\nP%d\t%d\t%d\t%d", p[i], bt[i], wt[i], tt[i]);

    
    printf("\n\nGantt Chart:\n");
    for (i = 0; i < n; i++)
        printf("--------");
    printf("\n|");
    for (i = 0; i < n; i++)
        printf(" P%d |", p[i]);
    printf("\n");
    for (i = 0; i < n; i++)
        printf("--------");

    printf("\n0  ");
    for (i = 0; i < n; i++) {
        time += bt[i];
        printf("   %d ", time);
    }
}
