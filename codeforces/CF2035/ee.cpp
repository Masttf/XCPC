#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
constexpr int Max = 1e18;
void solve(){
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    int ans = Max;
    auto get = [&](int x) -> int{
        int d = x / K;
        int ret = Z - K * (1 + d) * d / 2;
        if(ret < 0)return Max;
        return d * Y + (ret + x - 1) / x * Y + x * X;
    };
    for(int l = 0, r; l <= Z; l++){
    	r = K * (l + 1) - 1;
        if(K * (1 + l) * l / 2 > Z)break;
        int ret = Z - K * (1 + l) * l / 2;
    	for(int i = max(1ll, l * K); i < (l + 1) * K; ){
            ans = min(ans, get(i));
            int t = (ret + i - 1) / i;
            // dbg(i, ret, t);
            if(t <= 1)break;
            i = (ret + t - 2) / (t - 1);
        }
    }
    // int res = -1;
    // for(int i = 1; i <= Z; i++){
    //     if(ans > get(i)){
    //         ans = get(i);
    //         res = i;
    //     }
    // }
    // dbg(res);
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
/*
up
k + 1 k
2 * (k + 1) 2k
...
up / k *(k + 1), up / k * k
.... up
ret = z - k * (1 + up / k) * (up / k) / 2
tot = up / k * y + (ret + up - 1) / up * y + up * x
limit : ret > 0 
*/