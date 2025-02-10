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
	int n;cin>>n;
	vector<vector<int>>g(n+1);
	vector<int>du(n+1);
	vector<int>val(n+1);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int v;cin>>v;
			g[v].push_back(i);
			du[i]++;
		}
	}
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(!du[i]){
			val[i]=1;
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			du[v]--;
			if(!du[v])q.push(v);
			int d=val[u];
			if(u>v)d++;
			val[v]=max(val[v],d);
		}
	}
	for(int i=1;i<=n;i++){
		if(du[i]){
			cout<<-1<<'\n';
			return ;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,val[i]);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}