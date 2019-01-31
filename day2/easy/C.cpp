/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-21-13.02.30
* Description : 交大營 day2 easy A
*/
#include<bits/stdc++.h>

using namespace std;

vector<int> g[101];
queue<int> q;
int ans[101];

int main()
{
    int n,u,k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>u>>k;
        for(int j=0;j<k;j++)
        {
            int tmp;
            cin>>tmp;
            g[u].push_back(tmp);
        }
    }
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=n;i++)   sort(g[i].begin(),g[i].end());
    q.push(1);
    ans[1] = 0;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        for(int i=0;i<g[t].size();i++)
            if(ans[ g[t][i] ] == -1)
            {
                ans[ g[t][i] ]=ans[t]+1;
                q.push(g[t][i]);
            }
    }
    for(int i=1;i<=n;i++)
        cout<<i<<" "<<ans[i]<<"\n";
    return 0;
}

