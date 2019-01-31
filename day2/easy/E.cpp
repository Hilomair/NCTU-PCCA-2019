/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-21-14.16.49
*/
#include<bits/stdc++.h>

using namespace std;

int adj[105][105];
int n,m,ans;

void dfs(int a,int b)
{
    if(adj[a][b] == -1) return;
    adj[a][b] = -1;
    dfs(a-1,b+1);
    dfs(a-1,b);
    dfs(a-1,b-1);
    dfs(a,b+1);
    dfs(a,b-1);
    dfs(a+1,b+1);
    dfs(a+1,b);
    dfs(a+1,b-1);
    return;
}

int main()
{
    while(cin>>m>>n)
    {
        if(!m)  break;
        memset(adj,-1,sizeof(adj));
        ans = 0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                char tmp;
                cin>>tmp;
                if(tmp == '@')  adj[i][j] = 0;
            }
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(adj[i][j] == 0)
                {
                    //cout<<i<<" "<<j<<"\n";
                    ans++;
                    dfs(i,j);
                }
        cout<<ans<<"\n";
    }
    return 0;
}
