#include <bits/stdc++.h>
#include <numeric>
#include <functional>
using namespace std;
#define int long long 
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
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
            vi vec(n);
            cin>>vec;

            int ans=0;
            int res=INT_MIN;
            int leftMost=0;
            int leftans=0;

            for(int i=1;i<k-1;i++){
                if(vec[i]>vec[i-1] && vec[i]>vec[i+1]){
                    ans++;
                }
            }   

            res=ans;

            for(int i=k;i<n;i++){


                if(i>=k){
                    if((vec[i - k + 1] > vec[i-k]) && (vec[i - k + 1 ] > vec[i - k + 2])){
                        ans--;
                    }
                    if((vec[i-1] > vec[i]) && (vec[i-1] > vec[i - 2])){
                        ans++;
                    }
                }

                if(i>=k-1){
                    if(ans>res){
                        res=ans;
                        leftMost=i-k+1;
                    }
                }


            }


            cout<<res+1<<" "<<leftMost+1<<endl;
        }
    }
