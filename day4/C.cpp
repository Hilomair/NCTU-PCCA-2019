/**
* Copyright(c)
* All rights reserved.
* Author : helomair
* Date : 2019-01-23-07.15.11
*/
#include<bits/stdc++.h>

using namespace std;
const long long INF = 1LL<<60;
struct Dinic {  //O(VVE), with minimum cut
    static const int MAXN = 5003;
    struct Edge{
        int u, v;
        long long cap, rest;
    };

    int n, m, s, t, d[MAXN], cur[MAXN];
    vector<Edge> edges;
    vector<int> G[MAXN];

    void init(){
        edges.clear();
        for ( int i = 0 ; i < MAXN ; i++ ) G[i].clear();
    }

    // min cut start
    bool side[MAXN];
    void cut(int u) {
        side[u] = 1;
        for ( int i : G[u] ) {
            if ( !side[ edges[i].v ] && edges[i].rest ) cut(edges[i].v);
        }
    }
    // min cut end

    void add_edge(int u, int v, long long cap){
        edges.push_back( {u, v, cap, cap} );
        edges.push_back( {v, u, 0, 0LL} );
        m = edges.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }

    bool bfs(){
        memset(d, -1, sizeof(d));
        queue<int> que;
        que.push(s); d[s]=0;
        while (!que.empty()){
            int u = que.front(); que.pop();
            for (int ei : G[u]){
                Edge &e = edges[ei];
                if (d[e.v] < 0 && e.rest > 0){
                    d[e.v] = d[u] + 1;
                    que.push(e.v);
                }
            }
        }
        return d[t] >= 0;
    }

    long long dfs(int u, long long a){
        //cout<<" !!!! "<<u<<" "<<a<<"\n";
        if ( u == t || a == 0 ) return a;
        long long flow = 0, f;
        for ( int &i=cur[u]; i < (int)G[u].size() ; i++ ) {
            Edge &e = edges[ G[u][i] ];
            if ( d[u] + 1 != d[e.v] ) continue;
            //cout<<e.v<<"\n";
            f = dfs(e.v, min(a, e.rest) );
            //cout<<u<<" : "<<i<<" "<<f<<"\n";
            if ( f > 0 ) {
                e.rest -= f;
                edges[ G[u][i]^1 ].rest += f;
                flow += f;
                a -= f;
                if ( a == 0 )break;
            }
        }
        return flow;
    }

    long long maxflow(int s, int t){
        this->s = s, this->t = t;
        long long flow = 0, mf,cnt = 1;
        while ( bfs() ){
            memset(cur, 0, sizeof(cur));
            while ( (mf = dfs(s, INF)) ) {
                    //cout<<cnt<<" : "<<mf<<"\n";
                    flow += mf;
                    //cnt++;
            }
        }
        for(int i=0;i<=t;i++)
            for(auto &j : G[i])
                if(!i)  flow += edges[j].rest;
                else if(edges[j].v == t)
                    flow += edges[j].rest;

        return flow;
    }
} dinic;

int input[53][53];
int ss,tt,T,n,m;

void make(int i,int j)
{
    //cout<<"i : "<<i<<" j : "<<j<<"\n";
    if(input[i+1][j] != -1) {
        //cout<<"i+1 j :"<<(i-1)*m+j<<" -> "<<(i+1-1)*m+j<<"\n";
        dinic.add_edge( (i-1)*m+j , (i+1-1)*m+j , INF);
    }
    if(input[i-1][j] != -1) {
        //cout<<"i-1 j :"<<(i-1)*m+j<<" -> "<<(i-1-1)*m+j<<"\n";
        dinic.add_edge( (i-1)*m+j , (i-1-1)*m+j , INF);
    }
    if(input[i][j+1] != -1) {
        //cout<<"i j+1 :"<<(i-1)*m+j<<" -> "<<(i-1)*m+j+1<<"\n";
        dinic.add_edge( (i-1)*m+j , (i-1)*m+j+1 , INF);
    }
    if(input[i][j-1] != -1) {
        //cout<<"i j+1 :"<<(i-1)*m+j<<" -> "<<(i-1)*m+j-1<<"\n";
        dinic.add_edge( (i-1)*m+j , (i-1)*m+j-1 , INF);
    }
}



int main()
{

    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        ss = 0;
        tt = n*m + 1;
        dinic.init();
       // dinic.add_edge(ss ,tt ,INF);
        memset(input,-1,sizeof(input));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>input[i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if((i%2 == 1 && j%2 == 1) || (i%2 == 0 && j%2 == 0))
                {
                    make(i,j);
                    //cout<<"SS : "<<ss<<" "<<(i-1)*m+j<<" "<<input[i][j]<<"\n";
                    dinic.add_edge(ss, (i-1)*m+j, input[i][j]);
                }
                else
                {
                    //cout<<"TT : "<<tt<<" "<<(i-1)*m+j<<" "<<input[i][j]<<"\n";
                    dinic.add_edge((i-1)*m+j, tt, input[i][j]);
                }
       long long ans =  dinic.maxflow(ss,tt);

       cout<<ans<<"\n";
    }
    return 0;
}
