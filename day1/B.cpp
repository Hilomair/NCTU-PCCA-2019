#include <bits/stdc++.h>

using namespace std;

priority_queue<long long ,vector<long long>,greater<long long> >pq;

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        pq.push(tmp);
    }
    long long  now = pq.top(),ans = pq.top();
    while(k--)
    {
        if(pq.empty())
        {
            cout<<"0\n";
            continue;
        }
        cout<<ans<<"\n";
        while(!pq.empty() && pq.top() == now)
           // cout<<pq.top()<<" "<<now<<"\n";
                pq.pop();
        ans = pq.top() - now;
        now = pq.top();
        //cout<<k<<" "<<ans<<" "<<now<<"\n";
    }
    return 0;
}
