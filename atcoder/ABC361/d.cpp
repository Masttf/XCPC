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
constexpr int Max = 1e18;
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s += "..";
    string t; cin >> t;
    t += "..";
    vector<int> p(n + 5);
    p[0] = 1;
    for(int i = 1; i <= n + 2; i++){
    	p[i] = p[i - 1] * 3;
    }
    vector<int> vis(p[n + 2]);
    vector<int> dis(p[n + 2], -1);
    int S = 0;
    for(int i = 0; i < n + 2; i++){
    	if(s[i] == 'W')S += p[i];
    	else if(s[i] == 'B') S += 2 * p[i];
    }
    int T = 0;
    for(int i = 0; i < n + 2; i++){
    	if(t[i] == 'W')T += p[i];
    	else if(t[i] == 'B') T += 2 * p[i];
    }
    // dbg(S, T);
    auto adj = [&](int x) -> vector<int>{
    	int v = x;
    	vector<int> temp;
    	while(x){
    		temp.push_back(x % 3);
    		x /= 3;
    	}
    	while(temp.size() < n + 2)temp.push_back(0);
    	vector<int> res;
    	int pos = -1;
    	for(int i = 0; i <= n; i++){
    		if(temp[i] == 0){
    			pos = i;
    			break;
    		}
    	}
    	assert(pos != -1);
    	for(int i = 0; i <= n; i++){
    		if(temp[i] && temp[i + 1]){
    			int u = v - temp[i] * p[i] - temp[i + 1] * p[i + 1];
    			u += temp[i] * p[pos] + temp[i + 1] * p[pos + 1];
    			res.push_back(u);
    		}
    	}
    	return res;
    };
    auto bfs = [&]() -> void{
    	queue<int> q;
    	q.push(S);
    	dis[S] = 0;
    	vis[S] = 1;
    	while(!q.empty()){
    		int u = q.front();
    		q.pop();
    		for(auto v : adj(u)){
    			// dbg(u, v);
    			if(vis[v])continue;
    			vis[v] = 1;
    			dis[v] = dis[u] + 1;
    			q.push(v);
    		}
    	}
    };
    bfs();
    cout << dis[T] << '\n';
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