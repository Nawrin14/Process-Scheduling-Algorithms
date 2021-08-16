#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,x,y,timer=0,a,b;
    string z;
    double total_waiting_time=0, total_ta_time=0, avg_waiting_time, avg_ta_time;

    cout<<"Enter the number of process: ";
    cin>>n;

    vector<int> cpu_time, arrival_time, waiting_time(n), ta_time(n), status(n), temp;
    vector<string> str;

    cout<<"Process name  Arrival time  CPU time\n";

    for(int i=0;i<n;i++){
        cin>>z;
        str.push_back(z);
        cin>>x;
        arrival_time.push_back(x);
        cin>>y;
        cpu_time.push_back(y);
    }

    a = min_element(arrival_time.begin(), arrival_time.end())-arrival_time.begin();

    waiting_time[a]=0;
    ta_time[a]=cpu_time[a];
    total_ta_time=ta_time[a];
    timer+=cpu_time[a];
    status[a]=1;

    for(int i=0;i<n;i++){
        if(status[i]==0){
            temp.push_back(arrival_time[i]);
            status[i]=1;
        }
    }

    sort(temp.rbegin(),temp.rend());

    while(!temp.empty()){
        y = temp.back();
        temp.pop_back();

        vector<int>::iterator itr = find(arrival_time.begin(), arrival_time.end(), y);
        int m= distance(arrival_time.begin(),itr);

        waiting_time[m]=timer-arrival_time[m];
        ta_time[m]=waiting_time[m]+cpu_time[m];
        timer+=cpu_time[m];

    total_ta_time+=ta_time[m];
    total_waiting_time+= waiting_time[m];

    }

    avg_waiting_time=total_waiting_time/n;
    avg_ta_time=total_ta_time/n;

    for(int i=0;i<n;i++){
        cout<<"Process "<<i+1<<" "<<str[i]<<": Waiting time: "<<waiting_time[i]<<
        " Turnaround time: "<<ta_time[i]<<"\n";
    }

    cout<<"\nAverage waiting time: "<<avg_waiting_time;
    cout<<"\nAverage turnaround time: "<<avg_ta_time;
}
