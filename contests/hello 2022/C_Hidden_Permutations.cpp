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
    vector<int>v(n+1,0);
    For(i,1,n){
        if(v[i]!=0)continue;
        vector<int>zoro;
        int first;
        cout<<"? "<<i<<endl;
        cin>>first;
        int temp;
        // cout<<"? "<<i<<endl;
        temp=0;    
        while(temp!=first){
            cout<<"? "<<i<<endl;
            cin>>temp;
            zoro.pb(temp);
        }
        FOR(i,zoro.size()){
            v[zoro[i]]=zoro[(i+1)%zoro.size()];
        }
    }
    For(i,0,n){
        if(i==0){cout<<"!"<<" ";}
        else cout<<v[i]<<" ";
    }
    cout<<endl;

}
    return 0;
}   