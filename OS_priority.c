#include <stdio.h>
#include <stdlib.h>
#define max 30
int main()
{
    int i, j, n, t, pr[max], bt[max], wt[max], tat[max], pos;
    float awt = 0.0f, atat = 0.0f;
    system("cls");
    printf("Enter the number of process: ");
    scanf("%d", &n);

    printf("\nEnter the burst time of the processes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    printf("Enter the priority of processes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pr[i]);
    }

    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
            {
                pos = j;
            }
        }
        t = pr[i];
        pr[i] = pr[pos];
        pr[pos] = t;

        t = bt[i];
        bt[i] = bt[pos];
        bt[pos] = t;
    }
    wt[0] = 0;
    printf("Process\t Burst time\t Waiting time\t Turn around time\n");
    for (int i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] = wt[i] + bt[j];
        }
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t %d\t\t %d\t\t %d\t\t %d\n", i + 1, bt[i], pr[i], wt[i], tat[i]);
    }
    awt = (float)awt / n;
    atat = (float)atat / n;
    printf("\nAverage waiting time = %f", awt);
    printf("\nAverage turn around time = %f", atat);
    return 0;
}