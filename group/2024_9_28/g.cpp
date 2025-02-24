#include<bits/stdc++.h>
#define int long long
using namespace std;
using i128 = __int128;
ostream& operator<<(ostream& out, const __int128 &x) {
	string s;
	__int128 val = x;
	while(val) {
		s += val % 10 + '0';
		val /= 10;
	}
	reverse(s.begin(), s.end());
	for(auto i:s) out << i;
	return out;
}
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
    int x, t;
    cin >> x >> t;
    int k = x % 10;
    x -= k;
    i128 p = 1;
    i128 ans = 0;
    int rx = x;
    while(x){
    	int j = x % 10;
    	if(j >= t) --j;
    	ans += j * p;
    	x /= 10;
    	p *= 9;
    	//dbg(x, p, ans);
    }
    // dbg(rx, ans);
    if(rx % 10 == t) ans--;
    else if(k >= t) ans += k - 1;
    else ans += k;
    cout << ans + 1 << '\n';
    return ;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--)solve();
    return 0;
}