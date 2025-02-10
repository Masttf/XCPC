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
struct MCFGraph{
	//#define int long long
	static constexpr int inf = 1e18;
	struct Edge {
        int v, c, f;
        Edge(int v, int c, int f) : v(v), c(c), f(f) {}
    };
    int n;
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> dis, cur, vis;
	MCFGraph(int n){
		this->n = n;
		e.clear();
        g.assign(n, {});
        cur.assign(n, 0);
        vis.assign(n, 0);
	}
	void add(int u, int v, int c, int f){
		g[u].push_back(e.size());
        e.emplace_back(v, c, f);
        g[v].push_back(e.size());
        e.emplace_back(u, 0, -f);
	}
	bool bfs(int s, int t){
		dis.assign(n, inf);
		queue<int> que;
		dis[s] = 0;
		vis[s] = 1;
		que.push(s);
		while(!que.empty()){
			int u = que.front();
			que.pop();
			vis[u] = 0;
			for(auto i : g[u]){
				auto [v, c, f] = e[i];
				if(c > 0 && dis[v] > dis[u] + f){
					dis[v] = dis[u] + f;
					if(!vis[v]){
						vis[v] = 1;
						que.push(v);
					}
				}
			}
		}
		return dis[t] != inf;
	}
	int dfs(int u, int t, int flow){
		if (u == t) return flow;
		vis[u] = 1;
		int used = 0;
		for(int &i = cur[u]; i < (int)g[u].size(); i++){
			int j = g[u][i];
			auto [v, c, f] = e[j];
			if(!vis[v] && c > 0 && dis[v] == dis[u] + f){
				int k = dfs(v, t, min(flow - used, c));
				used += k;
				e[j].c -= k;
				e[j ^ 1].c += k;
				if(used == flow) break;
			}
		}
		vis[u] = 0;
		return used;
	}
	pair<int, int> flow(int s, int t){
		int flow = 0;
		int cost = 0;
		while(bfs(s, t)){
			cur.assign(n, 0);
			int aug = dfs(s, t, inf);
			flow += aug;
			cost += dis[t] * aug;
		}
		return {flow, cost};
	}
};
constexpr int maxn = 1e5 + 5;
array<int, 3> res[maxn];
int tot = 0;
vector<int> prim;
bool vis[maxn];
void init(){
    for(int i = 2; i < maxn; i++){
        if(!vis[i]){
            vis[i] = 1;
            prim.push_back(i);
        }
        for(int j = 0; prim[j] * i < maxn; j++){
            vis[i * prim[j]] = 1;
            if(i % prim[j] == 0)break;
        }
    }
}
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    map<int, int> mp;
    int t = n;
    vector<int>p(40);
    vector<int>pw(40);
    int sz = 0;
    
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        sz = 0;
        int num = 0;
        auto dfs = [&](auto self, int step, int now, int w) -> void{
            if(num > n)return ;
            if(step > sz){
                if(!mp.count(now))mp[now] = ++t;
                num++;
                res[++tot] = {i, mp[now], w - cnt};
                return ;
            }
            self(self, step + 1, now, w);
            for(int j = 1; j <= pw[step]; j++){
                now *= p[step];
                self(self, step + 1, now, w + j);
            }
        };
        int x = a[i];
        p.assign(40, 0);
        pw.assign(40, 0);
        for(auto j : prim){
            if(j > x)break;
            if(x % j == 0){
                p[++sz] = j;
                while(x % j == 0){
                    pw[sz]++;
                    x /= j;
                    cnt++;
                }
            }
        }
        if(x != 1){
            p[++sz] = x;
            pw[sz] = 1;
            cnt++;
        }
        dfs(dfs, 1, 1, 0);
    }
    t++;
    int s = 0;
    MCFGraph f(t + 1);
    for(int i = 1; i <= n; i++){
        f.add(s, i, 1, 0);
    }
    for(auto [x, y] : mp){
        f.add(y, t, 1, 0);
    }
    for(int i = 1; i <= tot; i++){
        auto [u, v, w] = res[i];
        f.add(u, v, 1, w);
    }
    auto [ans, cost] = f.flow(s, t);
    cout << -cost << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    init();
    // cin >> t;
    while(t--)solve();
    return 0;
}