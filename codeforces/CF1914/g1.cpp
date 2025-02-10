#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
void solve(){
	int n;cin>>n;
	vector<int>a(2*n+1);
	for(int i=1;i<=2*n;i++)cin>>a[i];
	vector g(n+1,vector<int>());
	vector<int>stk;
	vector<int>cnt(n+1);
	vector bl(n+1,vector<int>());
	for(int i=1;i<=2*n;i++){
		while(!stk.empty()&&cnt[stk.back()]==2)stk.pop_back();
		cnt[a[i]]++;
		if(cnt[a[i]]==1){
			if(!stk.empty())g[stk.back()].push_back(a[i]);
			stk.push_back(a[i]);
			bl[stk[0]].push_back(a[i]);
		}else{
			if(!stk.empty()&&stk.back()!=a[i]){
				g[stk.back()].push_back(a[i]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!bl[i].empty())ans++;
	}
	int res=1;
	vector<int>vis(n+1);
	auto bfs = [&](int s)->void{
		queue<int>q;
		q.push(s);
		vis[s]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:g[u]){
				if(vis[v])continue;
				q.push(v);
				vis[v]=1;
			}
		}
	};
	for(int i=1;i<=n;i++){
		if(bl[i].empty())continue;
		int num=0;
		for(auto x:bl[i]){
			vis.assign(n+1,0);
			bfs(x);
			int res=0;
			for(int j=1;j<=n;j++){
				if(vis[j])res++;
			}
			if(res==bl[i].size())num++;
		}
		res=res*num%mod*2%mod;
	}
	cout<<ans<<' '<<res<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}