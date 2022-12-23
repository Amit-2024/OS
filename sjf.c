// shortest job first (non - preemtive)

#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
struct sjf{
    int pid,at,bt,ct,tat,wt,start_time;
}p;

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
    printf("Enter the total process: ");
    scanf("%d",&n);

    struct sjf p[n];

    for(int i=0; i<n; i++)
    {
        printf("Enter the arrival and burst time for process %d : ",i);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid=i;
    }

    int completed =0;
    int current_time =0; 
    bool isfirstprocess = true;

    bool is_completed[n];
    int totalidle=0;
    int prev =0 ;
    while(completed!=n)
    {
        int min_index = -1;
        int minimum = INT_MAX;

        for(int i=0; i<n; i++)
        {
            if(p[i].at<=current_time && is_completed[i]==false)
            {
                if(p[i].bt<minimum)
                {
                    minimum=p[i].bt;
                    min_index=i;
                }
                if(p[i].bt==minimum)
                {
                    if(p[i].at<p[min_index].at)
                    {
                        minimum=p[i].bt;
                        min_index=i;
                    }
                }
            }
        }
        

            if(min_index==-1)
            current_time++;

            else
            {

                p[min_index].start_time=current_time;
                p[min_index].ct = p[min_index].start_time+p[min_index].bt;
                p[min_index].tat = p[min_index].ct - p[min_index].at;
                p[min_index].wt = p[min_index].tat-p[min_index].bt;

                totalidle += (isfirstprocess==true)?0:(p[min_index].start_time-prev);
                completed++;

                is_completed[min_index]=true;
                current_time = p[min_index].ct;
                prev = current_time;
                isfirstprocess = false;
            }
    }
    
        int max_completion = INT_MIN;
        int min_arrival = INT_MAX;

        for(int i=0; i<n; i++)
        {
            max_completion = findmax(max_completion,p[i].ct);
            min_arrival = findmin(min_arrival,p[i].at);
        }

        int length_cycle = max_completion-min_arrival;
        
        float cpuUtiliztion = (float)(length_cycle - totalidle)/length_cycle;
        
       printf("Pid\tAt\tbt\twt\ttat\tct\n");

        for(int i=0; i<n; i++)
        {
            printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tat,p[i].ct);
        }
        
        printf("CPU utilisation time : %f\n", cpuUtiliztion*100);
        printf("throughput : %f",(float)n/length_cycle);
        
}