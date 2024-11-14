#include<stdio.h>
struct data{
int pno,at,bt,tat,wt;
}a[10],temp;
void main()
{
int n,i,j,ct=0;
double atat,awt,ttat=0.0,twt;
printf("Enter the no of processes : ");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("\nEnter the process no,arrival time and burst time : ");
scanf("%d %d %d",&a[i].pno,&a[i].at,&a[i].bt);
}
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(a[i].at>a[j].at){
temp=a[i];
a[i]=a[j];
a[j]=temp;
}}}
for(i=0;i<n;i++){
ct+=a[i].bt;
a[i].tat=ct-a[i].at;
ttat+=a[i].tat;
a[i].wt=a[i].tat-a[i].bt;
twt=twt+a[i].wt;
}
atat=ttat/n;
awt=twt/n;
printf("Process No\tArrival Time\tBurst Time\tTAT\tWT\n");
for(i=0;i<n;i++){
printf("%d\t\t%d\t\t%d\t\t%d\t%d\n",a[i].pno,a[i].at,a[i].bt,a[i].tat,a[i].wt);
}
printf("\nAvg.turn around time = %f\n",atat);
printf("Avg.waiting time = %f\n",awt);
printf("GANTT CHART\n");
printf("0");
for(i=0;i<n;i++){
printf("\tP%d\t%d",a[i].pno,a[i].tat+a[i].at);
}
printf("\n");
}
