#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr long long Max = 1e18;
struct Max_Flow{
    struct node{
        int v, w;
    };
    int n;
    vector<node> e;
    vector<vector<int>> g;
    vector<int> h, cur;
    Max_Flow(int n){
        init(n);
    }
    void add(int u, int v, int w){
        g[u].push_back(e.size());
        e.push_back({v, w});
        g[v].push_back(e.size());
        e.push_back({u, 0});
    }
    void init(int n) {
        this->n = n;
        e.clear();
        g.assign(n, {});
        cur.resize(n);
        h.resize(n);
    }
    bool bfs (int s, int t){
        h.assign(n, -1);
        queue<int> q;
        h[s]=0;
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto i : g[u]){
                auto [v, w] = e[i];
                if(h[v] == -1 && w){
                    h[v] = h[u] + 1;
                    if(v == t){
                        return true;
                    }
                    q.push(v);
                }
            }
        }
        return false;
    }
    int dfs(int u, int t, int val){
        if(u == t)return val;
        int res = val;
        for(auto &i = cur[u]; i < (int)g[u].size(); i++){
            int j = g[u][i];
            auto [v, w] = e[j];
            if(w > 0 && h[v] == h[u] + 1){
                int d = dfs(v, t, min(res, w));
                e[j].w -= d;
                e[j ^ 1].w += d;
                res -= d;
                if(res == 0)return val;
            }
        }
        return val - res;
    }
    int flow(int s, int t){
        int ans = 0;
        while(bfs(s, t)){
            cur.assign(n, 0);
            ans += dfs(s, t, Max);
        }
        return ans;
    }
    vector<int> mincut(){
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(h[i] != -1)res.push_back(i);
        }
        return res;
    }
    vector<pair<int, int>> get_mincut_edge(){
        vector<pair<int, int>> res;
        for(int i = 0; i < e.size(); i += 2){
            int u = e[i + 1].v;
            int v = e[i].v;
            if(h[u] != -1 && h[v] == -1){
                res.push_back({u, v});
            }
        }
        return res;
    }
};
void solve(){
	int n, m; cin >> n >> m;
	vector<string>a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = ' ' + a[i];
	}
	auto get = [&](int x, int y) -> int{
		return (x - 1) * m + y;
	};
	int s = 0, t = 3 * n * m + 1;
	int ans = 0;
	Max_Flow g(t + 1);
	vector<int>temp;
	auto check = [&](int x, int y) -> void{
		if(x == n || y == m)return ;
		if(a[x][y] != 'W' && a[x + 1][y] != 'B' && a[x][y + 1] != 'B' && a[x + 1][y + 1] != 'W'){
			if((x + y) & 1){
				int u = 2 * n * m + get(x, y);
				temp.push_back(u);
				g.add(u, t, 1);
				g.add(get(x, y), u, Max);
				g.add(get(x + 1, y), u, Max);
				g.add(get(x, y + 1), u, Max);
				g.add(get(x + 1, y + 1), u, Max);
				ans++;
			}else{
				int u = n * m + get(x, y);
				temp.push_back(u);
				g.add(s, u, 1);
				g.add(u, get(x, y), Max);
				g.add(u, get(x + 1, y), Max);
				g.add(u, get(x, y + 1), Max);
				g.add(u, get(x + 1, y + 1), Max);
				ans++;
			}
		}
		if(a[x][y] != 'B' && a[x + 1][y] != 'W' && a[x][y + 1] != 'W' && a[x + 1][y + 1] != 'B'){
			if((x + y) & 1){
				int u = n * m + get(x, y);
				temp.push_back(u);
				g.add(s, u, 1);
				g.add(u, get(x, y), Max);
				g.add(u, get(x + 1, y), Max);
				g.add(u, get(x, y + 1), Max);
				g.add(u, get(x + 1, y + 1), Max);
				ans++;
			}else{
				int u = 2 * n * m + get(x, y);
				temp.push_back(u);
				g.add(u, t, 1);
				g.add(get(x, y), u, Max);
				g.add(get(x + 1, y), u, Max);
				g.add(get(x, y + 1), u, Max);
				g.add(get(x + 1, y + 1), u, Max);
				ans++;
			}
		}
	};
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			check(i ,j);
		}
	}
	//dbg(ans);

	ans = ans - g.flow(s, t);
	vector res(n + 1, vector<char>(m + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			res[i][j] = a[i][j];
			if(res[i][j] == '?')res[i][j] = 'W';
		}
	}
	vector<pair<int, int>>edge = g.get_mincut_edge();
	vector<int>c(t + 1);
	for(auto [u, v] : edge){
		if(u == 0)c[v]++;
		else c[u]++;
	}
	for(auto i : temp){
		if(c[i])continue;
		//dbg(i);
		int x, y;
		if(i >= 2 * n * m){
			x = (i - 2 * n * m) / m + 1;
			y = (i - 2 * n * m) % m;
			if(y == 0){
				y = m;
				x--;
			}
			//dbg(x, y);
			if((x + y) & 1){
				res[x][y] = 'B';
				res[x + 1][y] = 'W';
				res[x][y + 1] = 'W';
				res[x + 1][y + 1] = 'B';
			}else{
				res[x][y] = 'W';
				res[x + 1][y] = 'B';
				res[x][y + 1] = 'B';
				res[x + 1][y + 1] = 'W';
			}
		}else{
			x = (i - n * m) / m + 1;
			y = (i - n * m) % m;
			if(y == 0){
				y = m;
				x--;
			}
			//dbg(x, y);
			if((x + y) & 1){
				res[x][y] = 'W';
				res[x + 1][y] = 'B';
				res[x][y + 1] = 'B';
				res[x + 1][y + 1] = 'W';
			}else{
				res[x][y] = 'B';
				res[x + 1][y] = 'W';
				res[x][y + 1] = 'W';
				res[x + 1][y + 1] = 'B';
			}
		}
	}
	cout << ans << '\n';
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << res[i][j];
		}
		cout << '\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}