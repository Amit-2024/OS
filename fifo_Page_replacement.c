#include<stdio.h>
#include<string.h>


void printframe(int frame[], int f){
    for(int i=0; i<f; i++){
        printf("%d ",frame[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    int f;
    printf("Enter the size of frame : ");
    scanf("%d",&f);
    
    printf("Enter the page sequence: ");
    int page_seq[n];
    for(int i=0; i<n; i++) scanf("%d",&page_seq[i]);

    int page_fault =0;
    int page_hit=0;
    
    int frame[f];
    memset(frame,-1,f*sizeof(int));
    int index =-1;
    
    for(int i=0; i<n; i++){
        int flag = 0;
        for(int j=0; j<f; j++){
            if(page_seq[i]==frame[j]){
                printframe(frame,f);
                page_hit++;
                flag = 1;
            }
        }

        if(flag==0){
            index = (index+1)%f;
            frame[index] = page_seq[i];
            page_fault++;
            printframe(frame,f);
        }
    }

    printf("Total page hit: %d",page_hit);
    printf("\nTotal fault : %d",page_fault);
    printf("\nFault ratio : %f",(float)page_fault/n);

}