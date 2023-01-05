#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
    system("cls");
    int i, j, n, wt[20], bt[20], tat[20];
    float awt = 0.0, att = 0.0;
    printf("\n\t Enter the number of process: ");
    scanf("%d", &n);
    printf("\n\t Enter the burst time of the process: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        int tem = i;
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[tem])
            {
                tem = j;
            }
        }
        int temp = bt[i];
        bt[i] = bt[tem];
        bt[tem] = temp;
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
       Enter the number of process: 4

         Enter the burst time of the process: 6 8 7 3
Process  Burst Time      Waiting time    Turn around time
1        3               0               3
2        6               3               9
3        7               9               16
4        8               16              24

         Average waiting time is: 7.000000
         Average turn around time is: 13.000000
