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
    vector<int>last(n + 1);
    vector<array<int, 3>> a;
    vector<int>P;
    for(int i = 1; i <= m; i++){
    	int t, p; cin >> t >> p;
    	P.push_back(t);
    	if(last[p]){
    		a.push_back({last[p], t, p});
    		last[p] = 0; 
    	}else last[p] = t;
    }
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    auto get = [&](int x) -> int{
    	return lower_bound(P.begin(), P.end(), x) - P.begin() + 1;
    };
    sort(a.begin(), a.end());
    vector<vector<pair<int, int>>> edge(n + 1);
    for(auto &[l, r, id] : a){
    	l = get(l);
    	r = get(r) - 1;
    	edge[id].push_back({l ,r});
    }
    int B = sqrt(m / 2);
    vector<int> bl(n + 1);
    vector<int> use;
    for(int i = 1; i <= n; i++){
    	if(edge[i].size() > B){
    		bl[i] = use.size();
    		use.push_back(i);
    		//dbg(i);
    	}
    }
    auto bf = [&](int x, int y) -> int{
    	const int sx = edge[x].size();
    	const int sy = edge[y].size();
    	int i = 0, j = 0;
    	int sum = 0;
    	while(i < sx && j < sy){
    		auto [l1, r1] = edge[x][i];
    		auto [l2, r2] = edge[y][j];
    		l1 = P[l1 - 1], l2 = P[l2 - 1];
    		r1 = P[r1], r2 = P[r2];
    		sum += max(0ll, min(r1, r2) - max(l1, l2));
    		int mxr = max(r1, r2);
    		if(r1 == mxr)j++;
    		else i++;
    	}
    	//dbg(x, y, sx, sy);
    	return sum;
    };
    vector val(B + 1, vector<int>(n + 1));
    const int sz = P.size();
    auto run = [&](int x) -> void{
        vector<int> cnt(sz + 1), ans(sz + 1);
        for(auto [l, r] : edge[x]){
        	cnt[l]++;
        	cnt[r + 1]--;
        }
        for(int i = 1; i <= sz; i++){
        	cnt[i] += cnt[i - 1];
        	ans[i] += ans[i - 1];
        	if(cnt[i])ans[i] += P[i] - P[i - 1];
        }
        for(auto [l, r, id] : a){
        	val[bl[x]][id] += ans[r] - ans[l - 1];
        }
    };
    for(int i = 0; i < use.size(); i++){
    	int x = use[i];
    	run(x);
    }
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
    	int x, y; cin >> x >> y;
    	if(edge[x].size() < edge[y].size())swap(x, y);
    	if(edge[x].size() <= B && edge[y].size() <= B){
    		cout << bf(x, y) << '\n';
    	}else{
    		cout << val[bl[x]][y] << '\n';
    	}
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}