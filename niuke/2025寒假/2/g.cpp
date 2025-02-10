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
    int n, m; cin >> n >> m;
    if(m == 1){
    	cout << 1 << '\n';
    	return ;
    }
    vector<int> p(1, m);
    while(p.back() <= n){
    	p.push_back(p.back() * m);
    }
    int l = 0, r = p.size() - 1;
    int res = 0;
    while(l <= r){
    	int mid = (l + r) >> 1;
    	if(p[mid] <= n){
    		res = mid;
    		l = mid + 1;
    	}else r = mid - 1;
    }
    int ans = res;
    l = 0, r = p.size() - 1;
    res = 0;
    while(l <= r){
    	int mid = (l + r) >> 1;
    	if(p[mid] >= n){
    		res = mid;
    		r = mid - 1;
    	}else l = mid + 1;
    }
    if(abs(n - p[ans]) > abs(n - p[res])){
    	ans = res;
    }
    ans++;
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