// #include <bits/stdc++.h>
// #include <numeric>
// using namespace std;
// // #define int long long 
// const int MAXV = 1e6;
// #define whole(x) x.begin(), x.end()
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// int gcd(int a, int b)
// {
//     if(a>b) swap(a,b);
//     if (a == 0)
//         return b;
//     return gcd(b % a, a);
// }
// struct compare{
//     bool operator()(const int &lhs, const int&rhs)const{
//         return lhs<rhs;
//     }
// };
// istream& operator>>(istream& in, vi& vec) {
//     for (auto& element : vec) {
//         in >> element;
//     }
//     return in;
// }
// long long binpow(long long a, long long b) {
//     long long res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a;
//         a = a * a;
//         b >>= 1;
//     }
//     return res;
// }


// vector<int> least_prime(MAXV, 0);
// void leastPrimeFactor(int n)
// {
//     least_prime[1] = 1;
//     for (int i = 2; i <= n; i++)
//     {
       
//         if (least_prime[i] == 0)
//         {
           
//             least_prime[i] = i;
 
//             for (int j = i*i; j <= n; j += i)
//                 if (least_prime[j] == 0)
//                    least_prime[j] = i;
//         }
//     }
// }
//  vector<bool> prime(MAXV, true);
// void Sieve(int n)
// {
//   for (int p = 2; p * p <= n; p++) {

//         if (prime[p] == true) {
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     }
// }

// bool isPowerOfTwo(int n) {
//     return n > 0 && (n & (n - 1)) == 0;
// }

// int countSetBits(int n) {
//     int count = 0;
//     while (n) {
//         count += n & 1;
//         n >>= 1;
//     }
//     return count;
// }

// int mostSignificantBit(int n) {
//     int msb = 0;
//     while (n >>= 1) {
//         msb++;
//     }
//     return 1 << msb;
// }

// int leastSignificantBit(int n) {
//     return n & -n;
// }

// bool isIthBitSet(int n, int i) {
//     return (n & (1 << i)) != 0;
// }

// int ternary_search(int lo, int hi) {
//     while (hi - lo >= 3)
//     {
//         int mid1 = lo + (hi - lo) / 3;
//         int mid2 = hi - (hi - lo) / 3;
//         // int f1 = f(mid1);
//         // int f2 = f(mid2);
//         // if (f1 > f2)
//         // {
//         //     hi = mid2;
//         // }
//         // else if (f1 < f2)
//         // {
//         //     lo = mid1;
//         // }
//         // else
//         // {
//         //     // Note: this case doesn’t need to be explicitly handled
//         //     lo = mid1;
//         //     hi = mid2;
//         // }
//     }
//     int ans = INT_MIN;
    
//     // for (int i = lo; i <= hi; i++) ans = max(ans, f(i));
   
//     return ans;
// }


// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//             int n;
//             cin>>n;

//             vi vec(n,0);
//             for(int i=0;i<n;i++){
//                 cin>>vec[i];
//             }

//             bool state=true;

//             // int cnt=1;
//             int ans=0;
//             int res=0;
//             bool f=true;
//             // vi diff;
            
//             for(int i=0;i<n-1;i++){
//                 // int ele=vec[i];
//                 // if (vec[i-1]>ele) {
//                 //     cnt++;

//                 //     ans=max(ans,cnt);
//                 //     if ((i+1)<n && vec[i+1]>ele) {
//                 //         cnt++;
//                 //         i++;
                        
//                 //     ans=max(ans,cnt);
//                 //     }
//                 //     else cnt=1;
//                 // }
//                 // else cnt=1;
                
//                 // ans=max(ans,cnt);

//                 // if(vec[i]<vec[i-1] && vec[i]<vec[i+1]){
//                 //     i++;
//                 //     cnt+=2;
//                 // }else if(f){
//                 //     cnt+=2;
//                 //     f=false;
//                 // }
//                 // diff.push_back(vec[i]-vec[i+1]);


//                 if(f && vec[i]-vec[i+1] >0){
//                     ans++;
//                     f=!f;
//                     // res=max(res,ans);
//                     // cout<<"Hi"<<endl;
//                 }
//                 else if(!f && vec[i]-vec[i+1] < 0){
//                     ans++;
//                     f=!f;
//                     // res=max(res,ans);
//                     // cout<<"Hello"<<endl;
//                 }else{
//                     res=max(res,ans);
//                     ans=0;
//                     // cout<<"Hola"<<endl;
//                 }
//                 // cout<<res+1<<" ";
                
//             }
//             if(res==0 || res < ans){
//                 res=max(res,ans);
//             }
            
//             // int ans1=0;
//             // int ans2=0;
//             // for(int i=0;i<diff.size();i++){
//             //     if(diff[i] < diff[i+1]){
//             //         ans1++;
//             //     }else{
//             //         break;
//             //     }
//             // }

//             //  for(int i=0;i<diff.size();i++){
//             //     if(diff[i] > diff[i+1]){
//             //         ans2++;
//             //     }else{
//             //         break;
//             //     }

//             cout<<res+1<<endl;
//             // cout<<max(ans1,ans2)+1<<endl;
//     }
//     }
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while (t--){
    	int n;
    	cin>>n;
    	vector <int> vec(n);
    	vector <int> diff;
    	
    	for (int i=0; i<n; i++){
    		cin>>vec[i];
    		if (i>=1) {
    			int val=vec[i-1]-vec[i];
    			diff.push_back(val);
    		}
    	}
    	
    	int ans=1;
    	int index=INT_MAX;
    	for (int i=0; i<diff.size()-1; i++){
    		if (diff[i]>0) {
    			ans++;
    			index=i;
    			break;
    		}
    	}
    	// for (auto i: diff){
    		// cout<<i<<" ";
    	// }
    	// cout<<endl;
    	
    	// int curr=index;
    	// int prev=curr;
    	// for (int i=index+1; i<diff.size(); i++){
    		// if (diff[i]>0) curr=i;
    		// if ((curr-prev)>1) ans+=2;
    		// prev=curr;
    	// }
    	
    	
    	int index2=INT_MAX;
    	for (int i=index+1; i<diff.size(); i++){
    		if (diff[i]<0) {
    			index2=i;
    			ans++;
    			break;
    		}
    	}
    	
    	int curr=index2;
    	int prev=curr;
    	for (int i=index2+1; i<diff.size(); i++){
    		if (diff[i]<0) curr=i;
    		if ((curr-prev)>1) ans+=2;
    		prev=curr;
    	}
    	if (curr<(diff.size()-1)) ans++;
    	cout<<ans<<endl;
    }
    
    return 0;
}
