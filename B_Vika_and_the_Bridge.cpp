
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;

        cin >> n >> k;

        vi vec(n);
        cin >> vec;

        map<int, int> mp;
        map<int, priority_queue<int>> mp2;

        int mint = INT_MAX;

        vi last(*max_element(vec.begin(), vec.end()) + 1, -1);

        for (int i = 0; i < n; i++)
        {
            if (mp.find(vec[i]) != mp.end())
            {
                int dist = i - mp[vec[i]] - 1;
                mp2[vec[i]].push(dist);
            }
            else
            {
                mp2[vec[i]].push(i);
            }
            last[vec[i]] = i;
            mp[vec[i]] = i;
        }

        for (int v = 0; v < last.size(); v++)
        {
            if (last[v] != -1)
            {
                mp2[v].push(n - 1 - last[v]);
            }
        }

        for (auto &it : mp2)
        {
            int gdist = it.second.top();
            it.second.pop();
            it.second.push(gdist / 2);
            it.second.push(gdist - gdist / 2 - 1);
        }

        int ans = INT_MAX;

        for (auto &it : mp2)
        {
            ans = min(ans, it.second.top());
        }

        cout << ans << endl;
    }
}
