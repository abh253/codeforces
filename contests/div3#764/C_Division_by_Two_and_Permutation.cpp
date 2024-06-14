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
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll testcase;
cin>>testcase;
while(testcase--){
    ll n;cin>>n;
    vector<int>v(n+1,0);
    bool flag=1;
    vector<int>ele(n);
    FOR(i,n){
        cin>>ele[i];
    }
    for(int i=0;i<n;i++){
        int x=ele[i];
        while(x>n){x/=2;}

        while(x!=1 and v[x]==1){
            x/=2;
        }
        if(v[x]==1){cout<<"NO"<<endl;flag=0;break;}
        v[x]=1;
    }
    if(!flag)continue;
    cout<<"YES"<<endl;
}
    return 0;
}