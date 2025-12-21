#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int MAXV = 1e5;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V + 1];
    }

    void buildEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isBipartite() {
        vector<int> vis(V + 1, false);
        vector<int> color(V + 1, -1);

        for (int i = 1; i <= V; i++) {
            if (!vis[i]) {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                vis[i] = true;

                while (!q.empty()) {
                    int x = q.front();
                    q.pop();

                    for (auto v : l[x]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            q.push(v);
                            color[v] = !color[x];
                        } else if (color[v] == color[x]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int i = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;

        Graph g(n);

        while (m--) {
            int x, y;
            cin >> x >> y;
            g.buildEdge(x, y);
        }

        cout << "Scenario #" << i << ":\n";
        if (!g.isBipartite()) {
            cout << "Suspicious bugs found!\n";
        } else {
            cout << "No suspicious bugs found!\n";
        }
        i++;
    }
    return 0;
}
