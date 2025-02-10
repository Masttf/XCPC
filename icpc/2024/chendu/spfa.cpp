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
	static constexpr int inf = 1e9;
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
		int f = 0;
		int cost = 0;
		while(bfs(s, t)){
			cur.assign(n, 0);
			int aug = dfs(s, t, inf);
			f += aug;
			cost += dis[t] * aug;
		}
		return {f, cost};
	}
};
void solve(){
    
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