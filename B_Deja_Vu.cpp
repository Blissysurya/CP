
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


int32_t main(){
    int t;
    cin>>t;
    while(t--){
            int n,q;
            cin>>n>>q;

            vi a(n);
            cin>>a;

            vi x(q);
            cin>>x;

            set<int> s;

            for(int i=0;i<q;i++){
                int bit = x[i];

                if(s.find(bit)==s.end()){

                    s.insert(bit);
                    int val = (1<<bit);

                    for( int j=0; j<n; j++){
                        if(a[j]%val == 0){
                            a[j] += (1<<(bit-1));
                        }
                    }

                }

            }

            for(int i=0 ; i<n ; i++){
                cout << a[i] <<" ";
            }

            cout<<endl;

        }
    }
