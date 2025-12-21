
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

        class slidingWindow{

            public:
                multiset<int> ms1;
                multiset<int> ms2;
                int leftCost;
                int rightCost;
                int k;

                slidingWindow(int k){
                    leftCost=0;
                    rightCost=0;
                    this->k=k;
                }

                void insert(int x){
                    if(ms1.empty() || x<= *ms1.rbegin()){
                        ms1.insert(x);
                        leftCost+=x;
                    }else{
                        ms2.insert(x);
                        rightCost+=x;
                    }
                }

                void adjust(){
                    if(ms1.size() > ms2.size() + 1){
                        ms2.insert(*ms1.rbegin());
                         leftCost-= *ms1.rbegin();
                         rightCost+= *ms1.rbegin();
                        ms1.erase(ms1.find(*ms1.rbegin()));
                       
                    }

                    if(ms2.size() > ms1.size()){
                        ms1.insert(*ms2.begin());
                        leftCost+= *ms2.begin();
                        rightCost-= *ms2.begin();
                        ms2.erase(ms2.find(*ms2.begin()));

                    }

                }

                int findMedian(){

                    if(k%2!=0){
                        return *ms1.rbegin();
                    }else{
                        return min(*ms1.rbegin(),*ms2.begin());
                    }

                }

                int cost(){
                    int med=findMedian();
                    return (ms1.size()*med - leftCost + rightCost - ms2.size()*med);
                }
                

                void remove(int x){
                    if(x <= *ms1.rbegin()){
                        ms1.erase(ms1.find(x));
                        leftCost-=x;

                    }else{

                        ms2.erase(ms2.find(x));
                        rightCost-=x;
                    }
                }

                

        };


        int32_t main(){
            
            int n,k;
            cin>>n>>k;

            vi vec(n);
            cin>>vec;

            slidingWindow a(k);

          

       
            for(int i=0;i<n;i++){


               a.insert(vec[i]);
               a.adjust();
 
                if(i>=k){
                    a.remove(vec[i-k]);
                    a.adjust();
                }


                
                if(i>= k-1){
                    cout<<a.cost()<<" ";
                }
  
            }   
    
            
            }
