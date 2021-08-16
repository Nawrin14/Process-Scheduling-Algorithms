#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,cnt,timer=0;
    cout<<"Enter the number of processes: ";
    cin>>n;

    vector<int> cpu_time, arrival_time, waiting_time(n), turnaround_time(n), status(n), temp;
    double avg_waiting_time, avg_turnaround_time,total_waiting_time=0,total_turnaround_time=0;

    cout<<"\nEnter the CPU times: ";
    for(int i=0; i<n; i++)
    {
        cin>>x;
        cpu_time.push_back(x);
    }

    cout<<"\nEnter the arrival times: ";
    for(int i=0; i<n; i++)
    {
        cin>>x;
        arrival_time.push_back(x);
    }

    int min_index = min_element(arrival_time.begin(), arrival_time.end())-arrival_time.begin();

    waiting_time[min_index] = 0;
    turnaround_time[min_index] = cpu_time[min_index];
    total_turnaround_time = turnaround_time[min_index];
    status[min_index] = 1;
    timer+=cpu_time[min_index];
    cnt=n-1;

    while(cnt>0)
    {
        for(int i=0; i<n; i++)
        {
            if(arrival_time[i]<=timer && status[i]==0)
            {
                temp.push_back(cpu_time[i]);
                status[i]=1;
                cnt--;
            }
        }

        sort(temp.rbegin(), temp.rend());

        while(!temp.empty())
        {
            y = temp.back();
            temp.pop_back();

            vector<int>::iterator itr =  find(cpu_time.begin(), cpu_time.end(), y);
            int m = distance(cpu_time.begin(), itr);

            waiting_time[m]=timer-arrival_time[m];
            turnaround_time[m]=waiting_time[m]+cpu_time[m];
            timer+=cpu_time[m];

            total_waiting_time+=waiting_time[m];
            total_turnaround_time+=turnaround_time[m];
        }
    }

    avg_waiting_time = total_waiting_time/n;
    avg_turnaround_time = total_turnaround_time/n;

    cout<<"\n";
    for(int i=0; i<n; i++)
    {
        cout<<"Process "<<i+1<<":\tWaiting Time: "<<waiting_time[i]<<
            "\tTurnaround Time: "<<turnaround_time[i]<<"\n";
    }
    cout<<"\n";

    cout<<"Average Waiting Time: "<<fixed<<setprecision(2)<<avg_waiting_time<<"\n";
    cout<<"Average Turnaround Time: "<<fixed<<setprecision(2)<<avg_turnaround_time<<"\n";

}
