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
    int n, f; cin >> n >> f;
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i].first >> a[i].second;
    }
    vector<int> res(n + 1);
    int tot = 0;
    int ans = 0;
    vector<int> vis(n + 1);
    vector<array<int, 3>> b(n + 1);
    for(int i = 1; i <= n; i++){
    	auto [l, r] = a[i];
    	b[i] = {l, r, i};
    }
    sort(b.begin() + 1, b.end(), [&](array<int, 3> &x, array<int, 3> &y) -> bool{
    	return x[0] < y[0];
    });
    priority_queue<pair<int, int>>q;
    int now = f;
    for(int j = 1; j <= n; j++){
    	if(b[j][0] <= now){
    		q.push({b[j][1], b[j][2]});
    	}else{
    		if(!q.empty() && q.top().first > now){
    			auto [r, id] = q.top();
    			q.pop();
    			now = r;
    			ans += a[id].second - a[id].first;
    			res[++tot] = id;
    			vis[id] = 1;
    		}
    		if(b[j][0] <= now){
    			q.push({b[j][1], b[j][2]});
    		}else{
    			ans += max(0ll, b[j][0] - now);
    			ans += b[j][1] - b[j][0];
    			now = b[j][1];
    			res[++tot] = b[j][2];
    			vis[b[j][2]] = 1;
    		}
    	}
    }
    if(!q.empty() && q.top().first > now){
		auto [r, id] = q.top();
		q.pop();
		now = r;
		ans += a[id].second - a[id].first;
		res[++tot] = id;
		vis[id] = 1;
	}
	vector<int> temp;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			temp.push_back(i);
		}
	}
	sort(temp.begin(), temp.end(), [&](int &x, int &y) -> bool{
		return a[x].second > a[y].second;
	});
	for(auto x : temp){
		ans += a[x].second - a[x].first;
		res[++tot] = x;
	}
	cout << ans << '\n';
	for(int i = 1; i <= n; i++){
		cout << res[i] << " \n"[i == n];
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