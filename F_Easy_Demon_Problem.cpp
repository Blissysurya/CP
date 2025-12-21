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
  
        int n,m,q;
        cin>>n>>m>>q;

        vi a(n);cin>>a;
        vi b(m);
        cin>>b;

        set<int> s1;
        set<int> s2;

        vector<vector<int>> vec(n,vector<int>(m));

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                vec[i][j]=a[i]*b[j];
            }
            
        }
        
        
        while(q--){
            int x;
            cin>>x;

        }
    
    
}