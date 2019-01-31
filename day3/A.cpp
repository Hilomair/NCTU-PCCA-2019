/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-22-13.14.04
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    double t,h;
    float ans;
    cin>>n>>h;
    for(int i=1;i<n;i++)
    {
        t = h*h*i/n;
        t = sqrt(t);
        ans = t;
        cout<<fixed<<setprecision(10)<<ans;
        if(i != n-1)    cout<<" ";
    }
    return 0;
}
