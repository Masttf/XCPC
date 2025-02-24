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
    int n, D; cin >> n >> D;
    vector<int> x(n + 1), y(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> x[i] >> y[i];
    }
    sort(x.begin() + 1, x.end());
    sort(y.begin() + 1, y.end());
    vector<int>prey(n + 1), prex(n + 1);
    for(int i = 1; i <= n; i++){
    	prex[i] = prex[i - 1] + x[i];
    	prey[i] = prey[i - 1] + y[i];
    }
    auto gety = [&](int val) -> int{
    	int pos = upper_bound(y.begin() + 1, y.end(), val) - y.begin() - 1;
    	int tot = val * pos - prey[pos] + prey[n] - prey[pos] - (n - pos) * val;
    	return tot;
    };
    auto getx = [&](int val) -> int{
    	int pos = upper_bound(x.begin() + 1, x.end(), val) - x.begin() - 1;
    	int tot = val * pos - prex[pos] + prex[n] - prex[pos] - (n - pos) * val;
    	return tot;
    };
    vector<int> cntx(D + 1);
    vector<int> cnty(D + 1);
    for(int i = 0; i <= D; i++){
    	int ps = y[(n + 1) / 2];
    	int cost = gety(ps);
    	if(cost <= i){
    		//dbg(ps);
    		int l = y[1] - D, r = ps;
	    	int res = ps;
	    	while(l <= r){
	    		int mid = (l + r) >> 1;
	    		if(gety(mid) <= i){
	    			res = mid;
	    			r = mid - 1;
	    		}else l = mid + 1;
	    	}
	    	//dbg(res, gety(res));
	    	cnty[i] += ps - res + 1;
	    	l = ps + 1, r = y[n] + D;
	    	res = ps;
	    	while(l <= r){
	    		int mid = (l + r) >> 1;
	    		if(gety(mid) <= i){
	    			res = mid;
	    			l = mid + 1;
	    		}else r = mid - 1;
	    	}
	    	//dbg(res);
	    	cnty[i] += res - ps;
	    	// dbg(i, cnty[i]);
    	}
    	ps = x[(n + 1) / 2];
    	cost = getx(ps);
    	if(cost <= i){
    		int l = x[1] - D, r = ps;
	    	int res = ps;
	    	while(l <= r){
	    		int mid = (l + r) >> 1;
	    		if(getx(mid) <= i){
	    			res = mid;
	    			r = mid - 1;
	    		}else l = mid + 1;
	    	}
	    	cntx[i] += ps - res + 1;
	    	l = ps + 1, r = x[n] + D;
	    	res = ps;
	    	while(l <= r){
	    		int mid = (l + r) >> 1;
	    		if(getx(mid) <= i){
	    			res = mid;
	    			l = mid + 1;
	    		}else r = mid - 1;
	    	}
	    	cntx[i] += res - ps;
	    	// dbg(i, cntx[i]);
    	}
    }
    int ans = 0;
    for(int i = x[1] - D; i <= x[1] + D; i++){
    	int ct = getx(i);
    	if(ct > D)continue;
    	ans += cnty[D - ct];
    }
    // for(int i = 0; i <= D; i++){
    // 	ans += cntx[i] * cnty[D - i];
    // }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}