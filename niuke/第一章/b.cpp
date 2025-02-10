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
    int n; cin >> n;
    vector<int> a(n + 2);
    for(int i = 1; i <= n + 1; i++) cin >> a[i];
    string ans = "";
	for(int i = 1; i <= n + 1; i++){
		if(a[i] == 0)continue;
		int d = abs(a[i]);
		if(d != a[i]){
			ans += '-';
			if(d > 1 || i == n + 1)ans += to_string(d);
		}else{
			if(!ans.empty()) ans += '+';
			if(d > 1 || i == n + 1)ans += to_string(d);
		}
		int num = n - i + 1;
		if(num > 1){
			ans += "x^";
			ans += to_string(num);
		}else if(num == 1) ans += 'x';
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