
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

int query(int l, int r){
    cout<<"? "<<l<<" "<<r<<endl;
    int x;
    cin>>x;
    return x;
}

int32_t main(){
    int n;
    
    cin>>n;

    int low= 1;
    int high=n;

    int ans=-1;
    while(low<=high){
        int orig = query(low,high);
        
        if(query(low,orig) == orig){
            high=orig-1;
            ans=orig;
        }else{
            low=orig+1;
            
        }

    }

    cout<<"! "<<ans<<endl;

}
