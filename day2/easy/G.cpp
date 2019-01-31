/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-21-15.07.01
*/
#include<bits/stdc++.h>

using namespace std;

vector<int> g[105];
queue<int> q;
int degree[105];

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(!n&&!m)  break;
        int a,b;
        while(!q.empty())   q.pop();
        for(int i=0;i<105;i++)  degree[i] = 0,g[i].clear();
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            g[a].push_back(b);
            degree[b]++;
        }
        for(int i=1;i<=n;i++)
            if(!degree[i])  q.push(i);
        while(!q.empty())
        {
            int r = q.front();
            q.pop();
            for(auto &i : g[r])
            {
                degree[i]--;
                if(!degree[i])  q.push(i);
            }
            cout<<r;
            if(q.size())
                cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
