
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
    int n,k,m;
    cin>>n>>k>>m;

    vi vec(n);
    cin>>vec;

    map<int,vector<int>> mp;
    vector<int> modulo;
    for(int i=0;i<n;i++){
        mp[vec[i]%m].push_back(vec[i]);
    }

    bool poss=false;

    for(auto& it: mp){
        if(it.second.size() >= k){
            cout<<"Yes"<<endl;

            for(int i=0;i<k;i++){
                cout<<it.second[i]<<" ";
            }
            
            poss=true;
            break;
        }
    }

    if(!poss){
        cout<<"No"<<endl;
    }
    
    }
