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

//https://www.luogu.com.cn/problem/P4779
int main() {
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(GraphNode(v, w));
//        g[v].push_back(GraphNode(u, w));
    }
    fill(dist, dist + N, INF);
    dist[s] = 0;
    pq.push(s);
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = 0; i < g[u].size(); ++i) {
            int &to = g[u][i].to, &weight = g[u][i].weight;
            if (vis[to]) continue;
            if (dist[u] + weight <= dist[to]) {
                dist[to] = dist[u] + weight;
                pq.push(to);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", dist[i]);
    }
    return 0;
}