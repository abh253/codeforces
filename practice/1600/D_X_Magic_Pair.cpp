#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define ll long long

bool solve(ll a,ll b, ll x){
    if(a==0)return 0;
    if(x>a and x>b )return 0;
    if(x==a or x==b )return 1;
    if(a>b) return solve(b,a,x);

    if(x>(b%a) and (x-(b%a))%a==0)return 1;

    return solve(a,b%a,x);
}
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll testcase;
cin>>testcase;
while(testcase--){
    ll a,b,x;cin>>a>>b>>x;
    if(solve(a,b,x)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
    return 0;
}
