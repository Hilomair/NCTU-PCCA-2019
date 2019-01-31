#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    stack<int> s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int tmp ;
        cin>>tmp;
        tmp %= 2;
        if(s.empty() || s.top() != tmp)   s.push(tmp);
        else    s.pop();
    }
    if(s.size() <= 1)    cout<<"YES\n";
    else    cout<<"NO\n";
    return 0;
}



