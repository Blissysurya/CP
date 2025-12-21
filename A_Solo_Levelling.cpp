#include <bits/stdc++.h>


using namespace std;
#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector <int> vec(n);
    for (int i=0; i<n; i++){
    	cin>>vec[i];
    }
    if (vec[0]>=vec[1]){
    	if (vec[0]%2==0 && vec[1]%2!=0) {
    		cout<<1<<endl;
    		cout<<2<<" "<<2<<" "<<2<<endl;
    	}
    	else if (vec[0]%2!=0 && vec[1]%2==0){
    		cout<<2<<endl;
    		cout<<1<<" "<<2<<" "<<1<<endl;
    		cout<<2<<" "<<2<<" "<<2<<endl;
    	}
    	else if (vec[0]%2==0 && vec[1]%2==0) {
    		cout<<3<<endl;
    		cout<<1<<" "<<1<<" "<<1<<endl;
    		cout<<1<<" "<<2<<" "<<1<<endl;
    		cout<<2<<" "<<2<<" "<<2<<endl;
    	}
    	else if (vec[0]%2!=0 && vec[1]%2!=0){
    		cout<<2<<endl;
    		cout<<1<<" "<<1<<" "<<1<<endl;
    		cout<<2<<" "<<2<<" "<<2<<endl;
    	}
    }
    else cout<<0<<endl;
return 0;
}