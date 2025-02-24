#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
vector<int>g[maxn];
vector<int>f[maxn];
bool vis[maxn];
bool vis3[maxn];
int n,m;
queue<int>q;
int bfs(){
	q.push(1);
	int cnt=0;
	vis[1]=1;
	while(!q.empty()){
		int sz=q.size();
		for(int j=1;j<=sz;j++){
			int root=q.front();q.pop();
			for(auto i:f[root]){
				if(vis3[i])continue;
				vis3[i]=1;
				for(auto v :g[i]){
					if(!vis[v])q.push(v),vis[v]=1;
				}
			}
		}
		if(vis[m])return cnt;
		cnt++;
	}
	return -1;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int nu;cin>>nu;
		for(int j=1;j<=nu;j++){
			int x;cin>>x;
			g[i].push_back(x);
			f[x].push_back(i);
		}
	}
	cout<<bfs();
	return 0;
}
