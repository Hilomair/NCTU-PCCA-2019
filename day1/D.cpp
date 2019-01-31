#include <bits/stdc++.h>

using namespace std;

long long num[1000001],m[1000001][11];
int g(int x)
{
    while(x>=10)
        x = num[x];
    return x;
}

int main()
{
    for(int i=1;i<=1000000;i++)
    {
        num[i] = 1;
        int tmp = i;
        while(tmp)
        {
            int t = tmp % 10;
            tmp /= 10;
            if(t)   num[i] *= t;
        }
        for(int j=0;j<11;j++)
            m[i][j] = 0;
    }
    for(int i=1;i<=1000000;i++)
        for(int j=1;j<=9;j++)
            if(g(i) == j)
                m[i][j] = m[i-1][j] + 1;
            else
                m[i][j] = m[i-1][j];
    int Q;
    cin>>Q;
    while(Q--)
    {
        int l,r,k,ans;
        cin>>l>>r>>k;
        ans = m[r][k] - m[l][k];
        if(g(l) == k) ans++;
        cout<<ans<<"\n";
    }
    return 0;
}


