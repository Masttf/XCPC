#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
vector<int>g[maxn];
int ans[maxn],cnt[maxn];
int n,m;
queue<int>q;
void bfs(){
	for(int i=1;i<=n;i++){
		if(cnt[i]==0){
			ans[i]=1;
			q.push(i);
		}
	}
	while(!q.empty()){
		int temp=q.front();q.pop();
		for(int i=0;i<g[temp].size();i++){
			ans[g[temp][i]]=max(ans[g[temp][i]],ans[temp]+1);
			if(--cnt[g[temp][i]]==0){
				q.push(g[temp][i]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		cnt[y]++;
	}
	bfs();
	for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
	return 0;
}
