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
struct node{
	int u, v, t, ty, id;
};
void solve(){
    int n, m; cin >> n >> m;
    vector<int>ans(m + 1), d(n + 1);
    cin >> ans[1];
    vector<node> op;
    for(int i = 1; i <= m; i++){
    	int u, v, s, t; cin >> u >> v >> s >> t;
    	op.push_back({u, v, s, 0, i});
    	op.push_back({u, v, t, 1, i});
    }
    sort(op.begin(), op.end(), [&](node x, node y) -> bool{
    	if(x.t != y.t)return x.t < y.t;
    	return x.ty > y.ty;
    });
    for(auto [u, v, t, ty, id] : op){
    	if(ty == 0){
    		ans[id] = max(ans[id], d[u] - t);
    	}else{
    		d[v] = max(d[v], ans[id] + t);
    	}
    }
    for(int i = 2; i <= m; i++){
    	cout << ans[i] << " ";
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