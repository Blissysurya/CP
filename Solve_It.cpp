#include<iostream>
#include <bits/stdc++.h>
using namespace std;
double sum(double k,vector<double> &vec){
    double f= vec[0]*exp(-k)*1.0+vec[1]*1.0*sin(k)+vec[2]*cos(k)*1.0+vec[3]*1.0*tan(k)+vec[4]*k*k+vec[5];
    return f;
}
int main(){
    string line;
    while(getline(cin,line)){
        if(line.empty()){
            continue;
        }

        stringstream ss(line);
        vector<double> vec;
        int val;
        while(ss >> val){
            vec.push_back(val);
        }
        double h= vec[0]+vec[2]+vec[5];
        double hh=vec[0]*exp(-1)*1.0+vec[1]*1.0*sin(1)+vec[2]*cos(1)*1.0+vec[3]*1.0*tan(1)+vec[4]+vec[5];
        if(h*hh>0) {cout<<"No solution"<<endl;continue;}
        else if(abs(h)<1e-5) cout<<fixed<<setprecision(4)<<0.0<<endl;
        else if(abs(hh)<1e-5) cout<<fixed<<setprecision(4)<<1.0<<endl; 
        else{
            double eps=1e-7;
            double lo=0.0;
            double hi=1.0;double mid;
            if(h>0){
                while(hi-lo>eps){
                    mid=(hi+lo)/2;
                    if(sum(mid,vec)>0){
                        lo=mid;
                    }
                    else{
                        hi=mid;
                    }
                }
                cout<<fixed<<setprecision(4)<<lo<<endl;
            }
            else{
                while(hi-lo>eps){
                    mid=(hi+lo)/2;
                    if(sum(mid,vec)<0){
                        lo=mid;
                    }
                    else{
                        hi=mid;
                    }
                }
                cout<<fixed<<setprecision(4)<<lo<<endl;
                
            }
        }
        
    }



    return 0;
}