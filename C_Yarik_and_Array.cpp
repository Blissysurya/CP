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

int32_t main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vi vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        int ans=0;
        ans=vec[0];
        int sum=vec[0];
        for(int i=1;i<n;i++){
            if((vec[i-1]%2==0 && vec[i]%2!=0) || (vec[i-1]%2!=0 && vec[i]%2==0)){
                if(sum >0){
                    sum+=vec[i];
                }else{
                    sum=vec[i];
                }

            }else{
                sum=vec[i];
            }
            ans=max(ans,sum);
        }
        
    
        cout<<ans<<endl;
}
return 0;
}