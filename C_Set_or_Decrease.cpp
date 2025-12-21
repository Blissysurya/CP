
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

bool check(int mid,vector<int>& vec,int k){
    int sum=0;
    int n=vec.size();
    for(int i=0;i<n;i++){
        sum+=vec[i];
    }

    if(sum<=k){
        return true;
    }else{
        int diff = sum-k;
        if(diff <= mid){
            return true;
        }else{
            
            vector<int> temp=vec;

            sort(whole(temp));

           int i=0;
           int j=n-1;
            int at=mid;
           while(i<=j && at){
                if( (temp[j]-temp[i]) >= 1){
                    sum-= temp[j]-temp[i];
                    at--;
                  
                    j--;
                }else{
                    
                    j--;
                }
           }

           if(at>0){
            sum-=at;
           }

           if(sum<=k){
            return true;
           }
        }
    }

    return false;

}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        vi vec(n);
        cin>>vec;

        int low=0;
        int high=1e9;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(check(mid,vec,k)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }

        cout<<ans<<endl;    
        }
    }
