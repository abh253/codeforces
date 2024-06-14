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

// //fenwick tree
// // the queries are also 1 indexed
// void bitConstruction(vector<ll>&BIT,vll&a){
//     if(BIT.size()!=a.size()+1)BIT=vll(a.size()+1);
//     for(int i=0;i<a.size();i++){
//         BIT[i+1]+=a[i];
//         int x=i+1;
//         int par=x+(x&-x);
//         if(par<BIT.size())BIT[par]+=a[i];
//     }
// }
// // give the prefix sum from a[0 to index-1];
// ll bitSum(vector<ll> &BITree, ll index)
// {
//     ll sum = 0;
//     index = index;
//     while (index > 0)
//     {
//         sum += BITree[index];
//         index -= index & (-index);
//     }
//     return sum;
// }

// void bitUpdate(vector<ll> &BITree, ll index, ll val)
// {
//     index = index;
//     while (index <= BITree.size())
//     {
//         BITree[index] += val;
//         index += index & (-index);
//     }
// }
// // range update and range query
// void range_add(vll &BIT1,vll &BIT2,ll l,ll r,ll x){
//     bitUpdate(BIT1, l, x)
//     bitUpdate(BIT1, r+1, -x)
//     bitUpdate(BIT2, l, x*(l-1))
//     bitUpdate(BIT2, r+1, -x*r)
// }

// ll prefix_sum(vll &BIT1,vll &BIT2,ll idx){
//     return bitSum(BIT1,idx)*idx-bitSum(BIT2,idx);
// }

// ll range_sum(vll &BIT1,vll &BIT2,ll l,ll r){
//     return prefix_sum(BIT1,BIT2,r)-prefix_sum(BIT1,BIT2,l-1);
// }
// // fenwick tree ends

// bitmasking
// int count_one(ll n) {
//     int count=0;
//     while(n) {
//         n = n&(n-1);
//         count++;
//     }
//     return count;
// }

// int most_s_bit(ll n,ll bit){
//     //bit is number of bits to look for
//     for(int i=bit-1;i>=0;i--){
//         if((n&1LL<<i)!=0)return i;
//     }
//     return -1;
// }

// int least_s_bit(ll n,ll bit){
//     for(int i=0;i<bit;i++){
//         if((n&1LL<<i)!=0)return i;
//     }
//     return -1;
// }

// binarylifting starts
// vector<vector<ll>>up;
// vll depth;
// ll LOG=20;
// void init_bl(ll n){
//     up=vector<vector<ll>>(n,vll(LOG));
//     depth=vll(n);
// }
// void bl_dfs(int i,int p,vector<vll>&t){
//     up[i][0]=p==-1?0:p;
//     for(int x=1;x<LOG;x++){
//         up[i][x]=up[up[i][x-1]][x-1];
//     }
//     for(auto j:t[i]){
//         if(j==p)continue;
//         depth[j]=depth[i]+1;
//         bl_dfs(j,i,t);
//     }
// }

// ll lca(ll a,ll b){
//     if(depth[b]>depth[a])swap(a,b);

//     ll k=depth[a]-depth[b];
//     // cout<<k<<endl;
//     for(int i=0;i<LOG;i++){
//         if(k & (1<<i)){
//             a=up[a][i];
//         }
//     }
//     // err2(a,b);
//     if(a==b)return a;
//     // in this case we can not do reverse
//     // because that won't mzximise the lifting
//     for(int i=LOG-1;i>=0;i--){
//     // for(int i=0;i<LOG;i++){
//         if(up[a][i]!=up[b][i]){
//             a=up[a][i];
//             b=up[b][i];
//         }
//     }
//     // errA(up[9]);
//     return up[a][0];

// }
// ll distance_vertex(ll a,ll b){
//     ll l1=lca(a,b);

//     ll ans=depth[a]+depth[b]-2*depth[l1];
//     return ans;
// }
// binarylifting ends;

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
// class hashString{

//     vector<pll> prefix;
//     vector<pll> pp;
//     vector<pll> ppi;
//     public:
//     pll p={31,53};
//     pll BASE={1e9+7,998244353};
//     hashString(string &s){
//         ll n=s.length();
//         prefix=vector<pll>(n+1);
//         pp=vector<pll>(n);
//         ppi=vector<pll>(n);

//         pll curhash={0,0};
//         pp[0].ff=1;
//         pp[0].ss=1;
//         for(int i=0;i<n;i++){
//             if(i>0){
//                 pp[i].ff=(p.ff*pp[i-1].ff)%BASE.ff;
//                 pp[i].ss=(p.ss*pp[i-1].ss)%BASE.ss;
//             }
//             ppi[i].ff=inverse(pp[i].ff,BASE.ff);
//             ppi[i].ss=inverse(pp[i].ss,BASE.ss);
//             curhash.ff=(curhash.ff+(s[i]-'a'+1)*pp[i].ff)%BASE.ff;
//             curhash.ss=(curhash.ss+(s[i]-'a'+1)*pp[i].ss)%BASE.ss;
//             prefix[i+1]=curhash;
//         }
//     }
//     pll get(ll start,ll end){
//         if(start>end)return {0,0};
//         pll ans={0,0};
//         ans.ff=((prefix[end+1].ff-prefix[start].ff+BASE.ff)%BASE.ff * ppi[start].ff )%BASE.ff;
//         ans.ss=((prefix[end+1].ss-prefix[start].ss+BASE.ss)%BASE.ss * ppi[start].ss )%BASE.ss;
        
//         return ans;
//     }
// };
// vector<int> prefix_function(string s) {
//     int n = (int)s.length();
//     vector<int> pi(n);
//     for (int i = 1; i < n; i++) {
//         int j = pi[i-1];
//         while (j > 0 && s[i] != s[j])
//             j = pi[j-1];
//         if (s[i] == s[j])
//             j++;
//         pi[i] = j;
//     }
//     return pi;
// }
// vector<int> z_function(string s) {
//     int n = (int) s.length();
//     vector<int> z(n);
//     for (int i = 1, l = 0, r = 0; i < n; ++i) {
//         if (i <= r)
//             z[i] = min (r - i + 1, z[i - l]);
//         while (i + z[i] < n && s[z[i]] == s[i + z[i]])
//             ++z[i];
//         if (i + z[i] - 1 > r)
//             l = i, r = i + z[i] - 1;
//     }
//     return z;
// }



void solve(){
    
    ll n;cin>>n;
    vll v(n);vinput(v);
	sort(all(v));
	ll mx3=v.back()/3;
	ll ans=mx3+2;
	For(ones,0,1){
		For(twos,0,2){
			For(threes,max(0LL,mx3-2),mx3){
				bool ok=true;
				ll coins=ones+twos+threes;

				FOR(i,n){
					bool found=false;
					For(j,0,ones){
						For(k,0,twos){
							ll left=v[i]-j-2*k;
						
							if(left>=0 and (left%3)==0 and threes>=(left/3) )found=true;
						}
					}
					if(!found)ok=false;
				}

				if(ok){
					ans=min(ans,coins);
					// err3(ones,twos,threes);
				}

			}
		}
	}
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
