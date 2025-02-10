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
	int n;cin>>n;
	vector g(n+1,vector<int>());
	vector<int>du(n+1);
	for(int i=1;i<=n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		du[u]++;
		du[v]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(du[i]==1)q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		//dbg(u);
		q.pop();
		for(auto v:g[u]){
			du[v]--;
			if(du[v]==1)q.push(v);
		}
	}
	for(int i=1;i<=n;i++){
		if(du[i]>1)cout<<i<<' ';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}