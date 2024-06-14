//changing places of x pairs candles takes max x operations 
#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define ll long long
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll testcase;
cin>>testcase;
while(testcase--){
    ll n;cin>>n;
    string a,b;
    cin>>a>>b;
    ll zca=0,zcb=0,disp=0,zdisp=0;
    ll ans=-1;
    for(int i=0;i<n;i++){
        if(a[i]=='0'){zca++;}
        if(b[i]=='0'){zcb++;}
        if(a[i]=='1' and a[i]!=b[i])disp++;
        if(a[i]=='0' and a[i]!=b[i])zdisp++;
    }

    if(zca==zcb){
        ans=disp*2;
    }
    ll oca=n-zca;
    for(int i=0;i<n;i++){
        if(a[i]=='0')continue;
        if(oca-1!=zcb)break;
        ll cDisp;
        if(b[i]=='1'){
            cDisp=(zca-zdisp);
        }
        else{
            // cDisp=(zca-(disp-1))+1;
            cDisp=(zca-zdisp)+1;
        }
        if(zcb==oca-1){
            if(ans==-1)ans=1+cDisp*2;
            else ans=min(1+cDisp*2,ans);
        }
    }
    cout<<ans<<endl;

}
    return 0;
}