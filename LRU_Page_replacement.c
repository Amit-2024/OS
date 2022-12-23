#include<stdio.h>

int findLRU(int time[],int f){
    int min = time[0];
    int index=0;
    for(int i=1; i<f; i++){
        if(time[i]<min){
            min = time[i];
            index = i;
        }
    }

    return index;

}

int main()
{
    int n;
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    int f;
    printf("Enter the no. of frame : ");
    scanf("%d",&f);
    
    printf("Enter the page sequence: ");
    int page_seq[n];
    for(int i=0; i<n; i++) scanf("%d",&page_seq[i]);

    int page_fault =0;
    int page_hit=0;

    int frame[f];
    int cnt=0;

    for(int i=0; i<f; i++){
        frame[i]=-1;
    }

    int time[f];
    for(int i=0; i<n; i++){
        int flag1,flag2;
        flag1=flag2=0;

        // when there is page hit
        for(int j=0;j<f; j++){
            if(page_seq[i]== frame[j]){
                page_hit++;
                cnt++;
                time[j]=cnt;
                flag1=flag2=1;
                break;
            }
        }

        // when there is space in the frame for page
        if(flag1==0){
            for(int j=0; j<f; j++){
                if(frame[j]==-1){
                    cnt++;
                    page_fault++;
                    frame[j]=page_seq[i];
                    time[j]=cnt;
                    flag2 = 1; 
                    break;
                }
            }
        }

        if(flag2 == 0){
            int index = findLRU(time,f);
            frame[index] = page_seq[i];
            cnt++;
            page_fault++;
            time[index] = cnt;
        }
        
        for(int j=0; j<f; j++){
            printf("%d\t",frame[j]);
        } printf("\n");
    }

    printf("TOTAL PAGE FAULT : %d", page_fault);
    printf("\nTotal page hit : %d",page_hit);
    printf("\nPage fault ratio : %f",(float)page_fault/n);    
}