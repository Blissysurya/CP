#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int N, M;
vector<vector<int>> adj;
vector<int> disc, low, comp;  // discovery time, low-link, component id
vector<bool> inStack;
stack<int> st;
int timeCounter = 0, compCount = 0;

void tarjanDFS(int u) {
    disc[u] = low[u] = ++timeCounter;
    st.push(u);
    inStack[u] = true;
    
    for (int v : adj[u]) {
        if (disc[v] == 0) {
            tarjanDFS(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }
    
    if (low[u] == disc[u]) {
        // Found an SCC, assign component id to all nodes in this SCC.
        while (true) {
            int w = st.top();
            st.pop();
            inStack[w] = false;
            comp[w] = compCount;
            if (w == u) break;
        }
        compCount++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.resize(N);
    disc.assign(N, 0);
    low.assign(N, 0);
    comp.assign(N, -1);
    inStack.assign(N, false);

    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--; v--; // converting to 0-indexed
        adj[u].push_back(v);
    }
    
    // Run Tarjan's algorithm to find all SCCs.
    for (int i = 0; i < N; i++){
        if (disc[i] == 0)
            tarjanDFS(i);
    }
    
    // Build condensed graph: for each edge (u,v) that connects different SCCs, record the outdegree.
    vector<int> outdeg(compCount, 0);
    for (int u = 0; u < N; u++){
        for (int v : adj[u]){
            if (comp[u] != comp[v])
                outdeg[comp[u]]++;
        }
    }
    
    // Find the unique sink component (with outdeg = 0).
    int sinkComp = -1;
    int countZero = 0;
    for (int i = 0; i < compCount; i++){
        if (outdeg[i] == 0){
            sinkComp = i;
            countZero++;
        }
    }
    
    // If there is not exactly one sink component, then no city is reachable from all others.
    vector<int> candidates;
    if(countZero == 1){
        for (int i = 0; i < N; i++){
            if(comp[i] == sinkComp)
                candidates.push_back(i + 1); // converting back to 1-indexed
        }
        sort(candidates.begin(), candidates.end());
    }
    
    cout << candidates.size() << "\n";
    if(!candidates.empty()){
        for (int city : candidates)
            cout << city << " ";
        cout << "\n";
    }
    
    return 0;
}
