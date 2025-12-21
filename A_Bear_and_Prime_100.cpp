
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
// #define pb push_back

// vector<bool> prime(MAXV, true);
// void Sieve(int n)
// {
//   for (int p = 2; p * p <= n; p++) {

//         if (prime[p] == true) {
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     }
// }

// int32_t main(){
    
//         Sieve(100);
//         int count=0;
//         bool poss=false;
//         bool sec=false;
//         vector<int> squares={4,9,16,25,49};

//         // for(auto it: squares){
//         //     cout<<it<<endl;
//         //     string y;
//         //     cin>>y;

//         //     if(y=="yes"){
//         //         cout<<"composite"<<endl;
//         //         sec=true;
//         //         break;
//         //     }
//         // }


//         if(!sec){

//         for(int i=2;i<=47;i++){
//             if(!prime[i]){continue;}

//             cout<<i<<endl;
//             string x;   cin>>x;
//             if(x=="yes"){
//                 count++;
//             }
//             if(i*i<=100){
//                 cout<<i*i<<endl;
//                 cin>>x;
//                 if(x=="yes"){
//                     count+=2;
//                 }
//             } 


//             if(count>=2){
//                 cout<<"composite"<<endl;
                
//                 poss=true;
//                 count++;
//                 break;
//                 }
            

//         }

        
//         if(!poss){
//             cout<<"prime"<<endl;
//         }
//     }
//     }

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

int32_t main(){

        Sieve(100);
        int count=0;
        for(int i=2;i<50;i++){
            if(!prime[i])   continue;
            cout<<i<<endl;
            string x;   cin>>x;
            if(x=="yes"){
                count++;
            }
            if(i*i<=100){
                cout<<i*i<<endl;
                cin>>x;
                if(x=="yes"){
                    count+=2;
                }
            }
        }
        if(count<=1){
            cout<<"prime"<<endl;
        }
        else{
            cout<<"composite"<<endl;
        }

    }