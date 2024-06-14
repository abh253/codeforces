#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
#define vint vector<int>
#define vl vector<long>
#define vll vector<long long>
#define um unordered_map
#define pb push_back
#define pll pair<ll,ll>
#define mone cout<<-1<<endl;
#define nl cout<<endl;
#define all(x) x.begin(),x.end()
#define INF 1000000000000000000
const ll mx = 1e6;
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll testcase;
cin>>testcase;
while(testcase--){
    ll n,m;cin>>n>>m;
    string s;
    cin>>s;
    ll sR=1,sC=1,cR=1,cC=1;
    ll ux=1,lx=1,rx=1,dx=1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='R'){
            if(cC+1>m){
                if(sC-1>=1 and lx!=1){
                    lx--;
                    rx--;
                    sC--;
                }else break;
            }
            else cC++;
        }
        else if(s[i]=='D'){
            if(cR+1>n){
                if(sR-1>=1 and ux!=1){
                    ux--;dx--;
                    sR--;
                }else break;
            }
            else cR++;
        }
        else if(s[i]=='L'){
            if(cC-1<1){
                if(sC+1<=m and rx!=m){
                    sC++;
                    lx++;
                    rx++;
                }else break;
            }
            else cC--;
        }
        else if(s[i]=='U'){
            if(cR-1<1 ){
                if(sR+1<=n and dx!=n){
                    sR++;
                    ux++;
                    dx++;
                }else break;
            }
            else cR--;
        }
        lx=min(lx,cC);
        rx=max(rx,cC);
        ux=min(ux,cR);
        dx=max(cR,dx);
    }
    cout<<sR<<" "<<sC<<endl;
}
    return 0;
}