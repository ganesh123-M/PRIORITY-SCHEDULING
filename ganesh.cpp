#include<stdio.h>
int k,n;
struct process
{
int p_no;

int arrival_t,burst_t,ct,wait_t,taround_time,p;

int flag;
}
plist[100];
void Sorting()
{
struct process p;

int i, j;

for(i=0;i<k-1;i++)

{

for(j=i+1;k<n;j++)

{

if(plist[i].arrival_t > plist[j].arrival_t)

{

p = plist[i];

plist[i] = plist[j];

plist[j] = p;

}

}

}
}
int main()
{

int i,t=0,b_t=0,peak;

int a[10];

float wait_time = 0, taround_time = 0, avg_w_t=0, avg_taround_time=0;

printf("enter the no. of processes: ");

scanf("%d",&k);

for(i = 0; i < k; i++)

{

plist[i].p_no = i+1;

printf("\nEnter Details For P%d process:-\n", plist[i].p_no);
printf("Enter Arrival Time: ");
scanf("%d", &plist[i].arrival_t );
printf("Enter Burst Time: ");
scanf("%d", &plist[i].burst_t);
plist[i].flag = 0;
b_t = b_t + plist[i].burst_t;
}
Sorting();
for(int i=0;i<k;i++)
{
a[i]=plist[i].burst_t;
}
plist[9].burst_t = 9999;
for(t = plist[0].arrival_t; t <= b_t+1;)
{
peak = 9;
for(i=0;i<k;i++)
{
if(plist[i].arrival_t <= t && plist[i].burst_t < plist[peak].burst_t && plist[i].flag != 1)
{
peak = i;
}
if(plist[peak].burst_t==0 && plist[i].flag != 1)
{
plist[i].flag = 1;
plist[peak].ct=t;plist[peak].burst_t=9999;
printf("P%d completes in %d\n",plist[i].p_no,plist[peak].ct);
}
}
t++;
(plist[peak].burst_t)--;
}
for(i=0;i<k;i++)
{
plist[i].taround_time=(plist[i].ct)-(plist[i].arrival_t);
avg_taround_time=avg_taround_time+plist[i].taround_time;
plist[i].wait_t=((plist[i].taround_time)-a[i]);
avg_w_t=avg_w_t+plist[i].wait_t;
}
printf("PNO\tAT\tCT\tTA\tWTt\n");
for(i=0;i<k;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",plist[i].p_no,plist[i].arrival_t,plist[i].ct,plist[i].taround_time,plist[i].wait_t);
}
printf("Average Turn around Time: %f\t\n\n",avg_taround_time);
printf("Average Waiting Time :\t %f\t\n",avg_w_t);
} 

