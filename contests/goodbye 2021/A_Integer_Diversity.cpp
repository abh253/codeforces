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
    vector<int>v(101,0);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v[abs(x)]++;
    }
    int ans=0;
    for(int i=1;i<101;i++){
        if(!v[i])continue;
        if(v[i]>1){
            ans+=2;
        }else{ans+=1;}
    }
    if(v[0])ans++;
    cout<<ans<<endl;
}
    return 0;
}