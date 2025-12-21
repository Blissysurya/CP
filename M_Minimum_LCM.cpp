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
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define vb vector<bool>
#define vc vector<char>
#define vstr vector<str>
#define mii map<int,int>
#define vvi vector<vector<int>>
#define result(ans) cout<<((ans) ? "YES" : "NO");
#define printv(v) for(auto &i:v) cout<<i<<" ";
#define newl cout<<endl;
#define get(x) int x;cin>>x;
#define srt(a) sort(all(a))
#define ms multiset
#define mp make_pair
#define fastIO \
ios_base::sync_with_stdio(0);\
cin.tie(0);cout.tie(0);\
 
int32_t main(){
    fastIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        if(n&1){

        int div=1;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                div=i;
                if(i!=1){
                    break;
                }
            }
        }
        if(div!=1){
        int div1=n/div;
        cout<<div1<<" "<<n-div1<<endl;
        }
        else{
            cout<<1<<" "<<n-1<<endl;
        }
        }else{
            cout<<n/2 << " "<< n/2 <<endl;
        }
    }
    return 0;
}