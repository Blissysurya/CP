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


#define MAX 500

int multiply(int x, int res[], int res_size);


void factorial(int n)
{
    int res[MAX];

    // Initialize result
    res[0] = 1;
    int res_size = 1;
    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);

    cout << "Factorial of given number is \n";
    for (int i = res_size - 1; i >= 0; i--)
        cout << res[i];
}


int multiply(int x, int res[], int res_size)
{
    int carry = 0; // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (int i = 0; i < res_size; i++) {
        int prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry = prod / 10;
    }

    // Put carry in res and increase result size
    while (carry) {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int d;
        cin>>d;

        set<int> ans;
        ans.insert(1);
        if(d==5){
            ans.insert(5);
        }
        if(n>=3 && (d!=3 && d!=6 && d!=9)){
            ans.insert(3);
        }
        if(d==3 || d==6 || d==9){
            ans.insert(3);
        }
        if(d==7){
            ans.insert(7);
        }
        if(d!=7 && n>=3){
            ans.insert(7);
        }
        if(n>=6 && d!=9){
            ans.insert(9);
        }
        if(d==9){
            ans.insert(9);
        }
        if(n<6 && n>=3 && d==3){
             ans.insert(9);
        }
         if(n<6 && n>=3 && d==6){
             ans.insert(9);
        }

        for(auto it: ans){
            cout<<it<<" ";
        }

        cout<<endl;
        }      
    }
