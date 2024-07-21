#include <bits/stdc++.h>
using namespace std;
void BFS(int source, int n, const vector<vector<int>>& adj) {
    vector<int> distance(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    queue<int> q;

    distance[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (distance[v] == INT_MAX) {
                distance[v] = distance[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i != source) {
            cout << "v" << i << ": distance: " << distance[i] << " Path: ";
            if (distance[i] == INT_MAX) {
                cout << "No path";
            } else {
                stack<int> path;
                for (int v = i; v != -1; v = parent[v]) {
                    path.push(v);
                }
                while (!path.empty()) {
                    cout << "v" << path.top();
                    path.pop();
                    if (!path.empty()) cout << "-";
                }
            }
            cout << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n + 1);


    cout << "Enter edges (enter 0 0 to stop):" << endl;
    while (true) {
        int u, v;
        cin >> u >> v;
        if (u == 0 && v == 0) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    BFS(source, n, adj);

    return 0;
}