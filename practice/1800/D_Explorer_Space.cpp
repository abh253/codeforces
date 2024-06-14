
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
unordered_map<int,unordered_map<int,int>>edges;

int dp[501][501][11];
vector<int>dir={0,-1,0,1,0};
int dfs(int i,int j,int k,int n,int m){
    if(k==0)return 0;

    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    int ans=INT_MAX;
    for(int x=0;x<4;x++){
        int ni=i+dir[x];
        int nj=j+dir[x+1];

        if(ni>=0 and nj>=0 and ni<n and nj<m)
        ans=min(ans,edges[m*i+j][m*ni+nj]+dfs(ni,nj,k-1,n,m));
        
    }
    return dp[i][j][k]=ans;
}

void solve(){
    
    int n,m,k;cin>>n>>m>>k;

    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            ll x;cin>>x;
            edges[m*i+j][m*i+j+1]=x;
            edges[m*i+j+1][m*i+j]=x;
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            ll x;cin>>x;
            edges[m*i+j][m*(i+1)+j]=x;
            edges[m*(i+1)+j][m*i+j]=x;
        }
    }
    if(k%2){
        FOR(i,n){
            FOR(j,m){
                cout<<-1<<" ";
            }
            cout<<endl;
        }
    }
    else{


        memset(dp,-1,sizeof(dp));

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m-1;j++){
        //         cout<<edges[{i,j,i,j+1}]<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(int i=0;i<n-1;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<edges[{i,j,i+1,j}]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dfs(i,j,k/2,n,m)*2<<" ";
                // dfs(i,j,2,n,m);
            }
            cout<<endl;
        }

        // FOR(i,n){
        //     FOR(j,m){
        //         cout<<dp[i][j][2]<<" ";
        //     }
        //     cout<<endl;
        // }
        



    }
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll testcase;
	// cin>>testcase;
    testcase=1;
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