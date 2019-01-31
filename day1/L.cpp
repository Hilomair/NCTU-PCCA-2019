/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-21-10.17.12
* Description : 交大營 day1 L
*/

#include<bits/stdc++.h>

using namespace std;

queue<int> team[10001],all;
int m[1000000];
int flag[10001] = {0};

int main(){
    int t,tmp,x,cnt = 0;
    while(cin>>t)
    {
        if(!t)  break;
        cnt++;

        for(int i=0;i<10001;i++)
        {
            flag[i] = 0;
            while(!team[i].empty())
                team[i].pop();
        }
        while(!all.empty()) all.pop();
        for(int i=0;i<1000000;i++)  m[i] = -1;

        cout<<"Scenario #"<<cnt<<"\n";
        for(int i=1;i<=t;i++)
        {
            cin>>tmp;
            for(int j=0;j<tmp;j++)
                cin>>x,m[x] = i;
        }
        string s;
        int team_no;
        while(cin>>s)
        {
            if(s == "STOP") break;
            if(s == "ENQUEUE")
            {
                cin>>x;
                team_no = m[x];
                if(!flag[team_no])
                    flag[team_no] = 1,all.push(team_no);
                team[team_no].push(x);
            }
            if(s == "DEQUEUE")
            {
                team_no = all.front();
                //cout<<"!! "<<team_no<<"\n";
                cout<<team[team_no].front()<<"\n";
                team[team_no].pop();
                if(team[team_no].empty())   flag[team_no] = 0,all.pop();
            }
        }
        cout<<"\n";
    }
    return 0;
}
