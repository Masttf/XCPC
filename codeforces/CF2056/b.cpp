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
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> du(n + 1);
    for(int i = 1; i <= n; i++){
    	string s; cin >> s;
    	s = ' ' + s;
    	for(int j = i + 1; j <= n; j++){
    		if(s[j] == '1'){
    			g[i].push_back(j);
    			du[j]++;
    		}
    	}
    }
    vector<int> ans;
    priority_queue<int> q;
    for(int i = 1; i <= n; i++){
    	if(du[i] == 0)q.push(i);
    }
    while(!q.empty()){
    	int u = q.top();
    	q.pop();
    	ans.push_back(u);
    	for(auto v : g[u]){
    		du[v]--;
    		if(du[v] == 0){
    			q.push(v);
    		}
    	}
    }
    for(auto x : ans)cout << x << ' ';
    cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
/*
无向
先考虑第一个放啥
p1 ... p2
1 he 其他
*/