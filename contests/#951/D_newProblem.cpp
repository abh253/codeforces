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

ll power(ll a, ll b, ll m)
{	if(a<0){
		return 0;
	}
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
// vll fact;

// void init_factFunction(ll N){
//     fact=vll(N+1);
//     fact[0]=1;
//     For(i,1,N){
//         fact[i]=i*fact[i-1];
//         fact[i]%=mod;
//     }
// }
// ll nCr(ll n,ll r){
//     if(r>n){
//         return 0;
//     }
//     return (((fact[n]*inv(fact[n-r],mod))%mod)*inv(fact[r],mod))%mod;
// }

// bool sortthis(pll &a, pll &b)
// {
// 	if (a.first == b.first)
// 		return a.second < b.second;
// 	return (a.first > b.first);
// }
// bool prime(ll n)
// {
// 	if (n == 2)
// 		return true;
// 	if (n % 2 == 0 || n == 1)
// 		return false;
// 	for (ll i = 3; (i * i) <= n; i += 2)
// 	{
// 		if (n % i == 0)
// 			return false;
// 	}
// 	return true;
// }
//DSU functions
// ll findParent(ll v, vector<ll> &Parent)
// {
//     if (Parent[v] == v)
//         return v; // parent found
//     ll ans = findParent(Parent[v], Parent);
//     return Parent[v] = ans; // path-compression
// }
 
// bool Union(ll u, ll v, vector<ll> &Size, vector<ll> &parent)
// {
//     u = findParent(u, parent), v = findParent(v, parent);
//     if (u == v)
//     {
//         return true;
//     }

//     if (Size[u] < Size[v])
//             swap(u, v);
//         parent[v] = u;
//         Size[u] += Size[v];
    
//         return false;
// }

// string functions
class hashString{

    vector<pll> prefix;
    vector<pll>prefixinv;
    vector<pll> pp;
    vector<pll> ppi;
    public:
    pll p={31,53};
    pll BASE={1e9+7,998244353};
    hashString(string &s){
        ll n=s.length();
        prefix=vector<pll>(n+1);
        prefixinv=vector<pll>(n+1);
        pp=vector<pll>(n);
        ppi=vector<pll>(n);

        pll curhash={0,0};
        pll curhashinv={0,0};
        pp[0].ff=1;
        pp[0].ss=1;
        for(int i=0;i<n;i++){
            if(i>0){
                pp[i].ff=(p.ff*pp[i-1].ff)%BASE.ff;
                pp[i].ss=(p.ss*pp[i-1].ss)%BASE.ss;
            }
            ppi[i].ff=inverse(pp[i].ff,BASE.ff);
            ppi[i].ss=inverse(pp[i].ss,BASE.ss);
            curhash.ff=(curhash.ff+(s[i]-'0'+1)*pp[i].ff)%BASE.ff;
            curhash.ss=(curhash.ss+(s[i]-'0'+1)*pp[i].ss)%BASE.ss;

            curhashinv.ff=(curhashinv.ff+(!(s[i]-'0')+1)*pp[i].ff)%BASE.ff;
            curhashinv.ss=(curhashinv.ss+(!(s[i]-'0')+1)*pp[i].ss)%BASE.ss;
            prefix[i+1]=curhash;
            prefixinv[i+1]=curhashinv;
        }
    }
    pll get(ll start,ll end){
        if(start>end)return {0,0};
        pll ans={0,0};
        ans.ff=((prefix[end+1].ff-prefix[start].ff+BASE.ff)%BASE.ff * ppi[start].ff )%BASE.ff;
        ans.ss=((prefix[end+1].ss-prefix[start].ss+BASE.ss)%BASE.ss * ppi[start].ss )%BASE.ss;
        
        return ans;
    }

    pll getinv(ll start,ll end){
        if(start>end)return {0,0};
        pll ans={0,0};
        ans.ff=((prefixinv[end+1].ff-prefixinv[start].ff+BASE.ff)%BASE.ff * ppi[start].ff )%BASE.ff;
        ans.ss=((prefixinv[end+1].ss-prefixinv[start].ss+BASE.ss)%BASE.ss * ppi[start].ss )%BASE.ss;
        
        return ans;

    }
};


void populatedp(string &s,ll k ,vll&dp){

    ll n=s.length();
    dp=vll(n);
    rep(i,n-1,0){
        if(i+k>=n) dp[i]=1;
        else dp[i]=(s[i]!=s[i+k]) and dp[i+k] and dp[i+1];
    }
}


void solve(){
    
    ll n,k;cin>>n>>k;
    // vll v(n);vinput(v);
    string s;cin>>s;
    string t=s;reverse(all(t));
    hashString hashs(s);
    hashString hasht(t);

    vll dp1,dp2;
    populatedp(s,k,dp1);
    populatedp(t,k,dp2);

    // errA(dp1);
    // errA(dp2);
    
    if(dp1[0]){
        cout<<n<<endl;
        return;
    }

    For(i,1,n-1){
        if(dp1[i] and dp2[n-i]){
            
            ll r1=n-1;
            ll l1=max(n-k,i);
            ll l2=n-i;
            ll r2=min(n-i+k-1,n-1);
            ll len=min(r1-l1+1,r2-l2+1);
            
            r1=min(r1,l1+len-1);
            r2=min(n-i+len-1,r2);
            // cout<<s.substr(l1,r1-l1+1)<<endl;
            // cout<<t.substr(l2,r2-l2+1)<<endl;


            if(hashs.getinv(l1,r1)==hasht.get(l2,r2)){
                cout<<i<<endl;
                return;
            }
        }
    }

    mone;
    
    
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll testcase=1;
	cin>>testcase;
	while(testcase-->0){
		solve();
	}
}

// okay did a mistake but it can be a new problem
// where condition s1=s2=.. sk not need to be true;