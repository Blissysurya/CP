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
        int n,k;
        cin>>n>>k;

        priority_queue<int,vector<int>,greater<int>> pq;

        for (size_t i = 0; i < n; i++)
        {
            pq.push(i+1);
        }
        vi vec(n,0);

        int p=n/k;
        
        int i=1;
        
        while(p--){
            int pos=i*k-1;
            vec[pos]=pq.top();
            pq.pop();
            i++;
        }

        for(int i=0;i<n;i++){
            if(vec[i]==0){
                vec[i]=pq.top();
                pq.pop();
            }
        }
        
        for (size_t i = 0; i < n; i++)
        {
           cout<<vec[i]<<" ";
        }

        cout<<endl;
        

    
    }
}