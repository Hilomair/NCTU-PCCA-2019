/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-22-13.41.10
*/
#include<bits/stdc++.h>

using namespace std;

struct V {
    int x,y;
};
vector<V> v;

bool cmp(V a,V b)
{
    if(a.x == b.x)  return a.y<b.y;
    return a.x<b.x;
}
int test[100002];
stack<int> s;
vector<int> ans;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,D = 1e9,Q = -1;
        V tmp1,tmp2;
        v.clear();
 //       memset(v,,sizeof(v));
        memset(test,0,sizeof(test));
        ans.clear();

        cin>>N;
        for(int i=0;i<N;i++)
        {
            int x,y;
            char tmp;
            cin>>x>>y>>tmp;
            if(tmp == 'Y')
            {
               // cout<<i<<" "<<tmp<<"\n";
                v.push_back({x,y});
                D = min(x , D);
                Q = max(x , Q);
            }
        }
        sort(v.begin(),v.end(),cmp);

        tmp1.x = v[1].x - v[0].x;
        tmp1.y = v[1].y - v[0].y;
        s.push(0);
        s.push(1);
        test[0] = 1;
        test[1] = 1;
        for(int i=2;i<v.size();i++)
        {
            long long now = s.top(),cross;
            tmp2.x = v[i].x - v[now].x;
            tmp2.y = v[i].y - v[now].y;
            cross = tmp1.x * tmp2.y - tmp1.y * tmp2.x;
            if(cross < 0)
            {
              //  cout<<"1 : "<<v[now].x<<" "<<v[now].y<<" : "<<v[i].x<<" "<<v[i].y<<"\n";
                s.pop();
                test[now] = 0;
                test[i] = 1;
                tmp1.x = v[i].x - v[s.top()].x;
                tmp1.y = v[i].y - v[s.top()].y;
                s.push(i);

            }
            else
            {
             //   cout<<"2 : "<<v[i].x<<" "<<v[i].y<<" "<<cross<<"\n";
                s.push(i),test[i] = 1;
                tmp1 = tmp2;
            }
        }
        for(int i=v.size()-1;i>=0;i--)
            if(!test[i])
                s.push(i);

        cout<<s.size()<<"\n";
        while(!s.empty()) ans.push_back(s.top()),s.pop();
        for(int i=ans.size()-1;i>=0;i--)
        {
            cout<<v[ans[i] ].x<<" "<<v[ans[i] ].y;
            if(i != 0)  cout<<"\n";
        }
        if(T)   cout<<"\n";
    }
    return 0;
}
/*
-1 -1
-1 1
0 0
1 -1
1 1

*/
