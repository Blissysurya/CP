#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define ff first
#define ss second
#define str string
#define all(x) (x).begin(), (x).end()
#define scanv(v)      \
    for (auto &i : v) \
        cin >> i;
#define rep(i, x, y) for (int i = x; i < y; i++)
#define rrep(i, x, y) for (int i = x; i >= y; i--)
#define vi vector<int>
#define pii pair<int, int>
#define pib pair<int, bool>
#define vpii vector<pii>
#define vvi vector<vi>
#define vb vector<bool>
#define vc vector<char>
#define vstr vector<str>
#define mii map<int, int>
#define give(ans) cout << ((ans) ? "YES" : "NO");
#define printv(v)     \
    for (auto &i : v) \
        cout << i << " ";
#define newl cout << endl;
#define get(x) \
    int x;     \
    cin >> x;
#define get2(x, y) \
    int x, y;      \
    cin >> x >> y;
#define get3(x, y, z) \
    int x, y, z;      \
    cin >> x >> y >> z;
#define srt(a) sort(all(a))
#define rsrt(a) sort(all(a), greater<int>())
#define si set<int>
#define msi multiset<int>
#define mp make_pair
#define int long long


int MOD=1e9+7;
int32_t main()
{
    int n;
    cin >> n;

    vvi vec(n, vi(n, 0));

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cin >> vec[i][j];
        }
    }

    int m = 1 << n;
    vi dp(m, 0);
    dp[0]=1;

    for (int mask = 1; mask < m; mask++)
    {
        int p=__builtin_popcount(mask);
        p--;
        for (int i = 0; i < n; i++)
        {

            if (mask & (1 << i))
            {
                
                    if (vec[p][i])
                    {
                        dp[mask] += dp[mask ^ (1 << i)];
                        dp[mask]%=MOD;
                    }
                
            }
        }
    }

    cout<<dp[m-1]<<endl;
}