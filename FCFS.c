#include<stdio.h>
int main(){
    int n,i,j,time=0,temp;
    int at[10],bt[10],ct[10],tat[10],wt[10];
    float avgtat=0,avgwt=0;
    
    printf("Enter number of processes: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        printf("P%d AT BT: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
    }
    
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(at[i]>at[j]){
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }
    
    for(i=0;i<n;i++){
        if(time<at[i])
          time=at[i];
          
        time=time+bt[i];
        ct[i]=time;
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        
        avgtat+=tat[i];
        avgwt+=wt[i];
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT");
    for(i=0;i<n;i++){
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage TAT=%.2f ",avgtat/n);
    printf("\nAverage WT=%.2f",avgwt/n);
    
    return 0;
    
}
