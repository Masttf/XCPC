#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2005;
pair<int,int>g[maxn];
bool vis[maxn];
queue<pair<int,int>>q;
int n,d;
void bfs(){
	q.push({g[1].first,g[1].second});
	vis[1]=1;
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			int a=g[i].first,b=g[i].second;
			if((a-x)*(a-x)+(b-y)*(b-y)<=d*d){
				vis[i]=1;
				q.push({g[i].first,g[i].second});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>g[i].first>>g[i].second;
	bfs();
	for(int i=1;i<=n;i++){
		if(vis[i])cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
