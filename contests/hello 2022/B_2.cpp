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
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll testcase;
cin>>testcase;
while(testcase--){
    ll n;cin>>n;
    vector<vector<ll>>v(n,vector<ll>(3));
    FOR(i,n){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    
    ll l_price=INT_MAX;
    ll r_price=INT_MAX;
    pair<ll,ll>both={-1,-1};
    ll b_price=INT_MAX;
    ll minL=INT_MAX;
    ll maxR=-1;

    FOR(i,n){
        if(v[i][0]<minL){
            minL=v[i][0];
            l_price=v[i][2];
        }else if(v[i][0]==minL and l_price>v[i][2]){
            l_price=v[i][2];
        }
        if(v[i][1]>maxR){
            maxR=v[i][1];
            r_price=v[i][2];
        }else if(v[i][1]==maxR and r_price>v[i][2]){
            r_price=v[i][2];
        }

        if(v[i][0]==minL and v[i][1]==maxR){
                if(both.first==minL and both.second==maxR){
                    b_price=min(v[i][2],b_price);
                }else{
                    both={minL,maxR};
                    b_price=v[i][2];
                }
        }
        
        if(both.first==minL and both.second==maxR){
            cout<<min(r_price+l_price,b_price)<<endl;
        }else{
            cout<<r_price+l_price<<endl;
        }

    }
    
}
    return 0;
}