#include<stdio.h>
#include<math.h>

int main(){
    int n;
    printf("Enter no. of request: ");
    scanf("%d",&n);

    int request[n];

    int head;
    printf("Enter the head: ");
    scanf("%d",&head);

    printf("ENTER THE REQUESTS : ");
    for(int i=0; i<n; i++){
        scanf("%d",&request[i]);
    }   
    int headcount=0;

    for(int i=0; i<n;i ++){
        headcount +=  fabs(request[i]-head);
        head = request[i];
    }

    printf("Total headcount : %d",headcount);
}