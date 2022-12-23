#include <stdio.h>

int main()
{
    int n, r;
    printf("Enter the no of process along with no of resources: ");
    scanf("%d%d", &n, &r);

    int allocated[n][r], need[n][r], available[r];
    int ans[n];

    printf("Enter the allocated resources :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &allocated[i][j]);
        }
    }

    printf("Enter the Needs :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &need[i][j]);
        }
    }

    printf("Enter the available: ");

    for (int i = 0; i < r; i++)
    {
        scanf("%d", &available[i]);
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int cnt = 0;
    
    while (cnt < n)
    {
        int s = 0;
        int pid = 10000;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < r; j++)
            {
                if (available[j] >= need[i][j] && visited[i] == 0)
                {
                    s = 1;
                    pid = i;
                }
                else
                {
                    s = 0;
                    break;
                }
            }
            if (s == 1)
            {
                break;
            }
            else
            {
                continue;
            }
        }

        if (pid == 10000)
        {
            printf("DEADLOCK..");
            break;
        }

        ans[cnt] = pid;
        cnt++;
        visited[pid] = 1;

        for (int j = 0; j < r; j++)
            available[j] += allocated[pid][j];
    }

    printf("Sequence of process in safe side: \n");
    for (int i = 0; i < n; i++)
    {
        printf("p%d\n", ans[i]);
    }
}