#include<stdio.h>
#define N 10
typedef struct
{
      int process_id, arrival_time, burst_time, priority;
      int q, ready;
}s;
typedef struct
{
      int p_id,ra_t,rb_t,rp;
}r;
typedef struct
{
      int fp_id,fa_t,fb_t,fp;
}f;
typedef struct
{
      int pp_id,pa_t,pb_t,pp;
}p;
int Queue(int q) {
      if(q == 0 || q == 1 || q == 2 || q == 3)
      {
            return 1;
      }
      else
      {
            return 2;
      }
}
int main()
{
      int n,m=0,rr=0,pp=0,i, temp_process, time, j, y;
      s temp;
      printf("Enter Total Number of Processes:\t");
      scanf("%d", &n);
      s process[n];
      for(i = 0; i < n; i++)
      {
            printf("\nProcess ID:\t");
            scanf("%d", &process[i].process_id);
            printf("Arrival Time:\t");
            scanf("%d", &process[i].arrival_time);
            printf("Burst Time:\t");
            scanf("%d", &process[i].burst_time);
            printf("Process Priority:\t");
            scanf("%d", &process[i].priority);
            //temp_process = process[i].priority;
            //process[i].q = Queue(temp_process);
            //process[i].ready = 0;
      } r proces[n];f pro[n];p pr[n];
      for(i=0;i<n;i++)
      {
            if(process[i].priority>0 && process[i].priority<10)
            {     rr=rr+1;
                  proces[i].p_id=process[i].process_id;
                  proces[i].ra_t=process[i].arrival_time;
                  proces[i].rb_t=process[i].burst_time;
                  proces[i].rp=process[i].priority;
                  round_robin();
            }
            else if(process[i].priority>10 && process[i].priority<20)
            {     m=m+1;
                  return m;
                  pro[i].fp_id=process[i].process_id;
                  pro[i].fa_t=process[i].arrival_time;
                  pro[i].fb_t=process[i].burst_time;
                  pro[i].fp=process[i].priority;
                  fcfs();
            }
            else
            {
                  pr[i].pp_id=process[i].process_id;
                  pr[i].pa_t=process[i].arrival_time;
                  pr[i].pb_t=process[i].burst_time;
                  pr[i].pp=process[i].priority;
                  prior();
            }
      }

      return 0;
 }
round_robin()
 {
      int total=0,count=0,i;
      int wait_time = 0, turnaround_time = 0, temp[10]; 
      float average_wait_time, average_turnaround_time;
      printf("round_robin :\t");
      printf("quantum time of 4 seconds:\t");
      int static time_quantum=4;
      int x=rr;
      for(i=0;i<10;i++)
      {
            temp[i]=proces[i].rb_t;
      }
       printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, proces[i].rb_t, total - proces[i].ra_t, total - proces[i].rb_t);
                  wait_time = wait_time + total -proces[i].ra_t - proces[i].rb_t; 
                  turnaround_time = turnaround_time + total - proces[i].ra_t; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(proces[i+1].ra_t <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
      return 0; 
 }
fcfs()
{
      int i, m;
      float waiting_time[30], turnaround_time[30];
      float average_waiting_time = 0.0, average_turnaround_time = 0.0;
      int j;
      printf("first come first serve :\t");
      printf("quantum time of 10 seconds:\t");
      int static quantm=10;
      waiting_time[0] = 0;
        for(j = 1; j < m; j++)
        {
                waiting_time[j] = 0;
                for(i = 0; i < j; i++)
                {
                        waiting_time[j]=waiting_time[j]+pro[j].fb_t;
                }
        }
      printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
        for(j = 0; j < m; j++)
        {
                turnaround_time[j] = pro[j].fb_t + waiting_time[j];
                average_waiting_time = average_waiting_time + waiting_time[j];
                average_turnaround_time = average_turnaround_time + turnaround_time[j];
                printf("\nProcess [%d]\t\t%.2f\t\t%.2f\t\t%.2f", j + 1, pro[j].fb_t, waiting_time[j], turnaround_time[j]);
        }
        printf("\n");
        average_waiting_time = average_waiting_time/j;
        average_turnaround_time = average_turnaround_time / j;
        printf("\nAverage Waiting Time = %f", average_waiting_time);
        printf("\nAverage Turnaround Time = %f", average_turnaround_time);
        printf("\n");
        return 0;
}
prior()
{
      printf("priority scheduling :\t");
      printf("quantum time of 10 seconds:\t");
      int static quant=10;
      return 0;
}}





