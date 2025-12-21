#include <bits/stdc++.h>
#include <numeric>
using namespace std;
// #define int long long 
const int MAXV = 1e6;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
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


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi vec(n);
        cin>>vec;
        sort(vec.begin(),vec.end());
        int a=vec[0];
        int b=vec[1];
        int count = vec.size()-1;
        int ans=b;

        if(count==2){
            cout<<max(a,b)<<endl;
            cout<<a<<" "<<b<<endl;
            continue;
        }

        while(count>1){
            
            ans=ans+a;
            ans=ans+vec[count];
            
            count=count-2;
            
            ans=ans+b;
            ans=ans+b;
            
        }

        
        if(n%2!=0) ans=ans-2*b;

        cout<<ans<<endl;
        count=vec.size()-1;
        if(n%2!=0){
        cout<<a<<" "<<b<<endl;
        
        int x=0;
        while(count>1){
            cout<<a<<endl;
            ans=ans+a;
            x++;
            if(x==n/2) break;
            cout<<vec[count-1]<<" "<<vec[count]<<endl;
            count=count-2;
            cout<<b<<endl;
            cout<<a<<" "<<b<<endl;
            
            
        }
        cout<<a<<" "<<vec[count]<<endl;}
        else{
            cout<<a<<" "<<b<<endl;
        while(count>1){
            cout<<a<<endl;
            cout<<vec[count-1]<<" "<<vec[count]<<endl;
            count=count-2;
            cout<<b<<endl;
            cout<<a<<" "<<b<<endl;
        }
        }
       
        // priority_queue<int> pq;

        // for(int i=2;i<n;i++){
        //     pq.push(vec[i]);
        // }

        // cout<<a<<" "<<b<<endl;
        // int i=0;
        // while(pq.size()>0){
        //    if(i&1){
        //     cout<<b<<endl;
        //    }else{
        //     cout<<a<<endl;
        //    }
        //     cout<<pq.top()<<" ";
        //     pq.pop();
        //     cout<<pq.top()<<endl;
        //     pq.pop();
        //     i++;
        // }

        // if(n%2==0){cout<<a<<" "<<b<<endl;}

        // sort(whole(vec));
        // int maxEl=vec[vec.size()-1];
        // deque<int> dq1;
        // deque<int>dq2;
        // vector<pair<int,int>> out;

        // for(int i=0;i<n;i++){
        //     dq1.push_back(vec[i]);
        // }
        // int time=0;
        // bool flag=false;

        // if(n%2!=0){
        // while(dq1.size()>0){
        //     int x=dq1.front();
        //     dq1.pop_front();

        //     int y=dq1.front();
        //     dq1.pop_front();

        //     if(x==maxEl || y==maxEl){
        //         flag=true;
        //     }

        //      time+=max(x,y);
        //     if(flag){
        //         dq2.push_front(max(x,y));
        //         dq2.push_front(min(x,y));
        //     }
        //    else{
        //     dq2.push_back(min(x,y));
        //     dq2.push_back(max(x,y));
        //    }

        //     out.push_back(make_pair(x,y));

        //     if(dq1.size()==0){
        //         break;
        //     }
        //     int z=dq2.front();
        //     time+=z;
        //     dq2.pop_front();
        //     out.push_back(make_pair(z,0));
           
        //     dq1.push_back(z); // changed
        // }}
        // else{
        //             while(dq1.size()>0){
        //     int x=dq1.front();
        //     dq1.pop_front();

        //     int y=dq1.front();
        //     dq1.pop_front();

        //     if(x==maxEl || y==maxEl){
        //         flag=true;
        //     }

        //      time+=max(x,y);
        // //     if(flag){
        // //         dq2.push_front(max(x,y));
        // //         dq2.push_front(min(x,y));
        // //     }
        // //    else{
        //     dq2.push_back(min(x,y));
        //     dq2.push_back(max(x,y));
        // //    }

        //     out.push_back(make_pair(x,y));

        //     if(dq1.size()==0){
        //         break;
        //     }
        //     int z=dq2.front();
        //     time+=z;
        //     dq2.pop_front();
        //     out.push_back(make_pair(z,0));
           
        //     dq1.push_back(z); // changed
        // }
        //     }


        // cout<<time<<endl;
        // for(int i=0;i<out.size();i++){
        //     if(out[i].second!=0){
        //         cout<<min(out[i].first,out[i].second)<<" "<<max(out[i].first,out[i].second)<<endl;
        //     }else{
        //         cout<<out[i].first<<endl;
        //     }
        // }
        
        // cout<<endl;

        }

    }
