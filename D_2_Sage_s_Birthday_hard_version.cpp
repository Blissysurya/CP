
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
    
        istream& operator>>(istream& in, vi& vec) {
            for (auto& element : vec) {
                in >> element;
            }
            return in;
        }

        int n;
        vector<int> arr;
        vector<bool> marked(n,false);
        bool check(int mid, vector<int>& vec){
            int n=vec.size();
            arr.resize(2*mid+1);
            marked.assign(n,false);
            int k=1;
            for(int i=0;i<mid;i++,k+=2){
                arr[k]=vec[i];
                marked[i]=true;
            }

            k=0;

            for(int i=n-mid-1 ;i < n ;i++,k+=2){
                    arr[k]=vec[i];
                    marked[i]=true;
            }


            bool poss=true;

            for(int i=1;i<arr.size()-1;i+=2){
                if(arr[i]>=arr[i-1] || arr[i]>=arr[i+1]){
                    poss=false;
                    break;
                }
            }

            return poss;
            
        }

        int32_t main(){
            
            cin>>n;

            vi vec(n);
            cin>>vec;

            sort(whole(vec));

            int low=0;
            int high=ceil((n*1.0)/(2*1.0))-1;
            int ans=-1;

            while(low<=high){
                int mid= (low+high)/2;

                if(check(mid,vec)){
                    low=mid+1;
                    ans=mid;
                }else{
                    high=mid-1;
                }

            }


            cout<<ans<<endl;
            
            for(int i=0;i<n;i++){
                if(!marked[i]){
                    arr.push_back(vec[i]);
                }
            }

            for(auto& it : arr){
                cout<<it<<" ";
            }
            


            }
