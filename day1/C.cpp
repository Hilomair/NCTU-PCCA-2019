#include <bits/stdc++.h>

using namespace std;

long long a[200200],sum = 0,m = 0,sec = 0;
vector<int> ans;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum += a[i];
        if(a[i] > m)   sec = m,m = a[i];
        else if(a[i] > sec) sec = a[i];
    }
    //cout<<m<<" "<<sec<<"\n";
    for(int i=1;i<=n;i++)
    {
        if(a[i] == m && sum - a[i] == sec*2) ans.push_back(i);
        else if(a[i] != m && sum - a[i] == m * 2) ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}

