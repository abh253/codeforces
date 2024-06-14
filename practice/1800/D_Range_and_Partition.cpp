
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

class TreeNode{
    public:
    ll val;
    TreeNode*left,*right;
    TreeNode(){
        val=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(ll value){
        val=value;
        left=NULL;
        right=NULL;
    }
};
ll power(ll a, ll b, ll m)
{
	if (b == 0)
		return 1;
	if (b & 1)
		return (a % m * power((a % m * a % m) % m, (b - 1) / 2, m) % m) % m;
	return power((a % m * a % m) % m, b / 2, m) % m;
}
ll fact(ll a, ll b)
{
	if (a == b)
		return 1;
	return (a % mod * fact(a - 1, b) % mod) % mod;
}
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
bool check(vll& v,ll n,ll k,ll mid,pll&ans){

    for(int i=1;i<=n-mid;i++){
        ll x=i,y=i+mid;

        ll total=n;
        ll outofRange=v[x-1]+n-v[y];

        ll range=n-outofRange;

        ll z=range-outofRange;
        if(z>=k){
            ans={x,y};
            return true;
        }

    }
    return false;

    

}
void solve(){
    
    ll n,k;cin>>n>>k;
    vll v(n);vinput(v);

    // sort(all(v));
    vll zoro(n+1);

    for(auto it:v)zoro[it]++;

    for(int i=1;i<=n;i++)zoro[i]+=zoro[i-1];
    

    ll l=0,r=n;
    pll ans={1,n};
    while(l<r){
        ll mid=(l+r)/2;

        if(check(zoro,n,k,mid,ans)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<ans.ff<<" "<<ans.ss<<endl;
    vector<vll>part;
    for(int i=0,cur=0,li=0,count=0;i<n;i++){
        if(count==k-1){
            part.pb({li+1,n});
            break;
        }

        if(v[i]>=ans.ff and v[i]<=ans.ss)cur++;
        else cur--;
        if(cur==1){
            part.pb({li+1,i+1});
            li=i+1;
            cur=0;
            count++;
        }
       
    }
    for(int i=0;i<part.size();i++){
        cout<<part[i][0]<<" "<<part[i][1]<<endl;
    }
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll testcase;
	cin>>testcase;
	while(testcase-->0){
		solve();
	}
}

// DSU
 
//  vector<ll> Size(N, 1), Parent(N, 0);
//  for (ll i = 0; i < N; i++)
//      Parent[i] = i;

//Sieve

// vector<int>primes(5000001,0);
// for(int i=2;i<=sqrt(5000000);i++){
//     if(!primes[i]){
//         for(int j=i*i;j<=5000000;j+=i){
//             primes[j]=i;
//         }
//     }
// }

// for a given [x,y] we can greedily make subarrays
//because if in [l,r] range>outrange
// and subbarray after that[l+1,x] have range<outrange and for 
//[l,r] to fullfill the condition should get elements such that in that elements range>=outrange
// and giving that wont benifit the [l+1,x] to become valid
// so for a given [x,y ] i can check if it is valid in O(n);
