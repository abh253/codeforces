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
bool check(ll x,vector<int>&alp,ll k){

    int currK=0;
    int pairneed=(x/2)*k;
    int singleneed=(x%2)*k;
    int paircount=0;
    int singlecount=0;

    for(int i=0;i<26;i++){
            paircount+=(alp[i]/2);
            if(alp[i]%2){
                singlecount++;
            }            
    }

    if(pairneed<=paircount){
        singlecount+=((paircount-pairneed)*2);
        if(singlecount>=singleneed){
            return 1;
        }
    }
    return 0;

}
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll testcase;
cin>>testcase;
while(testcase--){
    ll n,k;cin>>n>>k;
    vector<int>alp(26,0);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        alp[s[i]-'a']++;
    }

    ll l=1,r=n/k;
    int ans=1;
    while(l<=r){
        ll x=(l+r)/2;
        if(check(x,alp,k)){
            l=x+1;
            ans=x;
        }else r=x-1;
    }
    cout<<ans<<endl;
}
    return 0;
}