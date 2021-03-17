#include "bits/stdc++.h"
#include "graph.h"

using namespace std;

const int N = int(1e6) + 1;
const int INF = int(1e10);
vector<GraphNode> g[N];
int dist[N];
int vis[N];

struct cmp {
    bool operator()(int a, int b) {
        return dist[a] > dist[b]; // 距离小的排在前面
    }
};

priority_queue<int, vector<int>, cmp> pq;

//https://www.luogu.com.cn/problem/P3366
int main() {
    int n, m, s = 1;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(GraphNode(v, w));
        g[v].push_back(GraphNode(u, w));
    }
    fill(dist, dist + N, INF);
    int cnt = 0;
    int mst = 0;
    dist[s] = 0;
    pq.push(s);
    while (!pq.empty() && cnt < n) {
        int u = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        mst += dist[u];
        cnt++;
        for (int i = 0; i < g[u].size(); ++i) {
            int &to = g[u][i].to, &weight = g[u][i].weight;
            if (vis[to]) continue;
            if (dist[to] >= weight) {
                dist[to] = weight;
                pq.push(to);
            }
        }
    }
    if (cnt == n)
        printf("%d", mst);
    else
        printf("orz");
    return 0;
}