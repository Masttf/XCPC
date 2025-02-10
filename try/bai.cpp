#include<bits/stdc++.h>
// #define int long long
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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    s = s + s;
    s = " " + s;
    vector<int> val(2 * n + 1);
    for(int i = 1; i <= n; i++) cin >> val[i];
    for(int i = n + 1; i <= 2 * n; i++)val[i] = val[i - n];
    vector<int> last(30);
	vector st(21, vector<int>(2 * n + 5));
	for(int i = 2 * n; i >= 1; i--){
		if(last[s[i] - 'A'])st[0][i] = last[s[i] - 'A'] + 1;
		else st[0][i] = 2 * n + 1;
		last[s[i] - 'A'] = i;
	}
	st[0][2 * n + 1] = 2 * n + 1;
	for(int k = 1; k <= 20; k++){
		for(int i = 1; i <= 2 * n + 1; i++){
			st[k][i] = st[k - 1][st[k - 1][i]];
		}
	}
	for(int i = 1; i <= q; i++){
		int ty, x, y; cin >> ty >> x >> y;
		if(ty == 1){
			val[x] = y;
			val[x + n] = y;
		}else{
			if(x > y)y += n;
			int ans = 0;
			int now = x;
			while(now <= y){
				// dbg(now);
				for(int j = 20; j >= 0; j--){
					if(st[j][now] <= y + 1){
						now = st[j][now];
					}
				}
				if(now <= y)ans += val[now];
				now++;
			}
			cout << ans << '\n';
		}
	}
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