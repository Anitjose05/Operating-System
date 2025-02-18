#include <stdio.h>
int main() {
    int n, quantum, i, time = 0, remaining;
    
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int btime[n], remaining_time[n], wtime[n], ttime[n];
    
   
    printf("Enter the burst time:\n");
    for (i = 0; i < n; i++) {
        printf("Process-%d burst time: ", i + 1);
        scanf("%d", &btime[i]);
        remaining_time[i] = btime[i];
        wtime[i] = 0;  
    }
    
    
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    remaining = n; 
    int process_order[100], order_time[100], index = 0;

    
    while (remaining > 0) {
        for (i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                
                process_order[index] = i + 1;
                order_time[index] = time;
                index++;

                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    wtime[i] = time - btime[i]; 
                    remaining_time[i] = 0;
                    remaining--;
                }
            }
        }
    }

    
    float avgwt = 0, avgtt = 0;
    printf("\nProcess\tBurst Time\tWait Time\tTurn Around Time\n");
    for (i = 0; i < n; i++) {
        ttime[i] = wtime[i] + btime[i];
        avgwt += wtime[i];
        avgtt += ttime[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, btime[i], wtime[i], ttime[i]);
    }

    avgwt /= n;
    avgtt /= n;
    printf("\n========================================================================\n");
    printf("The average waiting time: %.2f\n", avgwt);
    printf("The average turn around time: %.2f\n", avgtt);

    
    printf("\n========================================================================\n");
    printf("Gantt Chart\n\t");
    for (i = 0; i < index; i++) {
        printf(" P[%d] ", process_order[i]);
    }
    printf("\n========================================================================\n");

    for (i = 0; i < index; i++) {
        printf("%d\t", order_time[i]);
    }
    printf("%d\n", time); 
    
    return 0;
}


