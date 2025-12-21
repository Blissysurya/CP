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
        
        int k=2;

        while(true){
            bool even=false, odd=false;
            for(int i: vec){
                if((i&1)==0){
                    even=true;
                }
                else{
                    odd=true;
                }
            }
            if(even && odd){
                break;
            }
            k<<=1;
           for(int i=0;i<n;i++){
            vec[i]>>=1;
           }
        }

        cout<<k<<endl;
    }
}