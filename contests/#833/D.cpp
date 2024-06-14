# include <bits/stdc++.h>
# define pb push_back
# define int long long
# define f first
# define s second
using namespace std;
 
int cal(int x)
{
	int cnt=0;
	while(!(x&1)) cnt++,x>>=1;
	return cnt;
}
int inv(int a, int n){
    if(a == 1) return 1;
    return (1 - inv(n % a,a) * n) / a + n;
}
void solve(int test){
   int a, b, c;
    cin >> a >> b >> c;
 
    // if(test == 502){
    //     cout << a << b << c << endl;
    // }
    int cnt = 0, ptr = c;
    while(c % 2 == 0){
        c /= 2;
        cnt ++;
    }
    int d = c - ((a|b) % c);
    // cout << d << endl;
    // cout << c << endl;
    
    int x = d * inv((1ll<<(30)), c);
    cout<<inv(1LL<<(30),c)<<endl;
    x %= c;
    // cout << x << endl;
    x *= (1ll << (30 ));
    x += ((a|b));
    // cout << x << endl;
    // cout << x << ' ' << cnt << ' ' << c << ' ' << ptr<< endl;
    if((x|a) % ptr == 0 && (x|b) % ptr == 0) cout << x << endl;
    else cout << -1 << endl;
}
main(){
    int t;
    cin >> t;
    int test = 1;
    while(t--){
        solve(test++);
    }
}