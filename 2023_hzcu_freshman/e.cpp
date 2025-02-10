#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>st(m+1);
	vector<int>ed(m+1);
	for(int i=1;i<=n;i++){
		if(!st[a[i]])st[a[i]]=i;
		ed[a[i]]=i;
	}
	vector<int>p1(n+1),p2(n+1);
	for(int i=1;i<=m;i++){
		p1[st[i]]=i;
		p2[ed[i]]=i;
	}
	// for(int i=1;i<=n;i++){
	// 	cout<<p1[i]<<' ';
	// }
	// cout<<'\n';
	// for(int i=1;i<=n;i++){
	// 	cout<<p2[i]<<' ';
	// }
	// cout<<'\n';
	vector g(m+1,vector<int>());
	vector<int>du(m+1);
	vector<int>stk;
	for(int i=1;i<=n;i++){
		if(p1[i]){
			if(stk.empty())stk.push_back(a[i]);
			else{
				int u=stk.back();
				if(ed[u]<ed[a[i]]){
					cout<<"NO\n";
					return ;
				}else{
					g[a[i]].push_back(u);
					du[u]++;
					stk.push_back(a[i]);
				}
			}
		}
		if(p2[i]){
			if(a[i]!=stk.back()){
				cout<<"NO\n";
				return ;
			}else stk.pop_back();
		}
		if(p1[i]||p2[i])continue;
		if(stk.back()==a[i])continue;
		g[a[i]].push_back(stk.back());
		du[stk.back()]++;
	}
	vector<int>ans;
	queue<int>q;
	for(int i=1;i<=m;i++){
		if(!du[i])q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		ans.push_back(u);
		for(auto v:g[u]){
			du[v]--;
			if(du[v]==0)q.push(v);
		}
	}
	for(int i=1;i<=m;i++){
		if(du[i]){
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
	reverse(ans.begin(),ans.end());
	for(auto x:ans)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}