#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXV = 1e6;

int n, q;
vector<vector<int>> arr;
vector<vector<int>> graph;
vector<int> depth;
vector<int> par;

void dfs(int s, int p) {
    arr[s][0] = p;

    for (int i = 1; i < arr[s].size(); i++) {
        arr[s][i] = arr[arr[s][i - 1]][i - 1];
    }

    for (int ch : graph[s]) {
        if (ch != p) {
            depth[ch] = depth[s] + 1;
            dfs(ch, s);
        }
    }
}

int findxthpar(int node, int k) {
    for (int j = arr[node].size() - 1; j >= 0; j--) {
        if ((1 << j) & k) {
            node = arr[node][j];
            k -= (1 << j);
        }
    }
    return node;
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }

    int d = depth[b] - depth[a];
    b = findxthpar(b, d);
    if (a == b) {
        return a;
    }

    for (int i = arr[a].size() - 1; i >= 0; i--) {
        if (arr[a][i] != arr[b][i]) {
            a = arr[a][i];
            b = arr[b][i];
        }
    }

    return arr[a][0];
}

int32_t main() {
    cin >> n >> q;

   
    int x = log2(n) + 1;
    arr.assign(n + 1, vector<int>(x + 1, 0));
    graph.assign(n + 1, vector<int>());
    depth.assign(n + 1, 0);
    par.assign(n + 1, 0);

    vector<int> vec(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> vec[i];
    }

    par[1] = 1; 
    for (int i = 0; i < vec.size(); i++) {
        par[i + 2] = vec[i];
        graph[vec[i]].push_back(i + 2);
    }

    dfs(1, 0);

    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }

    return 0;
}