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
    vector<pair<int, int>>a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i].first >> a[i].second;
    }
    if(n < 5){
    	cout << "NO\n";
    	return ;
    }
    for(int i = 2; i <= n; i++){
    	if(a[i].first < a[1].first){
    		swap(a[i], a[1]);
    	}
    }
    map<pair<int, int>, pair<int, int>>mp;
    auto run = [&]() -> bool{
    	mp.clear();
    	auto check = [&]() -> bool{
    		mp.clear();
    		auto [x, y] = a[1];
		    for(int i = 2; i <= n; i++){
		    	auto [tx, ty] = a[i];
		    	int dx = tx - x;
		    	int dy = ty - y;
		    	int d = __gcd(dx, dy);
		    	dx /= d;
		    	dy /= d;
		    	if(dx != 0){
		    		if((tx - x) * dx < 0){
		    			dx = -dx;
		    			dy = -dy;
		    		}
		    	}else{
		    		if((ty - y) * dy < 0){
		    			dx = -dx;
		    			dy = -dy;
		    		}
		    	}
		    	
		    	// dbg(dx, dy);
		    	if(mp.count({dx, dy})){
		    		pair<int, int> temp = mp[{dx, dy}];
		    		if(temp.second == 0)temp.second = i;
		    		mp[{dx, dy}] = temp;
		    	}else{
		    		mp[{dx, dy}] = {i, 0};
		    	}
		    }
		    // dbg(a[1].first, a[1].second, mp.size());
		    // dbg(mp.size());
		    if(mp.size() >= 4){
		    	cout << "YES\n";
		    	cout << x << ' ' << y << '\n';
		    	int cnt = 0;
		    	for(auto [xx, yy] : mp){
		    		cnt++;
		    		int now = yy.first;
		    		cout << a[now].first << ' ' << a[now].second << '\n';
		    		if(cnt == 4)break;
		    	}
		    	return true;
		    }
		    return false;
    	};
    	if(check())return true;
	    else if(mp.size() == 3){
	    	vector<int> ans;
	    	ans.push_back(1);
	    	pair<int, int> chose;
	    	for(auto [x, y] : mp){
	    		// dbg(x.first, x.second, y.first, y.second);
	    		if(y.second){
	    			ans.push_back(y.first);
	    			ans.push_back(y.second);
	    			// dbg(y.first, y.second);
	    			chose = x;
	    			break;
	    		}
	    	}
	    	for(auto [x, y] : mp){
	    		if(x == chose)continue;
	    		ans.push_back(y.first);
	    	}
	    	// dbg(ans.size());
	    	for(auto x : ans){
	    		swap(a[1], a[x]);
	    		mp.clear();
	    		if(check())return true;
	    	}
	    	assert(0);
	    	return true;

	    }
	    return false;
    };
    // dbg("111");
    if(run())return ;
    else{
    	// dbg("???");
    	swap(a[1], a[2]);
    	if(run())return ;
    	swap(a[1], a[3]);
    	if(run()) return;
    	cout << "NO\n";
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