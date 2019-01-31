#include <bits/stdc++.h>

using namespace std;

struct P{
    int a,b;
};
int cnt[100001]={0};

bool cmp(P t1,P t2)
{
    if(t1.a==t2.a)  return t1.b<t2.b;
    return t1.a<t2.a;
}

long long ans = 0;
int main()
{
    int n,k;
    P p[100001];
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].a;
        cnt[p[i].a] ++;
    }
 //   cout<<"1\n";
    for(int i=1;i<=n;i++)
        cin>>p[i].b;
    sort(p+1,p+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(cnt[p[i].a] <= 1)    continue;
        int tmp = cnt[p[i].a ];
        cout<<i<<" "<<tmp<<"\n";
        while(tmp--)
        {
            ans += p[i].b;
            i++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}

