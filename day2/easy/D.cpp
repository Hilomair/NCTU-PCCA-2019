/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-21-14.00.04
* Description : 交大營 day2 easy D
*/
#include<bits/stdc++.h>

using namespace std;

int fa[100002];

int dis_find(int x)
{
    return x==fa[x]?x:dis_find(fa[x]);
}
void dis_union(int a,int b)
{
    fa[b] = a;
}

int main()
{
    int n,m,q;
    cin>>n>>m;
    for(int i=0;i<100002;i++)   fa[i] = i;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        dis_union(dis_find(a),dis_find(b));
    }
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(dis_find(a) == dis_find(b))  cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
