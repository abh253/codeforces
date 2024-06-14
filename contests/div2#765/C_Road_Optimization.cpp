#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<"\n";
#define err1(a) cout<<a<<"\n"
#define err2(a,b) cout<<a<<" "<<b<<"\n"
#define err3(a,b,c) cout<<a<<" "<<<<b<<" "<<c<<"\n"
#define err4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"
#define vint vector<int>
#define vl vector<long>
#define vll vector<long long>
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

ll solve(ll idx,ll lastIdx,ll signC,ll min_signC,ll &len,vector<pll>&v,vector<vll>&dp){
    if(signC>=min_signC and idx==v.size()){
        return ((len-v[lastIdx].ff)*v[lastIdx].ss);
    }
    if(idx>=v.size()){
        return INT_MAX;
    }
    if(dp[lastIdx][signC]!=-1){
        return dp[lastIdx][signC];
    }

    return dp[lastIdx][signC]=min((v[idx].ff-v[lastIdx].ff)*v[lastIdx].ss+solve(idx+1,idx,signC+1,min_signC,len,v,dp),
                        solve(idx+1,lastIdx,signC,min_signC,len,v,dp));

}
ll solve_dp(vector<pll>&v,ll k,ll l){
	ll n=v.size();
	vector<vector<ll>>dp(n,vector<ll>(k+1,INT_MAX));
	//k=max remove
	for(int i=1;i<n;i++){// ith signal
		for(int j=0;j<=k;j++){//max no of removals
			for(int a=i-1;a>=0;a--){
				int lastj=j-(i-a-1);
				if(lastj>=0){
				// cout<<"hello"<<endl;
				dp[i][j]=min((v[i].ff-v[a].ff)*v[a].ss+dp[a][lastj],dp[i][j]);

				}
			}

		}
	}
	ll ans=INT_MAX	;
	for(int i=1;i<n;i++){
		for(int j=0;j<=k;j++){
			ans=min(ans,dp[i][j]);
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

return ans;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		ll n,l,k;cin>>n>>l>>k;

        vector<pll>v(n);
        FOR(i,n)cin>>v[i].ff;
        FOR(i,n)cin>>v[i].ss;
        // min_signs=n-k;
        // max_sign=n
        //i can skip maximum k signs
        ll ans=1000000000;
        // vector<vll>dp(n+1,vll(n+1,-1));
        // ans=solve(1,0,1,n-k,l,v,dp);


		//dp part
		v.pb({l,0});

		ans=solve_dp(v,k,l);
		

        cout<<ans<<endl;
}