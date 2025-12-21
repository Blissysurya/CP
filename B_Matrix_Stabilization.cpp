// #include <bits/stdc++.h>
// #include <numeric>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include <functional>
// using namespace std;
// using namespace __gnu_pbds;
// #define int long long 
// const int MAXV = 1e6;
// #define whole(x) x.begin(), x.end()
// typedef vector<int> vi;
// typedef vector<vi> vvi;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
// typedef tree<pair<int, int>, null_type, less<pair<int, int> >,
//              rb_tree_tag, tree_order_statistics_node_update>
//     ordered_map;
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


// int32_t main(){
//     int t;
//     cin>>t;
//     while(t--){

//         int n,m;
//         cin>>n>>m;

//         vvi vec(n,vi(m,0));

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 cin>>vec[i][j];
//             }
//         }

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(i==0 && j>0 )
//                 {
//                     if(j==m-1){
//                         if(vec[i][j]>vec[i+1][j] && vec[i][j]>vec[i][j-1]){
//                         vec[i][j]=max(vec[i][j-1],vec[i+1][j]);
//                         }
//                     }else{
//                         if(vec[i][j]>vec[i][j+1] && vec[i][j]>vec[i+1][j] && vec[i][j]>vec[i][j-1]){
//                             vec[i][j]=max(vec[i][j+1],max(vec[i+1][j],vec[i][j-1]));
//                         }
//                     }
//                 }
//                 else if(i>0  && j==0){
//                     if(i==n-1){
//                             if(vec[i][j]>vec[i-1][j] && vec[i][j]>vec[i][j+1] ){
//                                 vec[i][j]=max(vec[i-1][j] ,vec[i][j+1]) ;
//                             } 
//                     }else{
//                             if(vec[i][j]>vec[i-1][j] && vec[i][j]>vec[i][j+1] && vec[i][j] > vec[i+1][j]){
//                                     vec[i][j]=max(vec[i-1][j],max(vec[i][j+1],vec[i+1][j]));
//                             } 
//                     }
//                 }
//                 else if(i==0 && j==0){
//                     if(vec[i][j] > vec[i+1][j] && vec[i][j]> vec[i][j+1]){
//                         vec[i][j]=max(vec[i+1][j],vec[i][j+1]);
//                     }
//                 }
//                 else if(i==n-1 && j>0){
//                     if(j==m-1){
//                         if(vec[i][j] > vec[i-1][j] && vec[i][j]> vec[i][j-1]){
//                             vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
//                         }
//                     }else{
//                         if(vec[i][j] > vec[i-1][j] && vec[i][j] > vec[i][j-1] && vec[i][j] > vec[i][j+1]){
//                             vec[i][j]=max(vec[i-1][j],max(vec[i][j-1],vec[i][j+1]));
//                         }
//                     }
//                 }
//                 else if(j==m-1 && i>0){
//                         if(i==n-1){
//                             if(vec[i][j] > vec[i-1][j] && vec[i][j] >vec[i][j-1] ){
//                                 vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
//                             }
//                         }else{
//                             if(vec[i][j] > vec[i-1][j] && vec[i][j] >vec[i][j-1] && vec[i][j] > vec[i+1][j]){
//                                 vec[i][j]=max(vec[i-1][j],max(vec[i][j-1],vec[i+1][j]));
//                             }
//                         }
//                 }   
//                 else{
//                     if(vec[i][j] > vec[i-1][j] && vec[i][j] > vec[i+1][j] && vec[i][j] > vec[i][j+1] && vec[i][j] > vec[i][j-1]){
//                         vec[i][j]=max(vec[i-1][j],max(vec[i+1][j],max(vec[i][j+1],vec[i][j-1])));
//                     }
//                 }
//             }
//         }

//             for(int i=0;i<n;i++){
//                 for(int j=0;j<m;j++){
//                         cout<<vec[i][j]<<" ";
//                 }
//                 cout<<endl;
//             }


//             }
//          }

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;
typedef vector<vi> vvi;

int32_t main(){
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vvi vec(n, vi(m, 0)), temp(n, vi(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> vec[i][j];
                temp[i][j] = vec[i][j];  // Copy the original matrix to temp
            }
        }

        // Direction vectors for checking the neighbors (top, right, bottom, left)
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int maxValue = vec[i][j];
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        maxValue = max(maxValue, vec[ni][nj]);
                    }
                }
                temp[i][j] = maxValue;  // Store the max value in the temporary matrix
            }
        }

        // Output the modified matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << temp[i][j] << " ";
            }
            cout << endl;
        }
    }
}
