/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-21-14.53.17
*/
#include<bits/stdc++.h>

using namespace std;

vector<int> g[2002];
queue<int> q;
int value[2002];

int main()
{
    int n,ans = 0;
    cin>>n;
    for(int i=0;i<2002;i++) g[i].clear();
    while(!q.empty())   q.pop();
    memset(value,0,sizeof(value));
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        if(t != -1) g[t].push_back(i);
        else q.push(i);
    }
    while(!q.empty())
    {
        int r = q.front();
        q.pop();
        for(auto &i : g[r])
        {
            value[i] = value[r] + 1;
            q.push(i);
        }
        ans = max(ans, value[r]);
    }
    cout<<ans+1<<"\n";
    return 0;
}
