#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<typename T> 
using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define inf 1e18
// #define mod 998244353
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(ll i = x; i >= y; i--)
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<"\n";
#define err1(a) cout<<a<<"\n"
#define err2(a,b) cout<<a<<" "<<b<<"\n"
#define err3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define err4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"
#define vint vector<int>
#define inp1(a) cin>>a;
#define inp2(a,b) cin>>a>>b;
#define inp3(a,b,c) cin>>a>>b>>c;
#define inp4(a,b,c,d) cin>>a>>b>>c>>d;
#define vl vector<long>
#define vll vector<long long>
#define vinput(v) FOR(i,(ll)v.size()){cin>>v[i];}
#define um unordered_map
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
#define mone cout<<-1<<"\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define nl cout<<"\n"
#define all(x) x.begin(),x.end()
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
#define INF 1000000000000000000
const ll mx = 1e6;
/*ll numinv[mx+1];
void InverseofNumber(ll p)
{
    numinv[0] = numinv[1] = 1;
    for (ll i = 2; i <= mx; i++)
        numinv[i] = numinv[mod % i] * (mod - mod / i) % mod;
}
ll fac[mx+1] = {0}, infac[mx+1] = {0};
ll comb(ll n, ll r)
{
	if(r > n)
	return 0;
	return (fac[n]%mod * infac[r]%mod * infac[n-r]%mod)%mod;
}*/


// segment tree
//// v=intial vertex put it 0 and tl=0 and tr=intial array size-1 , t will be the array where we store st
// ll build(int v,int tl,int tr,vll &t,vll &a){
//     if(tl==tr){
//       return  t[v]=a[tl];
        
//     }

//     ll tm=(tl+tr)/2;

//     return t[v]=build(2*v+1,tl,tm,t,a)+build(2*v+2,tm+1,tr,t,a);

// }
//// give v=0 and l and r  of the intial array to find sum between them ,
// //tl and tr are 0 and intial array size-1
// //ll sum(int v,int l,int r,int tl,int tr,vll &t){
//     if(l>r)return 0;
//     if(l==tl and r==tr){
//         return t[v];
//     }

//     int mid=(tl+tr)/2;

//     return sum(2*v+1,l,min(mid,r),tl,mid,t)+sum(2*v+2,max(mid+1,l),r,mid+1,tr,t);
// }

// //similarly give v=0 and pos is index where the value will change
// // tl =0 and tr=orignal array.size()-1
// void remove(int v,int pos,int new_val,int tl,int tr,vll &t){
//     if(tl==tr){
//         t[v]=new_val;
//         return;
//     }

//     ll mid=(tl+tr)/2;

//     if(pos<=mid){
//         remove(2*v+1,pos,new_val,tl,mid,t);
//     }else{
//         remove(2*v+2,pos,new_val,mid+1,tr,t);
//     }
//     t[v]=t[2*v+1]+t[2*v+2];
// }

// bitmasking
int count_one(ll n) {
    int count=0;
    while(n) {
        n = n&(n-1);
        count++;
    }
    return count;
}

int most_s_bit(ll n,ll bit){
    //bit is number of bits to look for
    for(int i=bit-1;i>=0;i--){
        if((n&1LL<<i)!=0)return i;
    }
    return -1;
}

int least_s_bit(ll n,ll bit){
    for(int i=0;i<bit;i++){
        if((n&1LL<<i)!=0)return i;
    }
    return -1;
}

ll power(ll a, ll b, ll m)
{
	if (b == 0)
		return 1;
	if (b & 1)
		return (a % m * power((a % m * a % m) % m, (b - 1) / 2, m) % m) % m;
	return power((a % m * a % m) % m, b / 2, m) % m;
}
ll factorial(ll a, ll b)
{
	if (a == b)
		return 1;
	return (a % mod * factorial(a - 1, b) % mod) % mod;
}
ll inverse(ll x,ll m){
    return power(x,m-2,m);
}
ll inv(ll a, ll n){
    if(a == 1) return 1;
    return (1 - inv(n % a,a) * n) / a + n;
}
vll fact;

void factFunction(ll N){
    fact=vll(N+1);
    fact[0]=1;
    For(i,1,N){
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
    }
}
// ll nCr(ll n,ll r){
//     if(r>n){
//         return 0;
//     }
//     return (((fact[n]*inv(fact[n-r],mod))%mod)*inv(fact[r],mod))%mod;
// }

bool sortthis(pll &a, pll &b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return (a.first > b.first);
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
//DSU functions
ll findParent(ll v, vector<ll> &Parent)
{
    if (Parent[v] == v)
        return v; // parent found
    ll ans = findParent(Parent[v], Parent);
    return Parent[v] = ans; // path-compression
}
 
bool Union(ll u, ll v, vector<ll> &Size, vector<ll> &parent)
{
    u = findParent(u, parent), v = findParent(v, parent);
    if (u == v)
    {
        return true;
    }

    if (Size[u] < Size[v])
            swap(u, v);
        parent[v] = u;
        Size[u] += Size[v];
    
        return false;
}

// string functions
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}



void solve(){
    
    // ll n;cin>>n;
    // vll v(n);vinput(v);
    string s;cin>>s;
    ll n=s.length();
    // count #01 -#10
    ll zerocnt=0;
    ll d=0;
    rep(i,n-1,0){if(s[i]=='0')zerocnt++;}
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            zerocnt--;
            d+=(n-i-1-zerocnt);
        }else{
            d-=(zerocnt);
        }
    }
    d=-(d/2);
    // cout<<d<<endl;
    // return;
    vint oneidx;
    vint zeroidx;
    oneidx.pb(-1);
    zeroidx.pb(-1);
    for(int i=0;i<n;i++){
        if(s[i]=='0'){zeroidx.pb(i);}
        else oneidx.pb(i);
    }

    ll zn=zeroidx.size();
    ll on=oneidx.size();

    // on both array we will apply dp to see what is the sum they can make when k elements are selected

    // dp1[i][k][sum];=>at ith index after choosing exact k numbers if sum is possible
    // transition
    // k<=i
    // dp1[i][k][sum]=dp[i-1][k][sum] or dp[i-1][k-1][sum-v[i]];

    vector<vector<vector<bool>>> dp1(n+1,vector<vector<bool>>(n+1,vector<bool>(6000,0)));

    dp1[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int k=0;k<=n;k++){
            // if(k>i)continue;
            for(int sum=0;sum<6000;sum++){
                dp1[i][k][sum]=dp1[i][k][sum]|dp1[i-1][k][sum];
                if(k-1>=0 and i<zn and sum-zeroidx[i]>=0)
                dp1[i][k][sum]=dp1[i][k][sum]|dp1[i-1][k-1][sum-zeroidx[i]];
            }
        }
    }

    vector<vector<vector<bool>>> dp2(n+1,vector<vector<bool>>(n+1,vector<bool>(6000,0)));
    dp2[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int k=0;k<=n;k++){
            // if(k>i)continue;
            for(int sum=0;sum<6000;sum++){

                dp2[i][k][sum]=dp2[i][k][sum]|dp2[i-1][k][sum];
                if(k-1>=0 and i<on and sum-oneidx[i]>=0)
                dp2[i][k][sum]=dp2[i][k][sum]|dp2[i-1][k-1][sum-oneidx[i]];
            }
        }

    }
    // cout<<d<<endl;
    for(int k=0;k<=n;k++){
        for(int i=0;i<6000;i++){
            if(dp1[n][k][i]){
                // cout<<i<<" ";
                if(i-d>=0 and i-d<6000 and dp2[n][k][i-d]){
                    // cout<<endl;
                    cout<<k<<endl;
                    return;
                }
            }
        }
    }
    // cout<<endl;
    cout<<-1<<endl;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll testcase=1;
	// cin>>testcase;
	while(testcase-->0){
		solve();
	}
}

//factorial
//   vll fact(N+1);
//   fact[0]=1;
//   for(int i=1;i<=N;i++){
//       fact[i]=i*fact[i-1];
//       fact[i]%=mod;
//   }

// DSU
 
//  vector<ll> Size(N, 1), Parent(N, 0);
//  for (ll i = 0; i < N; i++)
//      Parent[i] = i;

//Sieve

// primes=vint(N+1);
//     for(ll i=2;i<=sqrt(N);i++){
//         if(!primes[i]){
//             for(ll j=i*i;j<=N;j+=i){
//                 primes[j]=i;
//             }
//         }
//     }

// tree input
// vector<vll>t(n);

// FOR(i,n-1){
//     ll x,y;cin>>x>>y;
//     x--,y--;
//     t[x].pb(y);
//     t[y].pb(x);
    
// }

