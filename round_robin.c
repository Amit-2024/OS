#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

int findmax(int x, int y){
    return x>y?x:y;
}

struct p{
    int pid,at,bt,tat,rt,wt,rem_bt,start,ct;
}p[10];


int comparator(const void *x, const void *y){
   
    int l = ((struct p*)x)->at;
    int r = ((struct p*)y)->at;

    int c = ((struct p*)x)->pid;
    int d = ((struct p*)y)->pid;

    if(l==r) return c-d;
    return l-r;

}

int main(){
    int n;
    printf("Enter the total process : ");
    scanf("%d",&n);

    printf("Enter the arrival and burst time for processes\n ");
    for(int i=0; i<n; i++){
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].rem_bt = p[i].bt;
        p[i].pid = i;
    }

    qsort((void *)p, n, sizeof p[0] , comparator);

    int completed=0;

    int queue[10];
    int front , rear;
    front,rear=0;
    queue[rear]=0;
    int current_time=0; 
    int tq;
    printf("Enter the time quant : ");
    scanf("%d",&tq);
    bool visited[n];

    for(int i=0; i<n; i++) visited[i]=false;

    visited[0]=true;

    while(completed!=n){
        int index = queue[front];
        front++;

        if(p[index].rem_bt == p[index].bt){
            p[index].start = findmax(current_time,p[index].at);
            current_time = p[index].start;
        }

        if(p[index].rem_bt-tq > 0){
            p[index].rem_bt -= tq;
            current_time += tq;
        }

        else{
            current_time += p[index].rem_bt;
            p[index].rem_bt =0;

            completed++;

            p[index].ct = current_time;
            p[index].tat = p[index].ct-p[index].at;
            p[index].wt = p[index].tat-p[index].bt;
            p[index].rt = p[index].start - p[index].at;
        }


        // if process is remaining let that again in queue at rear
        for(int i=1; i<n; i++){
            if(p[i].rem_bt >0 && p[i].at<=current_time && visited[i] == false){
                queue[++rear]=i;
                visited[i]=true;
            }
        }

        if(p[index].rem_bt > 0){
            queue[++rear] = index;
        }

        // if no process - 
        if(front>rear){
            for(int i=1; i<n; i++){
                if(p[i].rem_bt > 0){
                    queue[rear++]=i;
                    visited[i]=true;
                    break;
                }
            }
        }
    }

    printf("pid at bt st ct tat wt rt\n");
    
    for(int i=0; i<n;i++){
        printf("%d %d %d %d %d %d %d %d\n",p[i].pid,p[i].at, p[i].bt, p[i].start, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    }
}