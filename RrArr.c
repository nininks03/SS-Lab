#include<stdio.h>
struct process {
int pno,bt,at,cbt,tat,wt;
};
void main()
{
int n,i,j,tq;
float ttat,twt,atwt,atat;
printf("Enter the number of process : ");
scanf("%d",&n);
struct process p[n],temp;
printf("Enter the Process no. Arrival time and Burst time of :-\n");
for(i=0;i<n;i++){
printf("Process %d : ",i);
scanf("%d %d %d",&p[i].pno,&p[i].at,&p[i].bt);
p[i].cbt=p[i].bt;
}
printf("Enter the time quantum : ");
scanf("%d",&tq);
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if(p[i].at>p[j].at){
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
/*printf("Sorted array is : \n");
for(i=0;i<n;i++) {
printf("%d %d %d\n",p[i].pno,p[i].at,p[i].bt);
}*/
printf("\nGANTT CHART\n0");
int time=0,y=0,t,k=0,queue[20],comp[n];
for(i=0;i<n;i++)
comp[i]=-1;
i=0,j=0;
while(1) {
if(p[i].at<=time) {
if(p[i].bt>0) {
if(p[i].bt>tq) {
//queue[j]=i;
queue[j]=p[i].pno;
printf("%d   P%d\n",j,p[i].pno);
j++;
time=time+tq;
p[i].bt-=tq;
printf("\t\t\t\t\time=%d\n",time);
//printf("  P%d  %d",p[i].pno,x);
//t+=tq;
for (t=j; t<time; t++)
{
if (p[(i+1)%n].at<=time ) {
//queue[j]=(i+1)%n;
queue[j]=p[(i+1)%n].pno;
printf("%d   P%d\n",j,p[(i+1)%n].pno);

if(p[(i+1)%n].bt>=tq){
time=time+tq;
p[(i+1)%n].bt-=tq;
printf("\t\t\t\t\ttime=%d\n",time);
j++;
}
else{
time=time+p[(i+1)%n].bt;
p[(i+1)%n].bt=0;
printf("\t\t\t\t\ttime=%d\n",time);
j++;
}


}
}
//queue[j]=i;
queue[j]=p[i].pno;
printf("%d   P%d\n",j,p[i].pno);

if(p[i].bt>=tq){
time=time+tq;
p[i].bt-=tq;
printf("\t\t\t\t\ttime=%d\n",time);
}
else{
time=time+p[i].bt;
p[i].bt=0;
}
printf("\t\t\t\t\ttime=%d\n",time);
j++;
}


else {
time=time+p[i].bt;
p[i].tat=time;
p[i].wt=p[i].tat-p[i].cbt;
p[i].bt=0;
y++;
comp[k]=i;
printf("  P%d  %d\n",p[k].pno,i);
k++;
//printf("  P%d  %d",p[i].pno,x);
//t+=tq;

/*if(y==n){
break;
}*/

}
}
if(i==n-1){
i=0;
}
else {
i++;
     }

    }
else {
time=p[i].at;
    printf("  IDEAL  %d",t);
}
}

printf("Sorted Process is : \n");
for(i=0;i<j;i++) {
printf("P%d ",queue[i]);
}

}
/*
printf("\n\nProcess no.\tArrival time\tBurst time\tTurnaround time\tWaiting time\n");
for(i=0;i<n;i++) {
printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pno,p[i].at,p[i].cbt,p[i].tat,p[i].wt);
}
ttat=p[n-1].tat;
twt=p[n-1].wt;
atat=ttat/n;
atwt=twt/n;
printf("Average Turnaround time = %f\n",atat);
printf("Average Waiting time = %f\n",atwt);
}
*/
