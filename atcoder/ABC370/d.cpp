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
    int q; cin >> q;
    vector vis(n + 1, vector<int>(m + 1, 1));
    vector<set<int>> row(n + 1);
    vector<set<int>> col(m + 1);
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		row[i].insert(j);
    		col[j].insert(i);
    	}
    }
    while(q--){
    	int x, y; cin >> x >> y;
    	if(vis[x][y]){
    		vis[x][y] = 0;
    		row[x].erase(y);
    		col[y].erase(x);
    	}else{
    		{
    			vector<int>res;
	    		auto it = row[x].lower_bound(y);
	    		if(it != row[x].end()){
	    			res.push_back(*it);
	    		}
	    		if(it != row[x].begin()){
	    			it--;
	    			res.push_back(*it);
	    		}
	    		for(auto t : res){
	    			//dbg(x, t);
	    			row[x].erase(t);
	    			col[t].erase(x);
	    			vis[x][t] = 0;
	    		}
    		}
    		{
    			vector<int>res;
	    		auto it = col[y].lower_bound(x);
	    		if(it != col[y].end()){
	    			res.push_back(*it);
	    		}
	    		if(it != col[y].begin()){
	    			it--;
	    			res.push_back(*it);
	    		}
	    		for(auto t : res){
	    			//dbg(t, y);
	    			col[y].erase(t);
	    			row[t].erase(y);
	    			vis[t][y] = 0;
	    		}
    		}
    	}
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++)ans += vis[i][j];
    }
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}