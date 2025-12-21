#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define int long long 
#define ll long long
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    if(a>b) swap(a,b);
    return gcd(b % a, a);
}

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

// ... (other functions: leastPrimeFactor, Sieve, etc.)

int32_t main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vi vec(n);
        cin>>vec;

        sort(whole(vec));
        vi ans;
        ans.push_back(vec[vec.size()-1]);

        vector<bool> vis(n,false);
        vis[n-1]=true;
        int y=1;
        for(int i=0;i<n-1;i++) {
            int a=ans[i];
            int x=1;     
            bool change=false;
            for(int j=0;j<n;j++) {
                if(!vis[j]) {
                    int b=vec[j];
                    if(gcd(a,b)>y) {
                        x=b;
                        y=gcd(a,b);
                        change=true;
                        vis[j]=true;
                    }
                }
                if(!change){
                    for(int i=0;i<n;i++){
                        if(!vis[i]){
                            x=vec[i];
                            y=1;
                        }
                    }
                }
               
            }
            ans.push_back(x);
        }

        for(int i=0;i<ans.size();i++) {
            cout<<ans[i]<<" ";
        }
        cout << endl; // Add newline for better output formatting
    }
    return 0;
}