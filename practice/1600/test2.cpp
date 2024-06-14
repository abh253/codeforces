#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<"\n";
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
#define vint vector<int>
#define vl vector<long>
#define vll vector<long long>
#define um unordered_map
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
#define mone cout<<-1<<endl;
#define nl cout<<endl;
#define all(x) x.begin(),x.end()
#define INF 1000000000000000000
const ll mx = 1e6;
ll power(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    if (b & 1)
        return (a % m * power((a % m * a % m) % m, (b - 1) / 2, m) % m) % m;
    return power((a % m * a % m) % m, b / 2, m) % m;
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
bool logic(pair<ll,ll>a,pair<ll,ll>b){
    return (a.ss-a.ff)<(b.ss-b.ff);
}

 bool check(ll x,int m,vector<int>&nums){
        
        ll cursum=0;
        
        for(int i=0;i<nums.size();i++){
            
            if(cursum+nums[i]<=x){
                
                cursum+=nums[i];
                
            }else{
                
                if(nums[i]>x)return 0;
                cursum=nums[i];
                m--;
                
            }
        }
        return m>=1;
        
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        ll l=0,r=50000000;
        ll ans=r;
        while(l<=r){
            ll mid=(l+r)/2;
            
            if(check(mid,m,nums)){
                r=mid-1;
                ans=mid;
                cout<<mid<<endl;
            }
            else l=mid+1;
        }
        
        return ans;
        
    }
 long long numberOfWays(string s) {
        int n=s.length();
        vector<int>oneleft(n);
        vector<int>oneRight(n);
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                oneRight[i]=1;
            }
            if(i<n-1)oneRight[i]+=oneRight[i+1];
        }
        if(s[0]=='1'){
            oneleft[0]=1;
        }
        long long ans=0;
        
        
        for(int i=1;i<n-1;i++){
            if(s[i]=='1'){
                oneleft[i]=1;
                oneleft[i]+=oneleft[i-1];
            }
            long long ol=oneleft[i-1];
            long long onr=oneRight[i+1];
            long long zl=i-ol;
            long long zr=n-i-1-onr;
            if(s[i]=='1'){
                ans+=zl*zr;
            }else{
                ans+=ol*onr;
            }
        }
        errA(oneleft);
        errA(oneRight);
        
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N,vector<int>(N));
        
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++){
        //         if(i+1==j){
        //             dp[i][j]=0;
        //         }
        //     }
        // }
        for(int i=2;i<=N;i++){
            for(int l=0;l<N-i+1;l++){
                
                int r=l+i-1;
                dp[l][r]=INT_MAX;
                if(l+1==r){
                    dp[l][r]=0;
                }
                else
                for(int k=l+1;k<r;k++){
                    dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]+arr[l]*arr[k]*arr[r]);
                }
                
                
            }
        }
        FOR(i,N){
            errA(dp[i]);
        }
        return dp[0][N-1];
    }
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int>v={7,2,5,10,8};
    int arr[]={10,30,5,60};
    matrixMultiplication(4,arr);
    // search(v,0);
    // vector<pll>v={{1,3},{1,5}};
    // splitArray(v,2);
    // numberOfWays("0001100100");
    return 0;
}