#include <bits/stdc++.h>
using namespace std;
class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};
struct Edge {
    int u, v, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int main() {
    int V, E;
    cout<<"Enter Input: ";
    cin >> V >> E;
    vector<Edge> edges(E);

    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(V);
    vector<Edge> mstEdges;
    int mstWeight = 0;

    for (const auto& edge : edges) {
        int rootU = uf.find(edge.u);
        int rootV = uf.find(edge.v);

        if (rootU != rootV) {
            uf.unionSet(rootU, rootV);
            mstEdges.push_back(edge);
            mstWeight += edge.weight;
        }
    }
    cout << "Edges in MST:" << endl;
    for (const auto& edge : mstEdges) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }
    cout << "Total weight of MST: " << mstWeight << endl;
    return 0;
}