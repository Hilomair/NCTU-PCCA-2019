/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-21-15.15.46
*/
#include<bits/stdc++.h>

using namespace std;

struct Edge{
    int to,value;
    bool operator > (const Edge &b) const
    {
        return value > b.value;
    }
};

vector<Edge> g[200];
priority_queue<Edge,vector<Edge>,greater<Edge> > pq;
int v[200],n,m;

int main()
{

    while(cin>>n>>m && n && m)
    {
        for(int i=0;i<200;i++)  v[i] = 1e9,g[i].clear();
        while(!pq.empty())   pq.pop();
        int a,b,c;
        while(m--)
        {
            cin>>a>>b>>c;
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        v[1] = 0;
        pq.push({1,v[1]});
        while(!pq.empty())
        {
            auto r = pq.top();  pq.pop();
            int u = r.to;
            if(v[u] < r.value) continue;
            for(auto &i : g[r.to])
            {
                if(v[i.to] > v[u] + i.value)
                {
                    v[i.to] = v[u] + i.value;
                    pq.push({i.to,v[i.to]});
                }
            }
        }
        cout<<v[n]<<"\n";
    }
    return 0;
}
