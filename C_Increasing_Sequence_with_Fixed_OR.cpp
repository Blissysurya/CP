// #include <bits/stdc++.h>
// #include <numeric>
// using namespace std;
// #define int long long 
// #define whole(x) x.begin(), x.end()
// typedef vector<int> vi;
// int gcd(int a, int b)
// {
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

// string DecimalToBinary(int num)
// {
//     string str;
//       while(num){
//       if(num & 1) 
//         str+='1';
//       else 
//         str+='0';
//       num>>=1; 
//     }    
//       return str;
// }

// int32_t main(){
//     int t;
//     cin>>t;
//     while(t--){
//             int n;
//             cin>>n;
            
//             string s=DecimalToBinary(n);

//             int p=0;
//             for(int i=0;i<s.size();i++){
//                 if(s[i]=='1'){
//                     p++;
//                 }
//             }

//             cout<<p+1<<endl;

//             vi ans;
//             ans.push_back(stoll(s, nullptr, 2));
//             for(int i=1;i<s.size();i++){
//                 string ns=s;
//                 if(ns[i]=='1'){
//                    ns[i]= '0';
//                 }
//                 ans.push_back(stoll(ns, nullptr, 2));
//             }

//             s[0]=0;
//             ans.push_back(stoll(s, nullptr, 2));
//             sort(ans.begin(),ans.end());
            
//             for(int i=0;i<n;i++){
//                 cout<<ans[i]<<" ";
//             }
//             cout<<endl;

//         }      
//     }

#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define int long long
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;

istream& operator>>(istream& in, vi& vec) {
    for (auto& element : vec) {
        in >> element;
    }
    return in;
}

string DecimalToBinary(int num) {
    if (num == 0) return "0";
    string str;
    while (num) {
        if (num & 1)
            str += '1';
        else
            str += '0';
        num >>= 1;
    }
    reverse(str.begin(), str.end());
    return str;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string s = DecimalToBinary(n);
       

        int p = 0;
        for (char c : s) {
            if (c == '1') {
                p++;
            }
        }


         vi ans;
        if(p==1){
            ans.push_back(stoll(s, nullptr, 2));
            
            cout<<p<<endl;
            cout<<ans[0]<<endl;
        }else{
            ans.push_back(stoll(s, nullptr, 2));
            cout << p + 1 << endl;
        
        for (int i = 1; i < s.size(); i++) {
            string ns = s;
            if (ns[i] == '1') {
                ns[i] = '0';
                 ans.push_back(stoll(ns, nullptr, 2));
            }
           
        }

        s[0] = '0';
        ans.push_back(stoll(s, nullptr, 2));

        sort(ans.begin(), ans.end());

        for (auto val : ans) {
            cout << val << " ";
        }
        cout << endl;
        }
    }
}
