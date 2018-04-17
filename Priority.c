//preemptive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int limit;
 
struct process
{
      char process_name;
      int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;
      int status;
}process_queue[10];
 
void Arrival_Time_Sorting()
{
      int i=0, j;
      struct process temp;
      while(i<limit-1)
      {
            j=i+1;
            while(j<limit)
            {
                  if(process_queue[i].arrival_time > process_queue[j].arrival_time)
                  {
                        // swaping
                        temp = process_queue[i];
                        process_queue[i] = process_queue[j];
                        process_queue[j] = temp;
                  }
                  j=j+1;
            }
            i=i+1;
      }
}
 
void main()
{
      char c;
      int i=0, time = 0, burst_time = 0, largest;
      float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;

      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit);

      i=0;
      c='A';
      while(i<limit)
      {
            process_queue[i].process_name = c;

            i=i+1;
            c=c+1;

            printf("\nEnter Details For Process[%C]:\n", process_queue[i-1].process_name);

            printf("Enter Arrival Time:\t");
            scanf("%d", &process_queue[i-1].arrival_time );

            printf("Enter Burst Time:\t");
            scanf("%d", &process_queue[i-1].burst_time);

            printf("Enter Priority:\t");
            scanf("%d", &process_queue[i-1].priority);

            process_queue[i-1].status = 0;
            burst_time = burst_time + process_queue[i-1].burst_time;

      }

      Arrival_Time_Sorting();

      process_queue[9].priority = -9999;
      time = process_queue[0].arrival_time;

      printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");

      while(time < burst_time)
      {
            largest = 9;
            i=0;
            while(i<limit)
            {
                  i=i+1;
                  if(process_queue[i-1].arrival_time <= time && process_queue[i-1].status != 1 && process_queue[i-1].priority > process_queue[largest].priority)
                        largest = i-1;
            }

            time += process_queue[largest].burst_time;
            int at = process_queue[largest].arrival_time;
            
            process_queue[largest].ct = time;
            process_queue[largest].waiting_time = time - at - process_queue[largest].burst_time;
            process_queue[largest].turnaround_time = time - at;
            process_queue[largest].status = 1;

            wait_time += process_queue[largest].waiting_time;
            turnaround_time += process_queue[largest].turnaround_time;
            
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", process_queue[largest].process_name, process_queue[largest].arrival_time, process_queue[largest].burst_time, process_queue[largest].priority, process_queue[largest].waiting_time);

      }

      average_waiting_time = wait_time;
      average_waiting_time = average_waiting_time/ limit;
      average_turnaround_time = turnaround_time;
      average_turnaround_time = average_turnaround_time / limit;

      printf("\n\nAverage waiting time:\t%f\n", average_waiting_time);
      printf("Average Turnaround Time:\t%f\n", average_turnaround_time);

}
