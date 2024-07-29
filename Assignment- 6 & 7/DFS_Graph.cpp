#include <bits/stdc++.h>
using namespace std;

void DFS(const vector<vector<int>>& graph, int startNode) {
    stack<int> stack;
    unordered_set<int> visited;
    stack.push(startNode);
    visited.insert(startNode);

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();

        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                stack.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int n, e;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> graph(n);

    cout << "Enter the edges (u v) where u and v are nodes connected by an edge:" << endl;
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    cout << "DFS starting from node " << startNode << ": ";
    DFS(graph, startNode);

    return 0;
}