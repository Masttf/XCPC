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
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    auto check = [&](double x) -> bool{
    	double res = 0;
    	for(int i = 1; i <= n; i++){
    		res += a[i] * x / (1.0 + a[i] * x);
    	}
    	return res >= k;
    };
    double l = 0, r = 8e18;
	for(int i = 1; i <= 500; i++){
		double mid = (l + r) / 2;
		if(check(mid)){
			r = mid;
		}else l = mid;
	}
	double x = l;
	vector<double> ans(n + 1);
	for(int i = 1; i <= n; i++){
		ans[i] = a[i] * x / (1.0 + a[i] * x);
	}
	for(int i = 1; i <= n; i++){
		cout << fixed << setprecision(12) << ans[i] << '\n';
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