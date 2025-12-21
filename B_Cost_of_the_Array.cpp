#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define ff first
#define ss second
#define str string
#define all(x) (x).begin(),(x).end()
#define scanv(v) for(auto &i:v) cin>>i;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rrep(i,x,y) for(int i=x;i>=y;i--)
#define vi vector<int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define vpii vector<pii>
#define vvi vector<vi>
#define vb vector<bool>
#define vc vector<char>
#define vstr vector<str>
#define mii map<int,int>
#define give(ans) cout<<((ans) ? "YES" : "NO");
#define printv(v) for(auto &i:v) cout<<i<<" ";
#define newl cout<<endl;
#define get(x) int x;cin>>x;
#define get2(x,y) int x,y;cin>>x>>y;
#define get3(x,y,z) int x,y,z;cin>>x>>y>>z;
#define srt(a) sort(all(a))
#define rsrt(a) sort(all(a),greater<int>())
#define si set<int>
#define msi multiset<int>
#define mp make_pair
#define fastIO \
ios_base::sync_with_stdio(0);\
cin.tie(0);cout.tie(0);\
 
void solve()
{
    get2(n,k);
    vi a(n+1);rep(i,1,n+1) cin>>a[i];
    
    
    if((n-k)==0)
    {
        rep(i,2,n+1)
        {
            if(a[i]!=i/2) {cout<<i/2;return;}
            i++;
        }
        cout<<k/2+1;return;
    }
    else
    {
        rep(i,2,n-k+3)
        {
            if(a[i]!=1) {cout<<1;return;}
        }
        cout<<2;return;
    }
    return;
}
    
    
    
int32_t main()
{
    fastIO;
    // int t=1;
    get(t);
    while(t--) {solve();newl;}
    return 0;
}