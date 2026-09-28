#include<stdio.h>
int main(){
    int n,i,j,time=0,min;
    int done[10]={0};
    int at[10],bt[10],ct[10],tat[10],wt[10];
    float avgtat=0,avgwt=0;
    
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nP%d AT BT:",i+1);
        scanf("%d %d",&at[i],&bt[i]);
    
    }
    
    for(i=0;i<n;i++){
        min=-1;
        for(j=0;j<n;j++){
            if(done[j]==0 && at[j]<=time){
                if(min==-1 || bt[j]<bt[min]){
                    min=j;
                }
            }
        }
            if(min==-1){
                time++;
                i--;
                continue;
            }
            time=time+bt[min];
            ct[min]=time;
            tat[min]=ct[min]-at[min];
            wt[min]=tat[min]-bt[min];
            
            done[min]=1;
            avgtat+=tat[min];
            avgwt+=wt[min];
        
        
    }
    printf("\nP\tAt\tBT\tCT\tTAT\tWt");
    for(i=0;i<n;i++){
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage TAT:%.2f",avgtat/n);
    printf("\nAverage WT:%.2f",avgwt/n);
    
    return 0;
    
    
}