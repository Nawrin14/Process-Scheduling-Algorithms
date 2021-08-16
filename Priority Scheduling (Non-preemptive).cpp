#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,cnt,timer,p = INT_MAX,index,value;
    double avg_waiting_time, avg_turnaround_time, total_waiting_time=0, total_turnaround_time=0;

    cout<<"Enter the number of processes: ";
    cin>>n;

    vector<int> cpu_time, arrival_time, priority, waiting_time(n), turnaround_time(n), status(n);

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

    cout<<"\nEnter the priority values: ";
    for(int i=0; i<n; i++)
    {
        cin>>x;
        priority.push_back(x);
    }

    vector< pair<int, pair<int, int> > > vec;

    for(int i=0; i<n; i++)
    {
        vec.push_back(make_pair(arrival_time[i], make_pair(priority[i], i)));
    }

    sort(vec.begin(), vec.end());

    int min_index = vec[0].second.second;

    waiting_time[min_index] = 0;
    turnaround_time[min_index] = cpu_time[min_index];
    total_turnaround_time = turnaround_time[min_index];
    timer = vec[0].first;
    timer += cpu_time[min_index];
    status[0] = 1;
    cnt = n-1;

    while(cnt>0)
    {
        for(int i=0; i<n; i++)
        {
            if(vec[i].first<=timer && status[i]==0 && vec[i].second.first<p)
            {
                p = vec[i].second.first;
                value = i;
                index = vec[i].second.second;
            }
        }

        status[value] = 1;
        p = INT_MAX;
        cnt--;

        waiting_time[index] = timer - arrival_time[index];
        turnaround_time[index] = cpu_time[index]+waiting_time[index];
        total_waiting_time += waiting_time[index];
        total_turnaround_time += turnaround_time[index];
        timer += cpu_time[index];
    }

    avg_waiting_time = total_waiting_time/n;
    avg_turnaround_time = total_turnaround_time/n;

    cout<<"\n";
    for(int i=0; i<n; i++)
    {
        cout<<"Process "<<i+1<<":\tWaiting Time: "<<waiting_time[i]<<" \tTurnaround Time: "<<turnaround_time[i]<<"\n";
    }
    cout<<"\n";

    cout<<"Average Waiting Time: "<<fixed<<setprecision(2)<<avg_waiting_time<<"\n";
    cout<<"Average Turnaround Time: "<<fixed<<setprecision(2)<<avg_turnaround_time<<"\n";

}
