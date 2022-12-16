#include<stdio.h>
#include<math.h>
void look(int input[], int n,int head){
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

    
	
	// int range = 199; // no requirement of range
	// int range = 0; // for smaller
	seek = fabs(input[n-1]-head)+fabs(input[n-1]-input[0])+fabs(input[c-1]-input[0]);  // for greater
	int seek1 = fabs(input[0]-head)+fabs(input[0]-input[n-1])+ fabs(input[n-1]-input[c]);  // for lower
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
	
	look(input,n,head);
	
}
