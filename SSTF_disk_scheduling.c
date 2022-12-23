#include<stdio.h>
#include<math.h>
void SSTF(int input[], int n, int head){

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(input[j]<input[j+1]){
                int temp = input[j];
                input[j]=input[j+1];
                input[j+1]= temp;
            }
        }
    }
    int c=0;
    for(int i=0; i<n; i++){
        if(input[i]<head) 
        c++;
    }

    int headcount=0;
    
    if(fabs(input[c-1]-head) < fabs(input[c]-head))
    headcount = fabs(head-input[0])+fabs(input[0]-input[n-1]);
    else
    headcount = fabs(head-input[n-1])+fabs(input[n-1]-input[0]);

    printf("\n%d",headcount);
}
int main()
{
	int n,head;
	printf("enter the value of n");
	scanf("%d",&n);
	
	printf("Enter the values : ");
	
	int input[n];
	int i;
	for( i=0; i<n ;i++){
		scanf("%d",&input[i]);
	}
	printf("Enter head : ");
	scanf("%d",&head);
	
	SSTF(input,n,head);
}