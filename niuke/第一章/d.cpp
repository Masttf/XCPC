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
    vector<array<int, 4>> a(n + 1);
    for(int i = 1; i <= n; i++){
    	int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
    	a[i] = {x0, y0, x1, y1};
    }
    int x, y; cin >> x >> y;
    int ans = -1;
    for(int i = n; i >= 1; i--){
    	auto [x0, y0, x1, y1] = a[i];
    	if(x0 <= x && x <= x0 + x1 && y0 <= y && y <= y0 + y1){
    		ans = i;
    		break;
    	}
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