#include <bits/stdc++.h>

using namespace std;

long long a[200200],len[200200];
long long mt[11];
vector<int> t[11];

int main()
{
    int n,k;
    cin>>n>>k;
    long long tmp = 10 % k;
    for(int i=1;i<11;i++)
    {
        mt[i] = tmp;
        tmp = (10*tmp)%k;
    }
    for(int i=0;i<n;i++)
    {
        int f,cnt = 0;
        cin>>f;
        a[i] = f%k;
        while(f)
        {
            cnt++;
            f/=10;
        }
        len[i] = cnt;
        t[cnt].push_back(a[i]);
    }
    long long ans = 0;
    for(int i=1;i<11;i++)   sort(t[i].begin(),t[i].end());
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<11;j++)
        {
            tmp = k - (a[i]*mt[j])%k;
            if(tmp == k)  tmp = 0;
            ans += (upper_bound(t[j].begin(),t[j].end(),tmp) - lower_bound(t[j].begin(),t[j].end(),tmp));
            if(len[i] == j && a[i] == tmp) ans--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}

