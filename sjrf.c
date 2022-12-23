#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

struct sjrf{
    int pid,at,bt,ct,start,tat,wt,rt;
};

int findmax(int x, int y)
{
    return x>y?x:y;
}

int findmin(int x , int y)
{
    return x<y?x:y;
}

int main()
{
    int n;
    printf("Enter total number of process : ");
    scanf("%d",&n);

    struct sjrf p[n];

    int remaining_bt[n];

    for(int i=0; i<n; i++)
    {
        printf("Enter the Arrival & burst time for process %d: ",i);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid=i;
        remaining_bt[i]=p[i].bt;
    }

    int completed=0;
    int current_time=0;
    bool iscompleted[n];
    int sumTAT=0,sumWT=0,sumRT=0 ;
    bool isfirst=false;
    int prev=0;
    int Totalidle=0;

    while(completed!=n)
    {
        int min_index=-1;
        int minimum = INT_MAX;

        for(int i=0; i<n; i++)
        {
            if(p[i].at<=current_time && iscompleted[i]==false)
            {
                if(remaining_bt[i]<minimum)
                {
                    minimum=remaining_bt[i];
                    min_index=i;
                }
                if(remaining_bt[i]==minimum)
                {
                    if(p[i].at<p[min_index].at){
                        minimum=remaining_bt[i];
                        min_index=i;
                    }
                }

            }
        }

        if(min_index==-1)
        {//no process found
            current_time++;
        }
        else
        {
            if(remaining_bt[min_index]==p[min_index].bt)
            {
                p[min_index].start = current_time;
                Totalidle += (isfirst==true)?0:(p[min_index].start-prev);
                isfirst=false;
            }
            remaining_bt[min_index]-=1;
            current_time++;
            prev = current_time;

            if(remaining_bt[min_index]==0)
            {
                p[min_index].ct = current_time;
                p[min_index].tat = p[min_index].ct-p[min_index].at;
                p[min_index].wt =  p[min_index].tat - p[min_index].bt;
                p[min_index].rt = p[min_index].start - p[min_index].at;

                sumTAT+=p[min_index].tat;
                sumWT +=p[min_index].wt;
                sumRT+=p[min_index].rt;

                completed++;
                iscompleted[min_index]=true;
            }

        }

    }
        int max_completion = INT_MAX;
        int min_arrival = INT_MAX;

        for(int i=0; i<n; i++)
        {
            max_completion = findmax(max_completion,p[i].ct);
            min_arrival = findmin(min_arrival,p[i].at);
        }

        int length_cycle = max_completion-min_arrival;

        printf("pid\tat\tbt\ttat\twt\trt\tct\n");

        for(int i=0 ;i<n; i++)
        {
            printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].tat,p[i].wt,p[i].rt,p[i].ct);
        }
}