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

vector<vector<char>> solve(ll n,ll k){
    vector<vector<char>>v;
    // vector<int>row(n,0);
    vector<int>col(n,0);
    if(k>(n+1)/2)return v;
    vector<vector<char>>current(n,vector<char>(n,'.'));
    v=current;
    int count=0;
    for(int i=0;i<n;i+=2){
            v[i][i]='R';
            count++;
            if(count==k)break;
    }

    return v;
    
}

int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll testcase;
cin>>testcase;
while(testcase--){
    ll n,k;cin>>n>>k;

    vector<vector<char>>v=solve(n,k);
    if(v.size()==0){cout<<-1<<endl;continue;}
    FOR(i,n){
        FOR(j,n){
            cout<<v[i][j];
        }
        nl
    }

}
    return 0;
}