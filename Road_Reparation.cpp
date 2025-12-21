
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

class dsu{
    public:
    vector<int> parent, size, rank;

   
            dsu(int n){
        for(int i = 0; i <= n; i++){
            size.push_back(1);
            parent.push_back(i);
            rank.push_back(0);
        }
    }
 
    int findpar(int node){
        if(parent[node] == node){
            return node;
        }
 
        return parent[node] = findpar(parent[node]);
    }
 
    void unionsize(int u, int v){
        int pu = findpar(u);
        int pv = findpar(v);
 
        if(pu == pv){
            return;
        }
 
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
 
    void unionrank(int u, int v){
        int pu = findpar(u);
        int pv = findpar(v);
 
        if(pu == pv){
            return;
        }
        if(rank[pu] == rank[pv]){
            parent[pu] = pv;
            rank[pu]++;
        }else if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }else{
            parent[pv] = pu;
        }
    }
};

int32_t main(){
        int n,m;
        cin>>n>>m;

        vector<pair<int,pair<int,int>>> edge;

        while(m--){
          int a,b,c;
          cin>>a>>b>>c;

          edge.push_back({c,{a,b}});
        }

        sort(whole(edge));
        int ans=0;
        int cnt=0;
        dsu d=dsu(n);
        for(auto& e: edge){
            int w=e.first;
            int u=e.second.first;
            int v=e.second.second;

            int p1=d.findpar(u);
            int p2=d.findpar(v);

            if(p1==p2){
                continue;
            }

            d.unionsize(p1,p2);
            ans+=w;
            cnt++;
        }

        if(cnt== n-1){
            cout<<ans<<endl;
        }else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
