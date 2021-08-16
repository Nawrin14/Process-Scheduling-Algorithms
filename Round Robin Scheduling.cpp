#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,q,timer1,timer2;
    double total_waiting_time=0, total_ta_time=0, avg_waiting_time, avg_ta_time;
    cout<<"Enter the number of process: ";
    cin>>n;

    vector<int> que, cpu_time, arrival_time, waiting_time(n), ta_time(n), re_time1, re_time2, start_time(n),
           end_time, status(n);

    cout<<"\nEnter the CPU times: ";
    for(int i=0; i<n; i++)
    {
        cin>>x;
        cpu_time.push_back(x);
        re_time1.push_back(x);
        re_time2.push_back(x);
    }

    cout<<"\nEnter the arrival times: ";
    for(int i=0; i<n; i++)
    {
        cin>>y;
        arrival_time.push_back(y);
        end_time.push_back(y);
    }

    cout<<"\nEnter the time quantum: ";
    cin>>q;

    vector< pair<int, pair<int, int> > > vec;

    for(int i=0; i<n; i++)
    {
        vec.push_back(make_pair(arrival_time[i], make_pair(i, cpu_time[i])));
    }

    sort(vec.begin(), vec.end());

    que.push_back(vec[0].second.first);
    status[0] = 1;
    timer1 = vec[0].first;
    timer2 = vec[0].first;

    for(int j=0; j<que.size(); j++)
    {
        if(re_time1[que[j]]<=q)
        {
            timer1 += re_time1[que[j]];
            re_time1[que[j]] = 0;
        }
        else
        {
            timer1 += q;
            re_time1[que[j]] -= q;
        }

        for(int k=0; k<n; k++)
        {
            if(vec[k].first<=timer1 && status[k]==0)
            {
                que.push_back(vec[k].second.first);
                status[k] = 1;
            }
        }

        if(re_time1[que[j]] != 0)
            que.push_back(que[j]);
    }

    for(int i=0; i<que.size(); i++)
    {
        start_time[que[i]] = timer2;

        waiting_time[que[i]] += start_time[que[i]] - end_time[que[i]];

        if(re_time2[que[i]]<=q)
        {
            timer2 += re_time2[que[i]];
            re_time2[que[i]] = 0;
            ta_time[que[i]] = waiting_time[que[i]] + cpu_time[que[i]];

            total_ta_time += ta_time[que[i]];
            total_waiting_time +=  waiting_time[que[i]];
        }
        else
        {
            timer2 += q;
            re_time2[que[i]] -= q;
        }

        end_time[que[i]] = timer2;
    }

    avg_waiting_time = total_waiting_time/n;
    avg_ta_time = total_ta_time/n;

    for(int j=0; j<n; j++)
    {
        cout<<"\nProcess "<<j+1<<":\tWaiting Time: "<<waiting_time[j]<<
            " \tTurnaround Time: "<<ta_time[j];
    }

    cout<<"\n\nAverage Waiting Time: "<<fixed<<setprecision(2)<<avg_waiting_time;
    cout<<"\nAverage Turnaround Time: "<<fixed<<setprecision(2)<<avg_ta_time<<"\n";

}
