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
    
    unordered_map<ll,ll>l_min;
    unordered_map<ll,ll>r_min;
    unordered_map<ll,unordered_map<ll,ll>>both;
    ll minL=INT_MAX;
    ll maxR=-1;

    FOR(i,n){
        if(v[i][0]<minL){
            minL=v[i][0];
            l_min[v[i][0]]=v[i][2];
        }else if(v[i][0]==minL and l_min[v[i][0]]>v[i][2]){
            l_min[v[i][0]]=v[i][2];
        }
        if(v[i][1]>maxR){
            maxR=v[i][1];
            r_min[v[i][1]]=v[i][2];
        }else if(v[i][1]==maxR and r_min[v[i][1]]>v[i][2]){
            r_min[v[i][1]]=v[i][2];
        }

        if(v[i][0]<=minL and v[i][1]>=maxR){
            if(both.count(v[i][0]) and both[v[i][0]].count(v[i][1])){
                both[v[i][0]][v[i][1]]=min(v[i][2],both[v[i][0]][v[i][1]]);
            }
            else {
                both[v[i][0]][v[i][1]]=v[i][2];
            }
            
        }
        
        if(both.count(minL) and both[minL].count(maxR)){
            cout<<min(r_min[maxR]+l_min[minL],both[minL][maxR])<<endl;
        }else{
            cout<<r_min[maxR]+l_min[minL]<<endl;
        }

    }
    
}
    return 0;
}