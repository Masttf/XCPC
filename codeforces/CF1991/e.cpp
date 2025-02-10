#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>>g(n + 1);
    for(int i = 1; i <= m; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    int ok = 1;
    vector<int> color(n + 1);
    auto dfs = [&](auto self, int now) -> void{
    	for(auto v : g[now]){
    		if(!color[v]){
    			color[v] = 3 - color[now];
    			self(self, v);
    		}else if(color[v] == color[now])ok = 0;
    	}
    };
    for(int i = 1; i <= n; i++){
    	if(!color[i]){
    		color[i] = 1;
    		dfs(dfs, i);
    	}
    }
    if(!ok){
    	cout << "Alice" << endl;
    	for(int i = 1; i <= n; i++){
    		cout << 1 <<' ' << 2 << endl;
    		int x, y; cin >> x >> y;
    	}
    }else{
    	cout << "Bob" << endl;
    	vector res(3, vector<int>());
    	for(int i = 1; i <= n; i++){
    		res[color[i]].push_back(i);
    	}
    	
    	for(int i = 1; i <= n; i++){
    		int a, b; cin >> a >> b;
    		if(a > b)swap(a, b);
    		if(!res[a].empty()){
    			cout << res[a].back() <<' ' << a << endl;
    			res[a].pop_back();
    		}else{
    			if(b == 2){
    				cout << res[2].back() <<' ' << 2 << endl;
    				res[2].pop_back();
    			}else{
    				if(!res[1].empty()){
    					cout << res[1].back() <<' ' << 3 << endl;
    					res[1].pop_back();
    				}else{
    					cout << res[2].back() <<' ' << 3 << endl;
    					res[2].pop_back();
    				}
    			}
    		}
    	}
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