#include<stdio.h>
struct process {
int pno,bt,rbt,tat,wt,at;
};
void main()
{
int n,i,tq,j;
float ttat=0,twt=0;
printf("Enter the number of process : ");
scanf("%d",&n);
struct process p[n];

/*struct process p[n],temp;
p[0].pno=1; p[0].at=2; p[0].bt=2;
p[1].pno=2; p[1].at=5; p[1].bt=6;
p[2].pno=3; p[2].at=0; p[2].bt=4;
p[3].pno=4; p[3].at=4; p[3].bt=7;*/
printf("Enter the Process no., Arrival time and Burst time of :-\n");
for(i=0;i<n;i++) {
printf("Process : \n");
scanf("%d %d %d",&p[i].pno,&p[i].at,&p[i].bt);
p[i].rbt=p[i].bt;
p[i].tat=0;
p[i].wt=0;
//tbt+=p[i].bt;
}
printf("Enter the time quantum : ");
scanf("%d",&tq);
int time=0,flag=0;
while (1)
{  
    printf("KKKKKKKKKKKK");
    flag=1;
    for ( i = 0; i < n; i++)
    {
        //flag=0;
            printf("if loop");
        printf("i: %d\n",i);
        printf("rbt : %d\n",p[i].rbt);
        if(p[i].rbt>0 && p[i].at<=time) {
            flag=0;
            if(p[i].rbt>tq) {
                time+=tq;
                p[i].rbt-=tq;
                printf("%d\n",time);
            }
            else {
                    printf("else loop");
                time+=p[i].rbt;
                p[i].rbt=0;
                //p[i].tat=time-p[i].at;
                p[i].wt=time-p[i].bt-p[i].at;
                p[i].tat=p[i].wt+p[i].bt;
                printf("%d %d\n",p[i].wt,p[i].tat);
            }
        }
    }
    if(flag==1)
    break;
}
printf("\n\nProcess no.\tBurst time\tArrival time\tTurnaround time\tWaiting time\n");
for(i=0;i<n;i++) {
printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pno,p[i].bt,p[i].at,p[i].tat,p[i].wt);
ttat+=p[i].tat;
twt+=p[i].wt;
}
printf("Average Turnaround time = %f\n",ttat/n);
printf("Average Waiting time = %f\n",twt/n);
}
