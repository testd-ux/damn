#include<stdio.h>
int main(){
	int count,n,time,remain,flag=0,t_q;
	int at[10],bt[10],rt[10];
	int wt=0,tat=0;
	printf("Enter total process : ");
	scanf("%d",&n);
	remain=n;
	for(count=0;count<n;count++){
		printf("Enter arrival time and burst time for process number P[%d]\n",count+1);
		printf("Arrival Time:");
		scanf("%d",&at[count]);
		printf("Burst Time:");
		scanf("%d",&bt[count]);
		rt[count]=bt[count];
	}
	printf("Enter time Quantum : ");
	scanf("%d",&t_q);
	printf("Process\t\tTAT\t\tWT\n");
	for(time=0,count=0;remain!=0;){
		if(rt[count]<=t_q && rt[count]>0){
			time+=rt[count];
			rt[count]=0;
			flag=1;
		}
		else if(rt[count]>0)
		{
			rt[count]-=t_q;
			time+=t_q;
		}
		if(rt[count]==0 && flag==1)
		{
			remain--;
printf("P[%d]\t\t%d\t\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
 wt+=time-at[count]-bt[count];
 tat+=time-at[count];
 flag=0;
 }
 if(count==n-1)
 count=0;
 else if(at[count+1]<=time){
 count++;
 }else {
 count=0;
 }}
      
 	printf("Average Waiting Time=%f\n",(float)wt/n);
	printf("Average Turnaround Time=%f\t",(float)tat/n);
	return 0;
}
	
