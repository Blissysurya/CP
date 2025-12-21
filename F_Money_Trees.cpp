#include <bits/stdc++.h>
#include <numeric>

#include <functional>
using namespace std;

#define int long long 
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back

istream& operator>>(istream& in, vi& vec) {
    for (auto& element : vec) {
        in >> element;
    }
    return in;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        vi a(n);
        vi h(n);

        cin>>a;
        cin>>h;


        int left=0;
        int right=0;

        int prevHeight=0;
        int sum=0;
        int ans=0;
        for(int right=0; right<n; right++){
            if(right==0 || (h[right-1] % h[right]) == 0 ){
                sum += a[right];
                // prevHeight=h[right];
            }else{
                // prevHeight=0;
                sum=0;
                left=right;
                sum += a[right];
            }
            while((left<=right) && sum > k){
                sum-= a[left];
                left++;
            }
            ans=max(ans,right-left+1);
        }
        cout<<ans<<endl;

        }
    }
