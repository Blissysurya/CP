
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

void dfs1(int src,vector<vector<int>>&graph,vector<bool>& vis,stack<int>& s){
    vis[src]=true;

    vector<int> neighbors=graph[src];

    for(auto v: neighbors){
        if(!vis[v]){
            dfs1(v,graph,vis,s);
        }
    }
    s.push(src);
}

void dfs2(int src, vector<vector<int>>& graphr, vector<bool>& vis,vector<int> &components){
   
    vis[src]=true;
    components.push_back(src);

    vector<int> neighbors=graphr[src];

    for(auto v: neighbors){
        if(!vis[v]){
            dfs2(v,graphr,vis,components);
        }
    }

 
}


void kosaraju( vector<vector<int>>& graph,vector<vector<int>>& graphr,int n,vector<int>& c){
    stack<int> s;

    vector<bool> vis(n,false);

    for(int i=0;i<n;i++){
        if(!vis[i]){
        dfs1(i,graph,vis,s);
        }
    }

    vis.assign(n,false);

    vvi scc;

    while(!s.empty()){
        int el=s.top();
        s.pop();

        vector<int> components;
        if(!vis[el]){
            dfs2(el,graphr,vis,components);
        }
        if(!components.empty()){
            scc.push_back(components);
        }
    }

    // cout<<scc.size()<<endl;
    vector<int> color(n,0);
    vis.assign(n,false);
    int code=1;
    for(vector<int>& vv: scc){
        for(auto &it: vv){
            color[it]=code;
        }
        code++;
    }

    vector<vector<int>> cg(scc.size());

   for(int i=0;i<n;i++){
        
        vector<int> neighbors =graph[i];
        for(auto & v : neighbors){
            if(!vis[v]){
                vis[v]=true;
                if(color[v]!=color[i]){
                        
                }
            }
        }

   }

}

int32_t main(){

    int n,m;
    cin>>n>>m;

    vector<int> c(n);
    cin>>c;

    vector<vector<int>> graph(n);
    vector<vector<int>> graphr(n);
    while(m--){
        int u,v;
        cin>>u>>v;

        u--;v--;

        graph[u].push_back(v);
        graphr[v].push_back(u);
    }

    kosaraju(graph,graphr,n,c);

    }
