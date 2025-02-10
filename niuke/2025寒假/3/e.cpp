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
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i++){
    	int p, v; cin >> p >> v;
    	a[i] = {p, v};
    }
    sort(a.begin() + 1, a.end());
    auto check = [&](double len) -> bool{
    	// dbg(len);
    	int cnt = 0;
    	int num = 0;
    	for(int i = 1, j = 1; i <= n; i++){
    		auto [p, v] = a[i];
    		while(j <= n && a[j].first - p <= 2  * len){
    			if(a[j].second == -1)num++;
    			j++;
    		}
    		if(v == 1){
    			cnt += num;
    		}else{
    			num--;
    		}
    	}
    	return cnt >= k;
    };
    double ans = -1;
    double l = 0, r = 1e18;
    for(int i = 1; i <= 100; i++){
    	double mid = (l + r) / 2;
    	if(check(mid)){
    		r = mid;
    		ans = mid;
    	}else{
    		l = mid;
    	}
    }
    if(ans == -1){
    	cout << "NO\n";
    }else{
    	cout << "YES\n";
    	cout << fixed << setprecision(10) << ans << '\n';
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
/*
交换速度那么就是穿过
k对，可以二分

*/