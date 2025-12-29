
#include <bits/stdc++.h>
#include <numeric>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace std;
using namespace __gnu_pbds;
#define int long long 
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
typedef tree<pair<int, int>, null_type, less<pair<int, int> >,
             rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
int gcd(int a, int b)
{
    if(a>b) swap(a,b);
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


int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;

        if(a<b){
            
           

            if(b%2!=0){
                cout<<-1<<endl;
                continue;
            }

            int ratio = (b)/a;

            if(ratio%2!=0){
                cout<<-1<<endl;
                continue;
            }

            int count = 0;
            while(b > a){
                count++;
                b>>=1;
            }

            int val = count/3 + (count%3)/2 + ((count%3)%2) ;
            cout<<val<<endl;
        }
        else
        {   
            if(b==a){
                cout<<0<<endl;
                continue;
            }

           
             if(a%b != 0){
                cout<<-1<<endl;
                continue;
            }
            int ratio = (a)/b;

            if(ratio%2!=0){
                cout<<-1<<endl;
                continue;
            }

            int count = 0;
            while(a > b){
                count++;
                a>>=1;
            }

             int val = count/3 + (count%3)/2 + ((count%3)%2) ;
             cout<<val<<endl;
        }



        }
    }
