/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-21-13.02.30
* Description : 交大營 day2 easy A
*/
#include<bits/stdc++.h>

using namespace std;

vector<int> g[102];
int visit[102];
long long ans[102][2];
long long stamp;

void dfs(int n)
{
    ans[n][0] = stamp++;
    visit[n] = 1;
    for(auto &v : g[n])
        if(!visit[v])
            dfs(v);
    ans[n][1] = stamp++;
    return;
}

int main()
{
    int n,u,k;
    cin>>n;
    stamp = 1;
    for(int i=0;i<102;i++)  visit[i] = 0,g[i].clear();
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

    for(int i=1;i<=n;i++)   sort(g[i].begin(),g[i].end());
    for(int i=1;i<=n;i++)
    {
        if(ans[i][0] == 0 || ans[i][1] == 0)
            dfs(i);
    }

    for(int i=1;i<=n;i++)
        cout<<i<<" "<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    return 0;
}
