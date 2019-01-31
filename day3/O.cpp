/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-22-13.02.31
*/
#include<bits/stdc++.h>

using namespace std;

//struct V {
//    int x[4],y[4];
//};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,minx = 1e9,miny = 1e9,maxx = -1,maxy = -1;
//        V v[1001];
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int x,y;
            for(int j=1;j<=4;j++)
            {
                cin>>x>>y;
                if(x < minx)    minx = x;
                if(y < miny)    miny = y;
                if(x > maxx)    maxx = x;
                if(y > maxy)    maxy = y;
            }
        }
        long long ans = (maxx - minx) * (maxy - miny);
        cout<<ans<<"\n";
    }
    return 0;
}
