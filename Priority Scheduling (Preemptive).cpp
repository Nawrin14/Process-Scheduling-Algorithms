#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,z,cnt,min_index,t,p;
    double total_waiting_time=0, total_ta_time=0, avg_waiting_time, avg_ta_time;
    cout<<"Enter the number of process: ";
    cin>>n;

    vector<int> cpu_time, arrival_time, priority, waiting_time(n), ta_time(n), temp, re_time, start_time(n), end_time;

    cout<<"\nEnter the CPU times: ";
    for(int i=0; i<n; i++)
    {
        cin>>x;
        cpu_time.push_back(x);
        re_time.push_back(x);
    }

    cout<<"\nEnter the arrival times: ";
    for(int i=0; i<n; i++)
    {
        cin>>y;
        arrival_time.push_back(y);
        end_time.push_back(y);
        temp.push_back(y);
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

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    cnt = 0;
    p = INT_MAX;
    min_index = vec[0].second.second;
    start_time[min_index] = vec[0].first;

    for(int k=0; k<temp.size(); k++)
    {
        end_time[min_index] = temp[k];
        t = end_time[min_index] - start_time[min_index];
        re_time[min_index] -= t;

        if(re_time[min_index]==0)
        {
            cnt++;
            p = INT_MAX;
            ta_time[min_index] = waiting_time[min_index]+cpu_time[min_index];
            total_ta_time += ta_time[min_index];
            total_waiting_time += waiting_time[min_index];

            if(cnt==n)
                break;
        }

        for(int j=0; j<n; j++)
        {
            if(arrival_time[j]<=temp[k] && priority[j]<p && re_time[j]!=0)
            {
                min_index = j;
                p = priority[j];
            }
        }

        start_time[min_index] = temp[k];

        waiting_time[min_index] += start_time[min_index]-end_time[min_index];

        if(k==temp.size()-1)
        {
            z = start_time[min_index]+re_time[min_index];
            temp.push_back(z);
        }

    }

    for(int i=0; i<n; i++)
    {
        cout<<"\nProcess "<<i+1<<":\tWaiting time: "<<waiting_time[i]<<" \tTurnaround time: "<<ta_time[i];
    }

    avg_waiting_time=total_waiting_time/n;
    avg_ta_time=total_ta_time/n;

    cout<<"\n\n";
    cout<<"Average Waiting Time: "<<fixed<<setprecision(2)<<avg_waiting_time<<"\n";
    cout<<"Average Turnaround Time: "<<fixed<<setprecision(2)<<avg_ta_time<<"\n\n";

}



