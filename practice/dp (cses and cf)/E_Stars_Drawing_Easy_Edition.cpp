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
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll testcase;
	// cin>>testcase;
    testcase=1;
	while(testcase--){
        ll n,m;cin>>n>>m;

        vector<string>v(n);
        vinput(v);
        string zee;
        FOR(i,m){
            zee+='.';
        }
        vector<string>cpy(n,zee);
        vector<vint>dp(n,vint(m));
        ll cnt=0;
        For(i,1,n-2){
            For(j,1,m-2){

                if(v[i][j]=='.')continue;

                ll width=min(i,min(j,min(n-i-1,m-j-1)));

                ll k=1;
                while(k<=width and v[i+k][j]=='*' and v[i][j+k]=='*' and v[i-k][j]=='*' and v[i][j-k]=='*'){
                    cpy[i+k][j]='*';
                    cpy[i][j+k]='*';
                    cpy[i-k][j]='*';
                    cpy[i][j-k]='*';
                    k++;
                }
                dp[i][j]=k-1;
                if(dp[i][j])cpy[i][j]='*';
                if(dp[i][j]!=0)cnt++;
            }
        }

        bool flag=1;
        FOR(i,n){
            FOR(j,m){
                // cout<<cpy[i][j];
                if(v[i][j]!=cpy[i][j]){
                    flag=0;
                    break;
                }
            }
            // nl;
            if(!flag)break;
        }

        if(flag){
            cout<<cnt<<endl;
            FOR(i,n){
                FOR(j,m){
                    if(dp[i][j]!=0){
                        err3(i+1,j+1,dp[i][j]);
                    }
                }
            }
        }else{
            cout<<-1<<endl;
        }




	}
}