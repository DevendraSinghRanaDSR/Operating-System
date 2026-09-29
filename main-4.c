#include<stdio.h>
int main(){
    int n,i,j,tq,time=0,done;
    int at[10],bt[10],rem[10],ct[10],tat[20],wt[10];
    float avgtat=0,avgwt=0;
    
    printf("Enter no of processes: ");
    scanf("%d ",&n);
    for(i=0;i<n;i++){
        printf("\nP%d AT BT:",i+1);
        scanf("%d %d ",&at[i],&bt[i]);
    }
    printf("Enter time quantum: ");
    scanf("%d",&tq);
    
    while(1){
        done=1;
        for(i=0;i<n;i++){
            if(rem[i]>0 && at[i]<=time){
                done=0;
                if(rem[i]>tq){
                    time=time+tq;
                    rem[i]=rem[i]-tq;
                }else{
                    time=time+rem[i];
                    rem[i]=0;
                    ct[i]=time;
                    tat[i]=ct[i]-at[i];
                    wt[i]=tat[i]-bt[i];
                    avgtat+=tat[i];
                    avgwt+=wt[i];
                }
            }
        }
        if(done==1){
            break;
        }
        int found=0;
        for(j=0;j<n;j++){
            if(rem[j]>0 && at[j]<=time){
                found=1;
                break;
            }
        }
        if(found==0){
            time++;
        }
    }
    
    printf("\nP\tAT\tBT\tCT\tTAT\tWT");
    for(i=0;i<n;i++){
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage TAt=%.2f",avgtat/n);
    printf("\nAverage wt=%.2f",avgwt/n);
    
    return 0;
    
    
}