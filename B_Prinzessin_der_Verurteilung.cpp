
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

    int MOD = 1e9 + 7;

    int hashfun(string s){
        int h=0;
        for(size_t i=0;i<s.size();i++){
            h=(31*h+(s[i]-'a'+1))%MOD;
        }
        return h;
    }



    int32_t main(){

        vector<string> ss;
        for(int i=0;i<=25;i++){
            ss.push_back(string(1,'a'+i));
        }

        for(int i=0;i<=25;i++){
            string s1=string(1,'a'+i);
            for(int j=0;j<=25;j++){
                string s2=string(1,'a'+j);
                string s3=s1+s2;
                ss.push_back(s3);
            }
        }


        for(int i=0;i<=25 && ss.size()<=1000;i++){
            string s1=string(1,'a'+i);
            for(int j=0;j<=25 && ss.size()<=1000;j++){
                string s2=string(1,'a'+j);
                string s3=s1+s2;
                for(int k=0;k<=25 && ss.size()<=1000 ;k++){
                    string s4=s3+(string(1,'a'+k));
                    ss.push_back(s4);
                }
            }
        }


        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;

            string s;
            cin>>s;

            string ans;

            for(int i=0;i<ss.size();i++){
            string c=ss[i];
            int hash_c=hashfun(c);
            
        
            int n=s.size();
            int m=c.size();
            int start_hash=hashfun(s.substr(0,m));

            int p=1;
            for(int i=0;i<m-1;i++) p=(p*31)%MOD;
            
            int count=0;
            if(hash_c==start_hash){
                count++;
            }

            for(int i=1,j=m; j<n;i++,j++){
                int del=((s[i-1]-'a'+1)*p);
                int add=(s[j]-'a'+1);

                start_hash= ((start_hash-del +MOD)*31+add)%MOD;
                if(hash_c==start_hash){
                    count++;
                }
            }

            if(count==0){
                ans=c;
                break;
            }

        }   

        cout<<ans<<endl;
            }
        }
