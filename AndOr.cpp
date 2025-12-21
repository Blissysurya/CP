
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

struct Node {
    int len;    // number of elements in this segment
    int val[2]; // val[0]: result if next op is '&', val[1]: result if next op is '|'
};

class SegmentTree {
    vector<Node> tree;
    int n;
    
    // Merge two nodes L and R.
    // The idea: when merging, the next operation depends on L.len:
    // If L.len is odd, next op is '&', so we combine using R.val[0].
    // If L.len is even, next op is '|', so we combine using R.val[1].
    Node mergeNode(const Node &L, const Node &R) {
        Node M;
        M.len = L.len + R.len;
        for (int init = 0; init < 2; init++) {
            if (L.len % 2 == 1) {
                // Next operation is '&'
                M.val[init] = L.val[init] & R.val[0];
            } else {
                // Next operation is '|'
                M.val[init] = L.val[init] | R.val[1];
            }
        }
        return M;
    }
    
    // Build the tree recursively.
    void build(const vector<int> &arr, int idx, int l, int r) {
        if (l == r) {
            tree[idx].len = 1;
            // For a leaf, both possibilities are the same.
            tree[idx].val[0] = arr[l];
            tree[idx].val[1] = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(arr, 2 * idx + 1, l, mid);
            build(arr, 2 * idx + 2, mid + 1, r);
            tree[idx] = mergeNode(tree[2 * idx + 1], tree[2 * idx + 2]);
        }
    }
    
    // Update a position recursively.
    void update(int idx, int l, int r, int pos, int value) {
        if (l == r) {
            tree[idx].len = 1;
            tree[idx].val[0] = value;
            tree[idx].val[1] = value;
        } else {
            int mid = (l + r) / 2;
            if (pos <= mid)
                update(2 * idx + 1, l, mid, pos, value);
            else
                update(2 * idx + 2, mid + 1, r, pos, value);
            tree[idx] = mergeNode(tree[2 * idx + 1], tree[2 * idx + 2]);
        }
    }
    
public:
    // Construct the segment tree from the array.
    SegmentTree(const vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    
    // Get the overall result.
    // The entire evaluation starts with an '&' operation (as given).
    int getResult() {
        return tree[0].val[0];
    }
    
    // Public update interface.
    void updatePos(int pos, int value) {
        update(0, 0, n - 1, pos, value);
    }
};


int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vi vec(n);
        cin>>vec;

        SegmentTree seg(vec);
        int q;
        cin>>q;

        while(q--){
            int idx,val;
            cin>>idx>>val;

            vec[idx-1]=val;
            seg.update(idx-1,val);

            cout<<seg.getResult()<<endl;
            
        }
        }
    }
