#include <bits/stdc++.h>
#include <numeric>
using namespace std;
// #define int long long 
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
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

int main(){
    int t;
    cin>>t;
    // leastPrimeFactor(MAXV);
    while(t--){
        int d;
        cin>>d;

        int n;
        cin>>n;

        vector<vector<int>> rat_grid(1025,vector<int>(1025,0));

        while(n--){
            int x,y,p;
            cin>>x>>y>>p;

            for(int i=x-d;i>=0 && i<=x+d && i<=1024; i++){
               for(int j=y-d;j>=0 && j<=y+d && j<=1024; j++){
                    rat_grid[i][j]+=p;
               }
            }

        }
        int max=INT_MIN;
        int xp=0;
        int yq=0;
        for(int i=0;i<1025;i++){
            for(int j=0;j<1025;j++){
                if(rat_grid[i][j] > max){
                    max=rat_grid[i][j];
                    xp=i;
                    yq=j;
                }
            }
        }

        cout<<xp<<" "<<yq<<" "<<max<<endl;
   
        }      
    }
