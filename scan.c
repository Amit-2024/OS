#include<stdio.h>

void scan(int input[], int n,int head){
	int curr,seek=0;
	int i,j;
	for( i=0; i<n-1; i++){
		for(j=0; j<n-1-i; j++){
			if(input[j]>input[j+1])
			{
				int t = input[j+1];
				input[j+1]=input[j];
				input[j]=t;
			}
		}
	}
	
	int range = 199;
	
	seek = fabs(range-head)+fabs(range-input[0]); // for greater
	int seek1 = fabs(0-head)+fabs(0-input[n-1]); // for lower
	printf("Seek: %d\n",seek);
	printf("Seek1: %d",seek1);
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
	
	scan(input,n,head);
	
}
