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

       int sum=0;
       int odd=0;
       int even=0;
    vi out;
       for (size_t i = 0; i < n; i++)
       {
        sum+=vec[i];

        if(vec[i]%2){
            odd++;
        }else{
            even++;
        }
        int cans=sum-odd/3;
        if(even+odd>=2 && odd%3==1){
            cans--;
        }
        out.push_back(cans);
       }
       
        for (size_t i = 0; i < n; i++)
        {
           cout<<out[i]<<" ";
        }
        
        cout<<endl;
       

    
    
    }
}