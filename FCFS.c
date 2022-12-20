//first come first server (non-preemtive);
#include<stdio.h>

struct fcfs
{
    int pid,at,bt,tat,wt,ct;
};

int main()
{
    int n;
    
    printf("Enter the total no. of process : ");
    scanf("%d",&n);

    struct fcfs p[n];
    
    for(int i=0; i<n; i++)
    {
        printf("Enter the Arrival time & burst time of process %d: \n",i);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid=i;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(p[j].at>p[j+1].at)
            {
                struct fcfs temp=p[j+1];
                p[j+1]=p[j];
                p[j]=temp;
            }
        }
    }

    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum += p[i].bt;
        p[i].ct=sum;
        p[i].tat = p[i].ct-p[i].at;
        p[i].wt = p[i].tat-p[i].bt;
    }

    printf("Pid\tArrivalTime\tBurstTime\tTurnAroundTime\tcompletion_time\twaiting_time\n");
    
    int tat=0;
    int wait=0;
    for(int i=0; i<n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].tat,p[i].ct,p[i].wt);
        tat+=p[i].tat;
        wait+=p[i].wt;
    }

    printf("Avg of tat : %f\n",(float)tat/n);
    printf("Avg of wt : %f\n",(float)wait/n);
}
