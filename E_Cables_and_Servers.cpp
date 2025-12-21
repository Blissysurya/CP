#include <bits/stdc++.h>
using namespace std;

class dsu {
    vector<int> parent, rank;

public:
    dsu(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findpar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findpar(parent[node]); // Path compression
    }

    void unionrank(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    dsu d(n);
    vector<pair<int, int>> edges;
    vector<pair<int, int>> redundant;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (d.findpar(u) == d.findpar(v)) {
            redundant.push_back({u, v});
        } else {
            d.unionrank(u, v);
        }
        edges.push_back({u, v});
    }

    vector<int> components;
    for (int i = 1; i <= n; i++) {
        if (d.findpar(i) == i) {
            components.push_back(i);
        }
    }

    int ops = components.size() - 1;
    cout << ops << endl;

    for (int i = 0; i < ops; i++) {
        int u = redundant[i].first;
        int v = redundant[i].second;
        int new_v = components[i + 1]; // Connect to next component
        cout << u << " " << v << " " << new_v << endl;
        d.unionrank(v, new_v);
    }

    return 0;
}
