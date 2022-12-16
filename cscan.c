#include<stdio.h>
#include<math.h>
void cscan(int input[], int n,int head){
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

    int c=0;

    for(int i=0; i<n; i++){
        if(head>input[i]) c++;
    }

    // range = 0-199
    
	seek = fabs(0-head)+fabs(199-0)+fabs(199-input[c]);  // for lower
	int seek1 = fabs(199-head)+fabs(199-0)+ fabs(0-input[c-1]);  // for greater
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
	
	cscan(input,n,head);
	
}
