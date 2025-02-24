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
constexpr int Max = 1e18;
void solve(){
    int n, m; cin >> n >> m;
    vector<array<int, 3>>edge(m);
    vector<int>dis(n + 1, Max);
    dis[0] = 0;
    for(int i = 0; i < m; i++){
    	int u, v, c; cin >> u >> v >> c;
    	edge[i] = {v, u, c};
    }
    for(int i = 1; i <= n; i++){
    	edge.push_back({0, i, 0});
    }
    for(int i = 1; i <= n + 1; i++){
    	int ok = 0;
    	for(auto [u, v, w] : edge){
    		if(dis[v] > dis[u] + w){
    			ok = 1;
    			dis[v] = dis[u] + w;
    		}
    	}
    	if(!ok)break;
    	if(i == n + 1 && ok){
    		cout << "NO\n";
    		return ;
    	}
    }
    for(int i = 1; i <= n; i++){
    	cout << dis[i] << ' ';
    }
    cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}