#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<vector<int>>pos(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]].push_back(i);
	}
	
	vector<int>vis(n+1,-1);
	vector<int>mx(n+1);
	vector<vector<int>>g1(n+1);
	vector<vector<int>>g2(n+1);
	for(int i=1;i<=n;i++){
		for(auto v:pos[i]){
			g1[i].push_back(v);
			g2[v].push_back(i);
		}
	}

	int ok=1;
	auto dfs = [&](auto dfs,int now)->void{
		if(vis[now]==0){
			for(auto v:g1[now]){
				if(vis[v]!=-1){
					if(vis[v]==0){
						ok=0;
						return ;
					}
				}else{
					vis[v]=1;
					dfs(dfs,v);
				}
			}
			for(auto v:g2[now]){
				if(vis[v]!=-1){
					if(vis[v]==0){
						ok=0;
						return ;
					}
				}else{
					vis[v]=1;
					dfs(dfs,v);
				}
			}
		}else{
			for(auto v:g2[now]){
				mx[v]++;
				if(mx[v]==pos[v].size()){
					if(vis[v]!=-1){
						if(vis[v]==1){
							ok=0;
							return ;
						}
					}else{
						vis[v]=0;
						dfs(dfs,v);
					}
				}
			}
		}
	};
	
	for(int i=1;i<=n;i++){
		if(pos[i].size()==0){
			vis[i]=0;
			dfs(dfs,i);
		}
	}

	for(int i=1;i<=n;i++){
		if(vis[i]==-1){
			vis[i]=0;
			dfs(dfs,i);
		}
	}
	if(ok==0){
		cout<<-1<<'\n';
		return ;
	}
	vector<int>ans;
	for(int i=1;i<=n;i++){
		if(!vis[i])ans.push_back(a[i]);
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans)cout<<x<<' ';
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