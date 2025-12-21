
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

bool vpredicate(int idx,vector<pair<int,int>>& seg, vector<int>& queries,int n){
    vector<int> vec(n,0);
    for(int i=0;i<=idx;i++){
        vec[queries[i]-1]=1;
    }

    for(int i=1;i<n;i++){
        vec[i]+=vec[i-1];
    }

    for(int i=0;i<seg.size();i++){
        int x=seg[i].first;
        int y=seg[i].second;

        x--;
        y--;

        int len = y - x + 1;

        int ones = vec[y]- (x>=0 ? vec[x-1]:0);

        int zeroes = len-ones;

        if(ones > zeroes){
            return true;
        }
    }

    return false;


}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        vector<pair<int,int>> seg(m);

        for(int i=0;i<m;i++){
            cin>>seg[i].first>>seg[i].second;
        }
        
        int q;
        cin>>q;
        vector<int> queries(q);
        cin>>queries;

        int low=0;
        int high=q-1;
        int ans=-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(vpredicate(mid,seg,queries,n)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }

        }

        cout<<ans<<endl;

        }
    }
