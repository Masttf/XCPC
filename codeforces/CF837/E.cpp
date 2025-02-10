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
    int x, y; cin >> x >> y;
    int d = __gcd(x, y);
    int ans = 0;
    map<int, int> mp;
    auto get = [&]() -> void{
    	d = __gcd(x, y);
    	map<int, int> res;
    	swap(res, mp);
    	int tmp = x / d;
	    for(int i = 2; i * i <= tmp; i++){
			while(tmp % i == 0){
				mp[i]++;
				tmp /= i;
			}
	    }
	    if(tmp != 1)mp[tmp]++;
    };
    while(y > 0){
    	get();
    	int now = y / d;
    	int mx = 0;
    	for(auto [val, cnt] : mp){
    		mx = max(mx, now / val * val);
    	}
    	ans += now - mx;
    	y -= (now - mx) * d;
    }
    cout << ans << '\n';
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
/*
gcd(a, b) = gcd(b, a % b)
d = gcd(a, b)
b = k1 * d
a = k2 * d
gcd(k1, k2) = 1
b = (k1 - 1) * d

k1-1, k2
k1-1, 
*/