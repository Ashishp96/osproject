#include<stdio.h>
#include<conio.h>
void main()
{
int n,seek=0,range,difference;
printf("enter the range of disk");
scanf("%d",&range);
float seektime;
printf("enter the size of queue request");
scanf("%d",&n);
int q[20],head;
int x,y,k;

printf("enter the queue");
x=1;
while(x<=n)
{
	scanf("%d",&q[x]);
	x = x+1;
}

printf("enter the initial head position");
scanf("%d",&head);

y=0;
q[0]=head;

while(y<=n-1)
{
	difference=abs(q[y+1]-q[y]);
	seek = seek + difference;
	printf("move is from %d to %d with seek %d\n",q[y],q[y+1],difference);
	y=y+1;
}

printf("total seek time is%d\n",seek);

seektime=seek;
seektime = seektime/(float)n;

printf("avrage seek time is %f\n",seektime);
}
