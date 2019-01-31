/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-23-05.19.14
*/
#include<bits/stdc++.h>

using namespace std;

string s1[] = { "S" , "M" , "L" , "XL" , "XXL" , "XXXL" };
string s2[] = { "S,M" , "M,L" , "L,XL" , "XL,XXL" , "XXL,XXXL" };
string input[100002];

int cnt[6] = {0};

int main()
{
    int N;
    for(int i=0;i<6;i++)   cin>>cnt[i];

    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>input[i];
        for(int j=0;j<6;j++)
            if(input[i] == s1[j])
            {
                cnt[j] --;
                if(cnt[j] < 0)  { cout<<"NO\n"; return 0; }
                break;
            }
    }

    for(int j=0;j<5;j++)
        for(int i=0;i<N;i++)
            if(input[i] == s2[j])
            {
               // cout<<input[i]<<" "<<s2[j]<<"\n";
                if(cnt[j] > 0)
                {
                    cnt[j] -- ;
                    input[i] = s1[j];
                }
                else if(cnt[j+1] > 0)
                {
                    cnt[j+1] --;
                    input[i] = s1[j+1];
                }
                else
                {
                   // cout<<i<<" "<<cnt[i]<<" "<<j<<" "<<s2[j]<<"\n";
                    cout<<"NO\n";
                    return 0;
                }
            }
    cout<<"YES\n";
    for(int i=0;i<N;i++)
        cout<<input[i]<<"\n";
    return 0;
}
