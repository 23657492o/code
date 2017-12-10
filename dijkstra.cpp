#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int maxn = 1e5 +5;
const LL INF = 1e15;

int n,m;
struct Node{
    LL d;
    int pos;
    operator < (const Node &rhs)const{
        return d > rhs.d;
    }

};

vector<int> e[maxn];
vector<int> w[maxn];

LL dist[maxn];
int p[maxn];
bool vis[maxn];


void dijkstra(){
    priority_queue<Node> pq;
    for(int i = 1;i<=n;i++)dist[i] = INF;
    dist[1] = 0;
    memset(vis,false,sizeof(vis));
    Node tar; tar.pos = 1;tar.d = 0;
    pq.push(tar);
    while(!pq.empty()){
        Node tmp = pq.top();
        int t = tmp.pos;
        pq.pop();
        if(vis[t])continue;
            vis[t] = true;
        for(int i = 0;i<(int)e[t].size();i++){
            int v = e[t][i];
            if(dist[v] > dist[t] + w[t][i]){
                dist[v] = dist[t] + w[t][i];
                p[v] = t;
                tar.pos = v; tar.d = dist[v];
                pq.push(tar);
            }
        }

    }

}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for( int i=1; i<=n; i++ ) e[i].clear(), w[i].clear();
            //memset(vis,false,sizeof(vis));
            memset(dist,0,sizeof(dist));
            int a,b,c;
            Node t;
        for(int i = 0;i < m;i++){
            scanf("%d%d%d",&a,&b,&c);
            e[a].push_back(b);w[a].push_back(c);
            e[b].push_back(a);w[b].push_back(c);
        }
        dijkstra();
     //   cout<<"cp"<<endl;
        //vector<int> s;
        if(dist[n] == INF) printf("-1\n");
        else{
             e[1].clear();
        e[1].push_back(n);
        while(p[n]!=1){
            n  = p[n];
            e[1].push_back(n);
        }
            e[1].push_back(1);
        for(int i = e[1].size()-1;i>=0;i--)printf("%d%c",e[1][i],i==0? '\n':' ');
        }

    }

return 0;
