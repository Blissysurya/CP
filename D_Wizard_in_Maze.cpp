
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


vector<int> least_prime(MAXV, 0);
void leastPrimeFactor(int n)
{
    least_prime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
       
        if (least_prime[i] == 0)
        {
           
            least_prime[i] = i;
 
            for (int j = i*i; j <= n; j += i)
                if (least_prime[j] == 0)
                   least_prime[j] = i;
        }
    }
}
 vector<bool> prime(MAXV, true);
void Sieve(int n)
{
  for (int p = 2; p * p <= n; p++) {

        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int mostSignificantBit(int n) {
    int msb = 0;
    while (n >>= 1) {
        msb++;
    }
    return 1 << msb;
}

int leastSignificantBit(int n) {
    return n & -n;
}

bool isIthBitSet(int n, int i) {
    return (n & (1 << i)) != 0;
}

int ternary_search(int lo, int hi) {
    while (hi - lo >= 3)
    {
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;
        // int f1 = f(mid1);
        // int f2 = f(mid2);
        // if (f1 > f2)
        // {
        //     hi = mid2;
        // }
        // else if (f1 < f2)
        // {
        //     lo = mid1;
        // }
        // else
        // {
        //     // Note: this case doesn’t need to be explicitly handled
        //     lo = mid1;
        //     hi = mid2;
        // }
    }
    int ans = INT_MIN;
    
    // for (int i = lo; i <= hi; i++) ans = max(ans, f(i));
   
    return ans;
}

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int32_t main(){
   
    int n,m;
    cin>>n>>m;

    int sx,sy;
    cin>>sx>>sy;

    int ddx,ddy;
    cin>>ddx>>ddy;
    sx--;
    sy--;
    ddx--;
    ddy--;
    vector<string> vec(n);

    for(int i=0;i<n;i++){
       cin>>vec[i];
    }

    vector<vector<int>> cost(n,vector<int>(m,1e8));

    cost[sx][sy]=0;

    deque<pair<int,int>> q;

    q.push_front({sx,sy});

    while(!q.empty()){
        auto ele=q.front();
        int x=ele.first;
        int y=ele.second;
        q.pop_front();
        for(int i=0;i<4;i++){
            if((x+dx[i])>=0 && (x+dx[i])<n && (y+dy[i])>=0 && (y+dy[i])<m && vec[x+dx[i]][y+dy[i]]!='#'){
                if(cost[x+dx[i]][y+dy[i]] > cost[x][y]){
                    cost[x+dx[i]][y+dy[i]]=cost[x][y];
                    q.push_front({x+dx[i],y+dy[i]});
                }
            }
        }

        for(int i=-2;i<3;i++){
            for(int j=-2;j<3;j++){
                if((x+i)>=0 && (x+i)<n && (y+j)>=0 && (y+j)<m && vec[x+i][y+j]!='#'){
                    if(cost[x+i][y+j] > cost[x][y] + 1){
                        cost[x+i][y+j] = cost[x][y]+1;
                        q.push_back({x+i,y+j});
                    }
                }
            }
        }
    }
        if(cost[ddx][ddy]!=1e8){
            cout<<cost[ddx][ddy]<<endl;
        }else{
            cout<<-1<<endl;
        }
    }

