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
    int n, c1, c2; cin >> n >> c1 >> c2;
    vector<pair<int, int>> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++){
    	int x, y; cin >> x >> y;
    	a[i] = {x, y};
    	b[i] = {y, x};
    }
 	a[0] = {0, 0};
    vector g(2 * n + 1, vector<pair<int, int>>());
    vector<int> du(2 * n + 1);
    for(int i = 0; i <= n; i++){
    	auto [x1, y1] = a[i];
    	for(int j = i + 1; j <= n; j++){
    		auto [x2, y2] = a[j];
    		int w = c1 * (j - i - 1);
    		if(x2 >= x1 && y2 >= y1){
    			g[i].push_back({j, w});
    			du[j]++;
    		}
    		x2 = b[j].first;
    		y2 = b[j].second;
    		if(x2 >= x1 && y2 >= y1){
    			g[i].push_back({n + j, w + c2});
    			du[n + j]++;
    		}
    	}
    	if(i){
    		x1 = b[i].first;
	    	y1 = b[i].second;
	    	for(int j = i + 1; j <= n; j++){
	    		auto [x2, y2] = a[j];
	    		int w = c1 * (j - i - 1);
	    		if(x2 >= x1 && y2 >= y1){
	    			g[n + i].push_back({j, w});
	    			// dbg('2', i, j);
	    			du[j]++;
	    		}
	    		x2 = b[j].first;
	    		y2 = b[j].second;
	    		if(x2 >= x1 && y2 >= y1){
	    			g[n + i].push_back({n + j, w + c2});
	    			du[n + j]++;
	    		}
	    	}
    	}
    	
    }
    queue<int> q;
    int inf = c1 * n;
    vector<int> ans(2 * n + 1, inf);
    ans[0] = 0;
    for(int i = 0; i <= 2 * n; i++){
    	if(du[i] == 0){
    		q.push(i);
    	}
    }
    while(!q.empty()){
    	int u = q.front();
    	// dbg(u, ans[u]);
    	q.pop();
    	for(auto [v, w] : g[u]){
    		ans[v] = min(ans[v], ans[u] + w);
    		du[v]--;
    		if(du[v] == 0)q.push(v);
    	}
    }
    int res = inf;
    for(int i = 1; i <= n; i++){
    	int d = (n - i) * c1;
    	res = min(res, d + ans[i]);
    	res = min(res, d + ans[i + n]);
    }
    cout << res << '\n';
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
/*
要求就是
ai >= ai -1, bi >= bi - 1
时间复杂度要求 n ^ 2 

pair 对的数量状态是n^2
枚举那个状态是最终状态倒推？
建图跑拓扑？

*/