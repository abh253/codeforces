#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define ll long long

vector<int>v(200000);
ll n;
bool check(int x){
    vector<int>add(n,0);

    for(int i=n-1;i>=2;i--){
        if((v[i]+add[i])<x)return 0;
        int d=min(v[i],v[i]+add[i]-x)/3;
        add[i-1]+=d;
        add[i-2]+=(2*d);
    }
    return (add[0]+v[0])>=x and (add[1]+v[1])>=x;

}
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll testcase;
cin>>testcase;
while(testcase--){
    cin>>n;
    int l=1,r=1;
    for(int i=0;i<n;i++){
            cin>>v[i];
            l=min(v[i],l);
            r=max(v[i],r); 
    }
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)){
            l=mid;
        }else {r=mid-1;}
    }

    cout<<r<<endl;
}
    return 0;
}