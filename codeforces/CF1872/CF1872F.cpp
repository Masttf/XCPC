#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>g(n+1),val(n+1);
	for(int i=1;i<=n;i++)cin>>g[i];
	for(int i=1;i<=n;i++)cin>>val[i];
	stack<int>s;
	vector<int>dfn(n+1);
	vector<int>low(n+1);
	vector<int>instack(n+1);
	int num=0;
	vector<int>res;
	auto tarjan = [&](auto tarjan,int x)->void{
		dfn[x]=low[x]=++num;
		s.push(x);
		instack[x]=1;
		if(!dfn[g[x]]){
			tarjan(tarjan,g[x]);
			low[x]=min(low[x],low[g[x]]);
		}else if(instack[g[x]]) low[x]=min(low[x],dfn[g[x]]);
		if(dfn[x]==low[x]){
			int sz=0;
			int mi=INT_MAX;
			int id=-1;
			int temp;
			do{
				temp=s.top();
				s.pop();
				instack[temp]=0;
				if(mi>val[temp])mi=val[temp],id=temp;
				sz++;
			}while(temp!=x);
			if(sz>1){
				res.push_back(id);
			}
		}
	};
	for(int i=1;i<=n;i++){
		if(!dfn[i])tarjan(tarjan,i);
	}
	vector<int>du(n+1);
	for(int i=1;i<=n;i++){
		du[g[i]]++;
	}
	vector<int>vis(n+1);
	for(auto x:res)vis[x]=1,du[g[x]]--;
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(du[i]==0)q.push(i);
	}
	vector<int>ans;
	while(!q.empty()){
		int root=q.front();
		q.pop();
		if(vis[root])continue;
		ans.push_back(root);
		du[g[root]]--;
		if(du[g[root]]==0)q.push(g[root]);
	}
	for(auto x:ans)cout<<x<<' ';
	for(auto x:res)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
