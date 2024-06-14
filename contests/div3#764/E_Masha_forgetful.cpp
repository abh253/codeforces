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
#define ff first
#define ss second
#define um unordered_map
#define pb push_back
#define pll pair<ll,ll>
#define mone cout<<-1<<endl;
#define nl cout<<endl;
#define all(x) x.begin(),x.end()
#define INF 1000000000000000000
const ll mx = 1e6;
ll power(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    if (b & 1)
        return (a % m * power((a % m * a % m) % m, (b - 1) / 2, m) % m) % m;
    return power((a % m * a % m) % m, b / 2, m) % m;
}
bool prime(ll n)
{
    if (n == 2)
        return true;
    if (n % 2 == 0 || n == 1)
        return false;
    for (ll i = 3; (i * i) <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll testcase;
cin>>testcase;
while(testcase--){
    ll n,m;cin>>n>>m;

    vector<string>know(n);
    FOR(i,n)cin>>know[i];
    string toRem;
    cin>>toRem;
    unordered_map<char,vector<int>>mp;
    FOR(i,toRem.length()){
        mp[toRem[i]].pb(i);
    }
    
                    //index 0 to m
    vector<pair<int,int>>v(m+1,{0,0});
    vint vcheck(m+2,0);


    FOR(i,n){
        FOR(j,m){
            int jIn=j;

            if(mp.count(know[i][j])){

                for(auto it:mp[know[i][j]]){
                    string x;
                    int i_torem=it;
                    while(i_torem<toRem.length() and j<m and know[i][j]==toRem[i_torem]){
                        x+=toRem[i_torem];
                        j++;
                        i_torem++;
                    }
    
                    if(x.length()>=2){
                        if(v[jIn+1].ff==0 or v[jIn+1].ff<j){
                            v[jIn+1]={j,i+1};
                        }
                        vcheck[it+1]++;
                        vcheck[i_torem+1]--;
                    }
                    // if(x.length()>=1)j--;
                    j=jIn;

                }
            }
        }
    }
    int count=0;
    For(i,1,m){
        if(v[i].ff!=0){
            count++;
        }
    }
    
    // for(auto it:vcheck)cout<<it<<" ";
    bool flag=0;
    For(i,1,m){
        vcheck[i]+=vcheck[i-1];
        if(vcheck[i]==0){
            mone
            flag=1;
            break;
        }
    }
    if(flag)continue;
    cout<<count<<endl;
    For(i,1,m){
        if(v[i].ff!=0){
            cout<<i<<" "<<v[i].ff<<" "<<v[i].ss<<endl;
        }
    }


    
}
    return 0;
}