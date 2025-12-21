#include <bits/stdc++.h>
#include <numeric>
#include <functional>
using namespace std;
#define int long long 
const int MAXV = 1e7+1;
#define whole(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back


istream& operator>>(istream& in, vi& vec) {
    for (auto& element : vec) {
        in >> element;
    }
    return in;
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

vector<int> answer(1e7+1,0);

void precompute(int n){
     int ans=0;

        vector<bool> suryansh(1e7+1,false);

        for(int i=1; i*i <= n ;i++){
            for( int j=1; j*j*j*j <= n ;j++ ){
                if((i*i + j*j*j*j) <= n  &&  prime[i*i + j*j*j*j] && !suryansh[i*i + j*j*j*j]){
                    ans++;
                    suryansh[i*i + j*j*j*j]=true;
                }

                if(i*i + j*j*j*j > n){
                    break;
                }
            }
        }

        answer[]
}

int32_t main(){

    Sieve(1e7);
    

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

       
        }
    }
