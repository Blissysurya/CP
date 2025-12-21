
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
        int32_t main(){
            
            int n,k;
            cin>>n>>k;

            vi vec(n);
            cin>>vec;

            multiset<int> ms1;
            multiset<int> ms2;


            auto balance = [&](){
                if(ms1.size() > ms2.size() + 1){
                    ms2.insert(*ms1.rbegin());
                    ms1.erase(ms1.find(*ms1.rbegin()));
                }

                if(ms2.size() > ms1.size()){
                    ms1.insert(*ms2.begin());
                    ms2.erase(ms2.find(*ms2.begin()));
                }
            };

         

            for(int i=0;i<n;i++){

                if(ms1.empty() || vec[i] <= *ms1.rbegin()){
                        ms1.insert(vec[i]);
                }else{
                        ms2.insert(vec[i]);
                }
                
                balance();


                
                if(i>=k){
                    if(vec[i-k] <= *ms1.rbegin()){
                        ms1.erase(ms1.find(vec[i-k]));
                    }else{
                        ms2.erase(ms2.find(vec[i-k]));
                    }

                    balance();
                
                  
                }

                if(i>=k-1){
                      if(k%2!=0){
                        cout<<*ms1.rbegin()<<" ";
                    }else{
                        cout<<min(*ms1.rbegin(),*ms2.begin())<<" ";
                    }
                }
                
            }   
        


            
            }
