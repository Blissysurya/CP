
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


int32_t main(){

   int N;
   cin>>N;

   int x=1;
   int y=N;

   vector<int> arr;

   cout<<"? "<<x<<" "<<y<<endl;

   int sum1;
   cin>>sum1;

   y--;

   cout<<"? "<<x<<" "<<y<<endl;

   int sum2;
   cin>>sum2;

   arr.push_back(sum1-sum2);
   y--;

   int prevSum=sum2;

   while(y>1){
        
        
        cout<<"? "<<x<<" "<<y<<endl;

        int sum3;
        cin>>sum3;

        arr.push_back(prevSum-sum3);

        prevSum=sum3;
        y--;

   }

   int l=2;
   int m=N;

   cout<<"? "<<l<<" "<<m<<endl;

   int exSum;
   cin>>exSum;

   int firstEl=sum1-exSum;

   int secondEl=prevSum-firstEl;
   arr.push_back(secondEl);
   arr.push_back(firstEl);


   reverse(whole(arr));

   cout<<"! ";

   for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
   }

   cout<<endl;


    }
