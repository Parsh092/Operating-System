#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
    system("cls");
    int i, j, n, wt[20], bt[20], tat[20], pr[20];
    float awt = 0.0, att = 0.0;
    printf("\n\t Enter the number of process: ");
    scanf("%d", &n);
    printf("\n\t Enter the burst time of the process: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("\n\tEnter the priority of the processes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int tem = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[tem])
            {
                tem = j;
            }
        }

        // Priority array sorting
        int var_at_i = pr[i];
        pr[i] = pr[tem];
        pr[tem] = var_at_i;

        // Burst time array sorting according to priority
        var_at_i = bt[i];
        bt[i] = bt[tem];
        bt[tem] = var_at_i;
    }

    printf("Process\t Burst Time\t Waiting time\t Turn around time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] = wt[i] + bt[j];
        }
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        att += tat[i];
        printf("%d\t %d\t\t %d\t\t %d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    awt = (float)awt / n;
    att = (float)att / n;
    printf("\n\t Average waiting time is: %f", awt);
    printf("\n\t Average turn around time is: %f", att);
    getch();
}

Output: -
    
         Enter the number of process: 5

         Enter the burst time of the process: 3 4 2 1 3

        Enter the priority of the processes: 1 3 2 1 4
Process  Burst Time      Waiting time    Turn around time
1        3               0               3
2        1               3               4
3        2               4               6
4        4               6               10
5        3               10              13

         Average waiting time is: 4.600000
         Average turn around time is: 7.200000
