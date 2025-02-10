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
void solve(){
	int n,m;cin>>n>>m;
	vector<vector<int>>g(n+1);
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>b(n+1);
	vector<int>res;
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(!a[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		b[u]++;
		res.push_back(u);
		for(auto x:g[u]){
			b[x]++;
			if(b[x]==a[x]){
				q.push(x);
			}
		}
	}
	sort(res.begin(),res.end());
	cout<<res.size()<<'\n';
	for(auto x:res)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}