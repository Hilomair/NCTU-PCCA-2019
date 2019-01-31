/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-21-15.52.54
*/
#include<bits/stdc++.h>

using namespace std;

int n,k,T[6];
long long F[102][102],dis[102];



int main()
{
    while(cin>>n>>k)
    {
        for(int i=1;i<=n;i++)
            cin>>T[i];
        for(int i=0;i<102;i++)
        {
            dis[i] = 1e9;
            for(int j=0;j<102;j++)
                F[i][j] = 1e9;
        }

        cin.ignore();

        for(int i=1;i<=n;i++)
        {
            string s;
            int cnt = 0,tmp[102];

            getline(cin,s);
            stringstream ss(s);
            while(ss >> tmp[cnt]) cnt++;

            for(int a=0;a<cnt;a++)
                for(int b=a+1;b<cnt;b++)
                {
                    int f1 = tmp[a],f2 = tmp[b];
                    if( (f2-f1)*T[i] < F[f1][f2])
                        F[f1][f2] = F[f2][f1] = (f2-f1)*T[i];
                }
        }
        queue<int> q;
        int inq[102] = {0};
        dis[0] = 0;
        inq[0] = 1;
        q.push(0);
        while(!q.empty())
        {
            int now = q.front();q.pop();
            inq[now] = 0;

            for(int nxt=0;nxt < 100;nxt++)
                if(dis[now] + F[now][nxt] + 60 < dis[nxt])
                {
                    //cout<<dis[nxt]<<"-> ";
                    dis[nxt] = dis[now] + F[now][nxt] + 60;
                    //cout<<now<<" "<<nxt<<" "<<dis[nxt]<<"\n";
                    if(!inq[nxt])
                    {
                        q.push(nxt);
                        inq[nxt] = 1;
                    }
                }
        }
        if(!k)  cout<<"0\n";
        else if(dis[k] == 1e9)  cout<<"IMPOSSIBLE\n";
        else    cout<<dis[k]-60<<"\n";
    }
    return 0;
}
