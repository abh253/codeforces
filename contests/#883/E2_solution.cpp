 
//Author: Ankush Bhagat (https://github.com/ankushbhagat124)
//RFIPITIDS?
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const long long inf = (numeric_limits<long long>::max());
const int N = (2e5 + 1);
const int mod = (1e9 + 7);
 
template <class type1>
using ordered_multiset = tree <type1, null_type, less <type1>, rb_tree_tag, tree_order_statistics_node_update>;
 
clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
 
void init()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V, typename M>
void __print(const tuple<T, V, M> &x) {cerr << '{'; __print(get<0>(x)); cerr << ','; __print(get<1>(x)); cerr << ','; __print(get<2>(x)); cerr << '}';}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(priority_queue<T> &x) {int f = 0; cerr << '{'; while (!x.empty()) { cerr << (f++ ? "," : ""), __print(x.top()); x.pop();} cerr << "}";}
template<typename T>
void __print(stack<T> &x) {int f = 0; cerr << '{'; while (!x.empty()) { cerr << (f++ ? "," : ""), __print(x.top()); x.pop();} cerr << "}";}
template<typename T>
void __print(queue<T> &x) {int f = 0; cerr << '{'; while (!x.empty()) { cerr << (f++ ? "," : ""), __print(x.front()); x.pop();} cerr << "}";}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/**********************************************************************************************************************/
 
unordered_map <long long, int> isPresent;
void precompute()
{
    for (long long k = 2; 1 + k + k * k + k * k * k <= 1e18; k++)
    {
        long long start = 1 + k + k * k + k * k * k;
        isPresent[start] = 1;
        long long pow = k * k * k;
        while (pow < (1e18) / k && start < 1e18)
        {
            pow *= k;
            start += pow;
            isPresent[start] = 1;
        }
    }
}
 
signed main()
{
    init();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    precompute();
    int t = 1;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
 
        if (isPresent[n])
            cout << "YES";
        else
        {
            // 1 + k + k*k = n;
            int l = 2, h = 1e9;
            bool found = false;
            while (l <= h)
            {
                long long mid = (l + h) / 2;
                if (1 + mid + mid * mid == n)
                {
                    found = true;
                    break;
                }
 
                if (1 + mid + mid * mid < n)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            if (found)
                cout << "YES";
            else
                cout << "NO";
        }
        cout << endl;
    }
 
    double time = getCurrentTime();
    debug(time);
}