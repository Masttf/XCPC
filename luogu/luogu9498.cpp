#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+6;
vector<int>g[maxn];
int deep[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	auto dfs = [&](auto dfs,int u,int father)->void{
		deep[u]=deep[father]+1;
		for(auto v:g[u]){
			if(v==father)continue;
			dfs(dfs,v,u);
		}
	};
	dfs(dfs,1,0);
	vector<pair<int,int>>res(n+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		res[i].first=deep[i];
		res[i].second=i;
		sum+=deep[i];
	}
	if(sum%2==1){
		cout<<-1<<'\n';
		return 0;
	}
	sort(res.begin(),res.end());
	vector<int>ans(n+1);
	int tot=0;
	for(int i=1;i<=n;i++){
		tot+=res[i].first;
		ans[res[i].second]=1;
		if(tot>=sum/2){
			tot-=sum/2;
			for(int j=1;j<=i;j++){
				if(res[j].first==tot){
					ans[res[j].second]=0;
					break;
				}
			}
			break;
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}
