#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF LLONG_MAX

struct Edge {
    int to;
    long long weight;
};

void dijkstra(int n, vector<vector<Edge>>& graph) {
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (Edge e : graph[u]) {
            int v = e.to;
            long long w = e.weight;
            long long new_dist = dist[u] + w;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF)
            cout << -1 << endl;
        else
            cout << dist[i] << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);

    cout << "Enter the edges (format: x y w):" << endl;
    for (int i = 0; i < m; i++) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w}); // Since the graph is bidirectional
    }

    dijkstra(n, graph);

    return 0;
}
