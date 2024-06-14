
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
#define mod2 998244353
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
// ll build(int v,int tl,int tr,vll &t,vll &a){
//     if(tl==tr){
//       return;  t[v]=a[tl];
        
//     }

//     ll tm=(tl+tr)/2;

//     return t[v]=build(2*v+1,tl,tm,t,a)+build(2*v+2,tm+1,tr,t,a);

// }
// ll sum(int v,int l,int r,int tl,int tr,vll &t){
//     if(l>r)return 0;
//     if(l==tl and r==tr){
//         return t[v];
//     }

//     int mid=(tl+tr)/2;

//     return sum(2*v+1,l,min(mid,r),tl,mid,t)+sum(2*v+2,max(mid+1,l),r,mid+1,tr,t);
// }


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
ll check(vll &a,vll &b){

    ll n=a.size();
    ll m=b.size();


    ll ans=0;
    vll prefix(m+1);

    ll ai=n-1;
    ll bi=m-1;
    while(ai>=0 and bi>=0){
        if(a[ai]>b[bi]){
            ai--;
        }else if(a[ai]<b[bi]){
            bi--;
        }else{
            prefix[bi]=1;
            ai--;
            bi--;
        }
    }
    rep(i,m-1,0){
        prefix[i]+=prefix[i+1];
    }
    // errA(prefix);

    ans=prefix[0];
    FOR(i,m){
        ll x=upper_bound(all(a),b[i])-a.begin();
        // x=number of boxes stacked

    
        ll y=upper_bound(all(b),b[i]-x)-b.begin();
        // cout<<i-y+1+prefix[i+1]<<endl;
        ans=max(ans,i-y+1+prefix[i+1]);


    }

    return ans;

}
void solve(){
    ll n,m;cin>>n>>m;
    vll a(n);vinput(a);
    vll b(m);vinput(b);

    vll a1;
    vll b1;
    vll a2;
    vll b2;
    
    FOR(i,n){
        if(a[i]<0){
            a1.pb(-a[i]);
        }else{
            a2.pb(a[i]);
        }
    }
    reverse(all(a1));
    FOR(i,m){
        if(b[i]<0){
            b1.pb(-b[i]);
        }else{
            b2.pb(b[i]);
        }
    }
    reverse(all(b1));
    ll ans=0;
    ans+=check(a1,b1);
    ans+=check(a2,b2);

    cout<<ans<<endl;
    
    
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll testcase=1;
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

// primes=vint(N+1);
//     for(ll i=2;i<=sqrt(N);i++){
//         if(!primes[i]){
//             for(ll j=i*i;j<=N;j+=i){
//                 primes[j]=i;
//             }
//         }
//  

//i thing i will have to got to every postion of the box and see for my self
// put last box of all the collected last box on positon b[i]
// and see how many are at 
// algorithm
// make a prefix array to know that how may from current special posion +1 to end how many are at special position
// then find upper bount to that position -1 and that is the number of boxes which are connected
// to know how may of them are at special positon find currentIndex- upper_bount(currentSpecial-count)