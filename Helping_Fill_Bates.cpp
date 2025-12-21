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

int first_occur(string q,char p){
    for(int i=0;i<q.size();i++){
        if(q[i]==p){
            return i;
        }
    }
}

int main(){
    string s;
    cin>>s;

    int n;
    cin>>n;

    vi freq1(100,0);
    
    for(int i=0;i<s.size();i++){
        freq1[s[i]-'A']++;
    }
    set<char> set1;
    for(int i=0;i<s.size();i++){
        set1.insert(s[i]);
    }

    while(n--){
        string p;
        cin>>p;
        set<char> set2;

        bool check=true;
        for(int i=0;i<p.size();i++){
            set2.insert(p[i]);
        }
        vi freq2(100,0);
        
        for(int i=0;i<p.size();i++){
            freq2[p[i]-'A']++;
        }

        for(int i=0;i<100;i++){
            if(freq2[i] > freq1[i]){
                check=false;
                break;
            }
        }

        if(check){
            for(auto it: set2){
                if(set1.find(it)==set1.end()){
                    check=false;
                    break;
                }
            }
        }

        if(check){
            for(auto it:set2){
                if((first_occur(p,it)) > (first_occur(s,it)) ){
                    check=false;
                    break;
                }
            }
        }
            int cnt=
        if(!check){
            cout<<"Not matched"<<endl;
        }else{
            cout<<"Matched "<<(lower_bound(s.begin(),s.end(),p[0])-s.begin())<<" "<<(lower_bound(s.begin(),s.end(),p[p.size()-1])-s.begin())<<endl;
        }

    }    
    }
