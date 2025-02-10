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
    vector res(n + 1, vector<pair<int, int>>());
    vector<int>last(n + 1);
    vector<pair<int, int>> a(m + 1);
    for(int i = 1; i <= m; i++){
    	int t, p; cin >> t >> p;
    	if(last[p]){
    		res[p].push_back({last[p], t});
    		last[p] = 0; 
    	}else last[p] = t;
        a[i] = {t, p};
    }
    int B = sqrt(m / 2);
    vector<int> bl(n + 1);
    vector<int> use;
    for(int i = 1; i <= n; i++){
    	if(res[i].size() > B){
    		bl[i] = use.size();
    		use.push_back(i);
    		//dbg(i);
    	}
    }
    auto get = [&](int x, int y) -> int{
    	const int sx = res[x].size();
    	const int sy = res[y].size();
    	int i = 0, j = 0;
    	int sum = 0;
    	while(i < sx && j < sy){
    		auto [l1, r1] = res[x][i];
    		auto [l2, r2] = res[y][j];
    		sum += max(0ll, min(r1, r2) - max(l1, l2));
    		int mxr = max(r1, r2);
    		if(r1 == mxr)j++;
    		else i++;
    	}
    	//dbg(x, y, sx, sy);
    	return sum;
    };
    vector val(B + 1, vector<int>(n + 1));
    auto run = [&](int x) -> void{
        vector<int> vis(n + 1);
        int sum = 0;
        int flag = 0;
        int last = 0;
        for(int i = 1; i <= m; i++){
            auto [t, p] = a[i];
            if(p == x){
                if(flag)sum += t - last;
                last = t;
                flag ^= 1;
            }
            val[bl[x]][p] += (vis[p] ? 1 : -1) * (sum + (flag ? t - last : 0));
            vis[p] ^= 1;
        }
    };
    for(int i = 0; i < use.size(); i++){
    	int x = use[i];
    	run(x);
    }
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
    	int x, y; cin >> x >> y;
    	if(res[x].size() < res[y].size())swap(x, y);
    	if(res[x].size() <= B && res[y].size() <= B){
    		cout << get(x, y) << '\n';
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