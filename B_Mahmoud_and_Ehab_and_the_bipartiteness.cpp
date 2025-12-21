
#include <bits/stdc++.h>
#include <numeric>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace std;
using namespace __gnu_pbds;
#define int long long 
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
typedef tree<pair<int, int>, null_type, less<pair<int, int> >,
             rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
int gcd(int a, int b)
{
    if(a>b) swap(a,b);
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
struct compare{
    bool operator()(const int &lhs, const int&rhs)const{
        return lhs<rhs;
    }
};
istream& operator>>(istream& in, vi& vec) {
    for (auto& element : vec) {
        in >> element;
    }
    return in;
}
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


vector<int> least_prime(MAXV, 0);
void leastPrimeFactor(int n)
{
    least_prime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
       
        if (least_prime[i] == 0)
        {
           
            least_prime[i] = i;
 
            for (int j = i*i; j <= n; j += i)
                if (least_prime[j] == 0)
                   least_prime[j] = i;
        }
    }
}
 vector<bool> prime(MAXV, true);
void Sieve(int n)
{
  for (int p = 2; p * p <= n; p++) {

        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int mostSignificantBit(int n) {
    int msb = 0;
    while (n >>= 1) {
        msb++;
    }
    return 1 << msb;
}

int leastSignificantBit(int n) {
    return n & -n;
}

bool isIthBitSet(int n, int i) {
    return (n & (1 << i)) != 0;
}

int ternary_search(int lo, int hi) {
    while (hi - lo >= 3)
    {
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;
        // int f1 = f(mid1);
        // int f2 = f(mid2);
        // if (f1 > f2)
        // {
        //     hi = mid2;
        // }
        // else if (f1 < f2)
        // {
        //     lo = mid1;
        // }
        // else
        // {
        //     // Note: this case doesn’t need to be explicitly handled
        //     lo = mid1;
        //     hi = mid2;
        // }
    }
    int ans = INT_MIN;
    
    // for (int i = lo; i <= hi; i++) ans = max(ans, f(i));
   
    return ans;
}

class Graph{
    int V;
    list<int> * l;

    public: 
        Graph(int V){
            this->V=V;
            l=new list<int> [V+1];
        }

        void buildEdge(int u, int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }

        void dfsHelper(int src, vector<bool> &vis){
            vis[src]=true;
            cout<<src<<" ";
            for(auto v : l[src]){
                if(!vis[v]){
                    vis[v]=true;
                    dfsHelper(v,vis);
                }
            }
            
        }

        void dfs(){
            vector<bool> vis(V,false);

            for(int i=1;i<=V;i++){
                if(!vis[i]){
                dfsHelper(i,vis);
                }
            }
            cout<<endl;
        }

       bool has_cycle_helper(int src, vector<bool>& vis, int parent) {
    vis[src] = true;
    for (auto v : l[src]) {
        if (!vis[v]) {
            if (has_cycle_helper(v, vis, src)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool hascycle() {
    vector<bool> vis(V + 1, false); // Ensure size is V + 1 to accommodate 1-based indexing
    for (int i = 1; i <= V; i++) {
        if (!vis[i]) {
            if (has_cycle_helper(i, vis, -1)) {
                return true;
            }
        }
    }
    return false;
}

    bool isBipartite(vector<int> &color){
        vector<int> vis(V+1,false);

        queue<int> q;
        q.push(1);
        color[1]=0;
        vis[1]=true;

        while(!q.empty()){
            int x=q.front();
            q.pop();

            list<int> neighbors= l[x];

            for(auto v: neighbors){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                    color[v]= !color[x];
                }else{
                    if(color[v]==color[x]){
                        return false;
                    }
                }
            }
            
        }
        return true;
    } 

};

int32_t main(){
    int n;
    cin>>n;

    Graph g(n);
    int t=n-1;
    while(t--){
        int x,y;
        cin>>x>>y;

        g.buildEdge(x,y);

    }

        vector<int> color(n+1,-1);

        g.isBipartite(color);

        int a=0;
        int b=0;


        if(n==1){
            cout<<0<<endl;
        }
        for(int i=1;i<=n;i++){
                if(color[i]==0){
                    a++;
                }else{
                    b++;
                }
        }

        int p=a*b;
        // cout<<a<<" "<<b<<endl;
        cout<<p-(n-1)<<endl;

        // for(auto it: color){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

    }
