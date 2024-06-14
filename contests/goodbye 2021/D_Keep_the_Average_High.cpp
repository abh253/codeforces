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
    int x;cin>>x;

    for(int i=0;i<n;i++)v[i]-=x;


    int ans=n;
    ll sum=v[0];
    //kadane's i want sum to be the least as possibe
    for(int i=1;i<n;i++){
        if(sum>=0){
            if(v[i]>0)
            sum=v[i];
            else sum+=v[i];
        }
        else if(sum<0){
            sum+=v[i];
            if(sum<0){
                sum=0;
                ans--;
            }
        }
        
    }
    cout<<ans<<endl;

}
    return 0;
}
//-1 1 -1 1 -1 1 -1 1 -1 1
