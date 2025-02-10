#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]!=i){
				cout<<"NO\n";
				return ;
			}
		}
		cout<<"YES\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			cout<<"NO\n";
			return ;
		}
	}
	int ok=1;
	vector<vector<int>>g(n+1,vector<int>());
	for(int i=1;i<=n;i++){
		g[i].push_back(a[i]);
	}
	vector<int>low(n+1),dfn(n+1);
	vector<int>instack(n+1);
	stack<int>s;
	int tot=1;
	auto tarjan = [&](auto tarjan,int u)->void{
		dfn[u]=low[u]=tot++;
		s.push(u);
		instack[u]=1;
		for(auto v:g[u]){
			if(!dfn[v]){
				tarjan(tarjan,v);
				low[u]=min(low[u],low[v]);
			}else if(instack[v]){
				low[u]=min(low[u],dfn[v]);
			}
		}
		if(dfn[u]==low[u]){
			int len=0;
			int temp;
			do{
				temp=s.top();s.pop();
				instack[temp]=0;
				len++;
			}while(temp!=u);
			if(len>1&&len!=k)ok=0;
		}
	};
	
	for(int i=1;i<=n;i++){
		if(!dfn[i])tarjan(tarjan,i);
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
