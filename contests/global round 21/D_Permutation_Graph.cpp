#include<bits/stdc++.h>
using namespace std;
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
vll prmn;
vll prmx;
vll sfmn;
vll sfmx;
ll left(ll l,ll r,bool mode=0){
    if(l==r)return 0;
    if(mode==0){
        return 1+left(l,prmn[r],1);
    }else{
        return 1+left(l,prmx[r],0);
    }

}
ll right(ll l,ll r,bool mode=0){
    if(l==r)return 0;
    if(mode==0){
        return 1+right(sfmn[l],r,1);
    }else{
        return 1+right(sfmx[l],r,0);
    }
}
void solve(){
    ll n;cin>>n;vll v(n);vinput(v);
    
    prmn=vll(n);
    prmx=vll(n);
    sfmn=vll(n);
    sfmx=vll(n);
    prmn[0]=prmx[0]=0;
    ll mn,mx;
    mn=mx=v[0];
    for(int i=1;i<n;i++){
        if(v[i]>mx){prmx[i]=i;mx=v[i];}
        else prmx[i]=prmx[i-1];

        if(v[i]<mn){prmn[i]=i;mn=v[i];}
        else prmn[i]=prmn[i-1];
    }

    sfmx[n-1]=sfmn[n-1]=n-1;
    mn=mx=v[n-1];
    for(int i=n-2;i>=0;i--){
         if(v[i]>mx){sfmx[i]=i;mx=v[i];}
        else sfmx[i]=sfmx[i+1];

        if(v[i]<mn){sfmn[i]=i;mn=v[i];}
        else sfmn[i]=sfmn[i+1];
    }
    // cout<<"hello"<<endl;
    // cout<<prmx[n-1]<<endl;
    // errA(prmn);
    // errA(prmx);
    // errA(sfmn);
    // errA(sfmx);
    cout<<left(0,prmx[n-1])+right(prmx[n-1],n-1)<<endl;
    
    
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