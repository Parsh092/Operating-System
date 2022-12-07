#include <stdio.h>
#include <stdlib.h>
#define max 30
int main()
{
    int i, j, n, t, p[max], bt[max], wt[max], tat[max];
    float awt = 0.0f, atat = 0.0f;
    system("cls");
    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter the process number: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("\nEnter the burst time of the processes: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                int tem = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = tem;

                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
    printf("Process\t Burst time\t Waiting time\t Turn aroundtime\n");
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
        printf("%d\t %d\t\t %d\t\t %d\n", p[i], bt[i], wt[i], tat[i]);
    }
    awt = (float)awt / n;
    atat = (float)atat / n;
    printf("\nAverage waiting time = %f", awt);
    printf("\nAverage turn around time = %f", atat);
    return 0;
}