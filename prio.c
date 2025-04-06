#include<stdio.h>
int main(){
int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,temp,pos,total=0;
float avgwt,avgtat;
printf("Enter the total number of process: ");
scanf("%d",&n);
printf("Enter burst time and priority \n");
for (i=0;i<n;i++)
{
    printf("P[%d] ",i+1);
    printf("Burst time:");
    scanf("%d",&bt[i]);
     printf("Priority:");
    scanf("%d",&pr[i]);
    p[i]=i+1;
    }
    for (i=0;i<n-1;i++){
		pos=i;
		for (j=i+1;j<n;j++){
			if (pr[j]<pr[pos])
				pos=j;
		}
		if(pos!=j){
			temp=pr[i];
			pr[i]=pr[pos];
			pr[pos]=temp;
			temp=bt[i];
			bt[i]=bt[pos];
			bt[pos]=temp;
			temp=p[i];
			p[i]=p[pos];
			p[pos]=temp;
		}
	}
	wt[0]=0;
	for(i=1;i<n;i++){
		wt[i]=0;
		for(j=0;j<i;j++)
			wt[i]+=bt[j];
			total+=wt[i];
	}
	avgwt=total/n;
	printf("Process\tPriority\tBT\tWT\tTAT\t\n");
	for(i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
		total+=tat[i];
		printf("%d\t%d\t\t%d\t%d\t%d\n",p[i],pr[i],bt[i],wt[i],tat[i]);
	}
	avgtat=total/n;
	printf("Average Waiting Time=%f\n",avgwt);
	printf("Average Turnaround Time=%f\t",avgtat);
	return 0;
}
	
