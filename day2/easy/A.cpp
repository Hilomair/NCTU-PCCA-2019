/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-21-13.02.30
* Description : 交大營 day2 easy A
*/
#include<bits/stdc++.h>

using namespace std;

int adj[101][101];


int main()
{
    int n,k,u;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>u>>k;
        for(int j=0;j<k;j++)
        {
            int tmp;
            cin>>tmp;
            adj[u][tmp] = 1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<adj[i][j];
            if(j != n)    cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
