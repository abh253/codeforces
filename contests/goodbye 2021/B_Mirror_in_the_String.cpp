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
    string s;
    cin>>s;
    int k=1;
    for(int i=1;i<n;i++){
        if(i==1 and s[i]>=s[i-1])break;
        if(s[i]>s[i-1])break;
        k++;
    }
    string mImg=s.substr(0,k);
    reverse(mImg.begin(),mImg.end());
    cout<<s.substr(0,k)+mImg<<endl;
}
    return 0;
}