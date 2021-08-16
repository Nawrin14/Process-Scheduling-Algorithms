#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,cnt,min_index,minimum,t;
    double total_waiting_time=0, total_ta_time=0, avg_waiting_time, avg_ta_time;
    cout<<"Enter the number of process: ";
    cin>>n;

    vector<int> cpu_time, arrival_time, waiting_time(n), ta_time(n), temp, re_time(n), start_time(n),
           end_time(n);

    cout<<"Enter CPU times: ";
    for(int i=0; i<n; i++)
    {
        cin>>x;
        cpu_time.push_back(x);
    }

    cout<<"Enter arrival times: ";
    for(int i=0; i<n; i++)
    {
        cin>>y;
        arrival_time.push_back(y);
        temp.push_back(y);
    }

    vector< pair<int, pair<int, int> > > vec;

    for(int i=0; i<n; i++)
    {
        vec.push_back(make_pair(arrival_time[i], make_pair(cpu_time[i], i+1)));
    }

    sort(vec.begin(), vec.end());

    for(int i=0; i<n; i++)
    {
        re_time[i]=vec[i].second.first;
        end_time[i]=vec[i].first;
    }

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    cnt=0;
    min_index = 0;
    minimum = INT_MAX;
    start_time[0] = vec[0].first;

    for(int k=0; k<temp.size(); k++)
    {
        end_time[min_index] = temp[k];
        t = end_time[min_index] - start_time[min_index];
        re_time[min_index]-=t;
        minimum = re_time[min_index];

        if(re_time[min_index]==0)
        {
            cnt++;
            minimum = INT_MAX;
            ta_time[min_index]=waiting_time[min_index]+vec[min_index].second.first;
            total_ta_time+=ta_time[min_index];
            total_waiting_time+=waiting_time[min_index];

            if(cnt==n)
                break;
        }

        for(int j=0; j<n; j++)
        {
            if(arrival_time[j]<=temp[k] && re_time[j]<minimum && re_time[j]!=0)
            {
                min_index = j;
                minimum = re_time[j];
            }
        }

        start_time[min_index] = temp[k];

        waiting_time[min_index]+= start_time[min_index] - end_time[min_index];

        if(k==temp.size()-1)
        {
            int z = start_time[min_index] + re_time[min_index];
            temp.push_back(z);
        }

    }

    for(int i=0; i<n; i++)
    {
        cout<<"\nProcess "<<vec[i].second.second<<":\tWaiting time: "<<waiting_time[i]
            <<"\tTurnaround time: "<<ta_time[i];
    }

    avg_waiting_time=total_waiting_time/n;
    avg_ta_time=total_ta_time/n;

    cout<<"\n\n";
    cout<<"Average Waiting Time: "<<fixed<<setprecision(2)<<avg_waiting_time<<"\n";
    cout<<"Average Turnaround Time: "<<fixed<<setprecision(2)<<avg_ta_time<<"\n";
}



