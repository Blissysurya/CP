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
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vi vec(n);
        cin>>vec;

        vi pre(n);

        for(int i=0;i<n;i++){
            if(i%2){
                vec[i]=-vec[i];
            }
        }

        pre[0]=vec[0];
        for (size_t i = 1; i < n;i++)
        {
            pre[i]=pre[i-1]+vec[i];
        }

        multiset<int> m;

        for (size_t i = 0; i < n; i++)
        {
            m.insert(pre[i]);
        }
        bool ans=false;
        for(auto it: m){
            if(m.count(it)>=2 || m.count(0)>=1){
                ans=true;
                break;
            }
        }
        

        if(ans){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }


    
    }
}