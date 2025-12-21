#include <bits/stdc++.h>
#include <numeric>
using namespace std;
// #define int long long 
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
struct compare{
    bool operator()(const int &lhs, const int&rhs)const{
        return lhs<rhs;
    }
};
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
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi a(n);
        cin>>a;

        int var=-1; 
        vi ans;
        bool even=false;
        bool odd=false;
        for(int i=0;i<n;i++){
            if(a[i]%2!=0){
                odd=true;
            }
            else{
                even=true;
            }
            if(even & odd){
                break;
            }
        }

        if(even && odd){
            cout<<-1<<endl;
        }
        else{
            vi ans;
           
          for(int i=0;i<=29;i++){
                ans.push_back(1<<i);
          }
          if(even){
            ans.push_back(1);
          }

            
        

        cout<<ans.size()<<endl;

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
          cout<<endl;

        }


        }

  
        
    }
