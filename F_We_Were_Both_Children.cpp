#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define int long long 
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
struct compare{
    bool operator()(const int &lhs, const int&rhs) const {
        return lhs<rhs;
    }
};
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
        int n;
        cin>>n;
        vi vec(n);
        cin>>vec;

        // sort(whole(vec));

        map<int,int> mp;
        
        map<int,int> mp1;

        for(int i=0;i<n;i++){
            mp1[vec[i]]++;
        }
        
    

            for(auto& it: mp1){
                    for(int j=it.first;j<=n;j+=it.first){
                        mp[j] += it.second;
                    }
            }   
        

        int maxfreq=INT_MIN;

        for(auto& it: mp){
            maxfreq=max(maxfreq,it.second);
        }

        if(maxfreq==INT_MIN){
            maxfreq=0;
        }
        cout<<maxfreq<<endl;
        
    }
}