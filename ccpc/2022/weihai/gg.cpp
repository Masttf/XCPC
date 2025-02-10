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
void solve(){
    int x, n; cin >> x >> n;
    int len;
    for(int i = 30; i >= 0; i--){
    	if(x >> i & 1){
    		len = (1 << (i + 1));
    		break;
    	}
    }
    vector<int>val(len + 1), pre(len + 1);
    for(int i = 1; i <= len; i++){
    	val[i] = __gcd((i * x) ^ x, x);
    	pre[i] = pre[i - 1];
    	if(val[i] == 1)pre[i]++;
    }
    auto get = [&](int r) -> int{
    	int ans = r / len * pre[len];
    	ans += pre[r % len];
    	return ans;
    };
    for(int i = 1; i <= n; i++){
    	int l, r; cin >> l >> r;
    	cout << get(r) - get(l - 1) << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}