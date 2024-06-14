
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

// void help(int j,vector<vint>&v,vll &vand,vll &vor,int ftand,int ftor){

// }

void solve(){
    
    ll n,k;cin>>n>>k;
    vector<vint> v(n,vint(31,-1));
    vll vand;
    vll vor;
    //vand[i] has and of (i),(i+1) th index
    // vll vand={0,4,0,2,1,4};
    // vll vor={7,6,6,3,7,5};
    FOR(i,n-1){
        cout<<"and "<<(i+1)<<" "<<(i+2)<<endl;
        ll x;cin>>x;
        vand.pb(x);
    }
    FOR(i,n-1){
        cout<<"or "<<(i+1)<<" "<<(i+2)<<endl;
        ll x;cin>>x;
        vor.pb(x);
    }
    ll ftand,ftor;//first and thrid number and,or
    cout<<"and "<<(1)<<" "<<(3)<<endl;
    cin>>ftand;
    cout<<"or "<<(1)<<" "<<(3)<<endl;
    cin>>ftor;
    for(int j=30;j>=0;j--){//bit
        bool flag=0;
        for(int i=n-2;i>=0;i--){
            int andbit=vand[i]&(1<<j);
            int orbit=vor[i]&(1<<j);

            if(andbit==orbit){
                v[i][j]=andbit?1:0;
                v[i+1][j]=v[i][j];
                flag=1;
            }
            else{
                v[i][j]=v[i+1][j]!=-1?!v[i+1][j]:-1;
            }
        }
        if(flag==0){
            //all -1
            int ftandj=ftand&(1<<j);
            v[0][j]=ftandj?1:0;
            for(int i=1;i<n;i++){
                v[i][j]=!v[i-1][j];
            }    

        }else{
            for(int i=0;i<n;i++){
                if(v[i][j]==-1){
                    v[i][j]=!v[i-1][j];
                }
            }
        }
       
    }

    vll arr;
    for(int i=0;i<n;i++){
        arr.pb(0);
        for(int j=0;j<31;j++){
            if(v[i][j]==1)
            arr[i]+=(1<<j);
        }
    
    }
    sort(all(arr));
   
    cout<<"finish "<<arr[k-1]<<endl;
    
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
// 32784 38 128638 108086 8192 61528

//first i thought knowing info about adjacent number in the array
// like which bit of them is same and which is different 
//if the jth bit is same i would know if it's 0 or 1
// but complication lies where they are different 
//if there is atleast one pair of adjacent number which are same int bit
//otherwise itwill be 010101... or 10101... and i can use and and or of first and third number