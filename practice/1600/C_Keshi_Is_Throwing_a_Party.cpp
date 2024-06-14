#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
#define vint vector<int>
#define vl vector<long>
#define vll vector<long long>
#define um unordered_map
#define pb push_back
#define pll pair<ll,ll>
#define mone cout<<-1<<endl;
#define nl cout<<endl;
#define all(x) x.begin(),x.end()
#define INF 1000000000000000000
const ll mx = 1e6;
bool check(int x,vector<vector<int>>&v){

    int cx=x;
    for(int i=0;i<v.size();i++){
        if(v[i][0]>=(cx-1) and v[i][1]>=(x-cx))cx--;
        if(!cx)return 1;
    }
    return !cx;
}
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll testcase;
cin>>testcase;
while(testcase--){
    ll n;cin>>n;
    vector<vector<int>>v(n,vector<int>(2));
    FOR(i,n){
        cin>>v[i][0]>>v[i][1];
    }
    
    ll l=1,r=n;
    ll ans=1;
    while(l<=r){
       ll mid=(l+r)/2;

        if(check(mid,v)){
            ans=max(mid,ans);
            l=mid+1;
        }else{
            r=mid-1;
        }

    }
    cout<<ans<<endl;
}
    return 0;
}