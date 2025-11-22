#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj; // adjacency list (node, weight)
public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v, int w=1, bool undirected=true) {
        adj[u].emplace_back(v, w);
        if (undirected)
            adj[v].emplace_back(u, w);
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (auto &edge : adj[u]) {
                int v = edge.first;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int u, vector<bool> &visited) {
        visited[u] = true;
        cout << u << " ";
        for (auto &edge : adj[u]) {
            int v = edge.first;
            if (!visited[v])
                DFSUtil(v, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
        cout << endl;
    }

    struct Edge {
        int u, v, w;
        bool operator<(const Edge &other) const {
            return w < other.w;
        }
    };

    int find(vector<int>& parent, int x) {
        return parent[x] == x ? x : parent[x] = find(parent, parent[x]);
    }

    void KruskalMST() {
        vector<Edge> edges;
        for (int u = 0; u < V; ++u)
            for (auto &e : adj[u])
                if (u < e.first)
                    edges.push_back({u, e.first, e.second});
        sort(edges.begin(), edges.end());
        vector<int> parent(V);
        for (int i = 0; i < V; i++)
            parent[i] = i;
        int cost = 0;
        for (auto &edge : edges) {
            int x = find(parent, edge.u), y = find(parent, edge.v);
            if (x != y) {
                cout << edge.u << " - " << edge.v << " (" << edge.w << ")" << endl;
                cost += edge.w;
                parent[x] = y;
            }
        }
        cout << "Total Cost: " << cost << endl;
    }

    void PrimMST() {
        vector<int> key(V, INT_MAX), parent(V, -1);
        vector<bool> inMST(V, false);
        key[0] = 0;
        for (int count = 0; count < V; count++) {
            int u = -1;
            for (int v = 0; v < V; v++)
                if (!inMST[v] && (u == -1 || key[v] < key[u]))
                    u = v;
            inMST[u] = true;
            for (auto &e : adj[u]) {
                int v = e.first, w = e.second;
                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }
        int cost = 0;
        for (int v = 1; v < V; v++) {
            cout << parent[v] << " - " << v << " (" << key[v] << ")" << endl;
            cost += key[v];
        }
        cout << "Total Cost: " << cost << endl;
    }

    void Dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            int u = -1;
            for (int j = 0; j < V; j++)
                if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;
            visited[u] = true;
            for (auto &e : adj[u]) {
                int v = e.first, w = e.second;
                if (dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
        for (int i = 0; i < V; i++)
            cout << "Dist from " << src << " to " << i << ": " << dist[i] << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    cout << "BFS from 0: ";
    g.BFS(0);

    cout << "DFS from 0: ";
    g.DFS(0);

    cout << "Kruskal MST:\n";
    g.KruskalMST();

    cout << "Prim MST:\n";
    g.PrimMST();

    cout << "Dijkstra from 0:\n";
    g.Dijkstra(0);

    return 0;
}
