#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int N; // 1<= N <= 20000
const int maxn = 20000;
vector<int> tree[maxn + 5]; // tree[i]表示节点i的相邻节点
int d[maxn + 5]; // d[i]表示以i为根的子树的节点个数

#define INF 10000000

int minNode;
int minBalance;

void dfs(int node, int parent) // node and its parent
{
    d[node] = 1; // the node itself
    int maxSubTree = 0; // subtree that has the most number of nodes
    for (int i = 0; i < tree[node].size(); i++) {
        int son = tree[node][i];
        if (son != parent) {
            dfs(son, node);
            d[node] += d[son];
            maxSubTree = max(maxSubTree, d[son]);
        }
    }
    maxSubTree = max(maxSubTree, N - d[node]); // "upside substree with (N - d[node]) nodes"

    if (maxSubTree < minBalance){
        minBalance = maxSubTree;
        minNode = node;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%d", &N);

        for (int i = 1; i <= N - 1; i++){
            tree[i].clear();
        }

        for (int i = 1; i <= N-1; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        minNode = 0;
        minBalance = INF;

        dfs(1, 0); // fist node as root

        printf("%d %d\n", minNode, minBalance);
    }

    return 0;
}
