/* Design a scheduler following non-preemptive scheduling approach to scheduke the process that arrives at different
 units and having burst time double the arrival time.scheduler selects the process with largest burst time from 
 the queue for execution. process is not being preempted until it finishes its service time .compute the average waiting 
 times and average turnaround time .what should be the average waiting time if processes are  excuted according to 
 shortest job first scheduling approach with the same attributes values*/ 
 
 #include<iostream>
using namespace std;
int main()
{
    int burst_time[20],arrival_time[20],process[20],waiting_time[20],tat[20],i,j,n,total=0,pos,temp;
    float wait_avg,TAT_avg;
  cout<<"Enter number of process: ";
    cin>>n;
  
   
    for(i=0;i<n;i++)
    {
       cout<<"Enter Arrival time of Process["<<i+1<<"]: ";
       cin>>arrival_time[i];
        process[i]=i+1;           //Process Number
        burst_time[i]=2*arrival_time[i];
		cout<<"Burst Time of Process["<<i+1<<"]: ";
       cout<<burst_time[i]<<"\n";
    }
  
//Sorting
       for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
  
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
  
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
  
    waiting_time[0]=0;            //First process has 0 waiting time
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
  
        total+=waiting_time[i];
    }
     //Calculating Average waiting time 
    wait_avg=(float)total/n;
      total=0;
  
   cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        tat[i]=burst_time[i]+waiting_time[i]; //Calculating Turnaround Time     
        total+=tat[i];
        cout<<"\n process"<<process[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<tat[i];
    }
  
 //Calculation of Average Turnaround Time
    TAT_avg=(float)total/n;    
   cout<<"\n\nAverage Waiting Time: "<<wait_avg;
    cout<<"\nAverage Turnaround Time: "<<TAT_avg;
    return 0;
}
