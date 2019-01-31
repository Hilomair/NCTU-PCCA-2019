#include <bits/stdc++.h>

using namespace std;

long long a[200200],k,arr = 0;

int main()
{
    int n,q;
    cin>>n>>q;
    cin>>a[0];
    for(int i=1;i<n;i++)    cin>>a[i],a[i] += a[i-1];
    while(q--)
    {
        cin>>k;
        arr += k;
        if(arr >= a[n-1])
        {
            cout<<n<<"\n";
            arr = 0;
            continue;
        }
        int tmp = upper_bound(a,a+n,arr) - a;
        cout<<n-tmp<<"\n";
    }
    return 0;
}

