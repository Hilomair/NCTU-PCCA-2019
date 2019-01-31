#include <bits/stdc++.h>

using namespace std;

int a[31],t[120001],ans = 0,mi = -1;
map<int,int> mp;
int main()
{
    for(int i=0;i<=30;i++)  a[i] = 1 << i;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
        mp[t[i]]++;
        mi = max(t[i],mi);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<=30;j++)
        {
            long long tmp = a[j] - t[i];
            if(tmp > mi || tmp < 0)    continue;
            if(tmp == t[i] && mp[tmp] >= 2) { ans++; break; }
            else if(tmp != t[i] && mp[tmp]) { ans++; break;}
        }
    cout<<n-ans<<"\n";
    return 0;
}



