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
    #define int long long
    #define ll long long

    int32_t main(){
        int n;
        cin>>n;

        vector<vector<float>> vec(n,vector<float>(n,0));
        rep(i,0,n){
            rep(j,0,n){
                cin>>vec[i][j];
            }
        }

        vector<float> dp(1<<n);
        int m=1ll<<n;
        dp[m - 1]=1;
        for(int mask= m- 1 ; mask>0 ; mask--){
            for(int i=0;i<n;i++){
                int bit=1ll<<i;
                if(mask & bit) 
                {
                    continue;
                }
                    int omask = mask ^ (1ll<<i);
                    for(int j=0;j<n;j++){
                        if(!(mask & (1ll<<j))) continue;    
                        float setbits =  __builtin_popcount(omask);
                        float nC2= 2.0/(setbits*(setbits-1.0)) ;

                        dp[mask] += 1.0*dp[omask]*vec[j][i]*(nC2);

                    
                }
            }
        }

        for(int i=0;i<n;i++){
            cout<<fixed;
            cout<<setprecision(8);
            cout<<dp[1ll<<i]<<" ";
        }
        cout<<endl;
    }
