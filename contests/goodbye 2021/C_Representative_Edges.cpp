#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define ll long long
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll testcase;
cin>>testcase;
while(testcase--){
    ll n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    int mlinear=0;//max no.s which are present in linear incr. or dec.
    for(int i=0;i<n;i++){
        unordered_map<double,int>mp;
        int localMax=0;
        for(int j=0;j<n;j++){
            if(i==j)continue;
            double diff;
            if(j<i){
                diff=(v[i]-v[j])/((i-j)*1.0);
                mp[diff]++;
            }else{
                diff=(v[j]-v[i])/((j-i)*1.0);
                mp[diff]++;
            }
            localMax=max(localMax,mp[diff]);       
        }
        mlinear=max(mlinear,localMax);
    }
    
    cout<<n-mlinear-1<<endl;
       
}
    return 0;
}