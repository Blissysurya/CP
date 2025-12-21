
#include <bits/stdc++.h>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
typedef tree<pair<int, int>, null_type, less<pair<int, int>>,
             rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
int gcd(int a, int b)
{
    if (a > b)
        swap(a, b);
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
struct compare
{
    bool operator()(const int &lhs, const int &rhs) const
    {
        return lhs < rhs;
    }
};
istream &operator>>(istream &in, vi &vec)
{
    for (auto &element : vec)
    {
        in >> element;
    }
    return in;
}
long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int32_t main()
{

    int n, k, x;

    cin >> n >> k >> x;

    vi vec(n);
    cin >> vec;
    int p = k;
    sort(vec.begin(), vec.end());

    vector<int> diff;

    for (int i = 0; i < n - 1; i++)
    {
        diff.push_back(vec[i + 1] - vec[i]);
    }

    sort(diff.begin(), diff.end());

    int ans = 0;

    for (int i = 0; i < diff.size(); i++)
    {
        if (diff[i] > x )
        {
            if (p >= (diff[i] - 1) / x)
            {
                p -= (diff[i] - 1) / x;
            }
            else
            {
                ans++;
                // cout << "Hi" << endl;
            }
        }
    }

    // ceil(a/b) = (a + b - 1) / b
    // ceil(diff / x) - 1 = (diff - 1) / x

    

    cout << ans + 1 << endl;
}
