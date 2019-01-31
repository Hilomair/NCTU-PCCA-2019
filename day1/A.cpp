#include <bits/stdc++.h>

using namespace std;

int a[20],n;

void dfs(int now,int i)
{
    //cout<<now<<" "<<i<<"\n";
    if(now < 0) now += 360;
    if(now >= 306) now -= 360;
    if(i == n && now == 0)
    {
        cout<<"YES\n";
        exit(0);
    }
    if(i==n)    return;
    dfs(now + a[i],i+1);
    dfs(now - a[i],i+1);
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    dfs(a[0],1);
    dfs(a[0]*(-1),1);
    cout<<"NO\n";
    return 0;
}
