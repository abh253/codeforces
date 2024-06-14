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
// #define mod 1000000007
#define inf 1e18
#define mod 998244353
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


vll fact;

void init_factFunction(ll N){
    fact=vll(N+1);
    fact[0]=1;
    For(i,1,N){
        fact[i]=i*fact[i-1];
        fact[i]%=mod;
    }
}
ll inv(ll a, ll n){
    if(a == 1) return 1;
    return (1 - inv(n % a,a) * n) / a + n;
}
ll nCr(ll n,ll r){
    if(r>n){
        return 0;
    }
    return (((fact[n]*inv(fact[n-r],mod))%mod)*inv(fact[r],mod))%mod;
}

void solve(){
    
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    s="#"+s;
    if(k==0){
        cout<<1<<endl;
        return;
    }
    init_factFunction(n+5);

    vll dp(n+1);
    dp[1]=1;

    For(i,2,n){
        ll j=i;
        ll onecnt=0;
        while(j>0){
            onecnt+=(s[j]=='1');
            if(onecnt>k){
                onecnt--;
                break;
            }
            j--;
        }
        j++;
        // err2(j,i);
        ll len=i-j+1;
        ll zerocnt=len-onecnt;

        dp[i]+=dp[i-1];
        
        if(s[i]=='0'){
            if(onecnt>0)
            dp[i]+=nCr(len-1,onecnt-1);
        }else{
            if(zerocnt>0)
            dp[i]+=nCr(len-1,zerocnt-1);
        }
        dp[i]%=mod;
    }
    // errA(dp);
    ll onecnt=0;
    For(i,1,n){if(s[i]=='1')onecnt++;}
    // cout<<onecnt<<endl;
    if(onecnt<k){
        cout<<1<<endl;
        return;
    }
    cout<<dp[n]<<endl;


    
    
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
