#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=6e4+5;
vector<pair<int,int>>g[maxn];
//首先n方 连边不行
//因为字母数为26*26 所以对每种都建一个点 这样建图就是On
//同时连向这个虚点的边权为0 连出为1 因为跳跃嘛得有进有出总和为1
//再考虑每次跑最短路时间会TLE
//所以考虑它到终点要不要经过一次跳跃，为什么呢
//因为虚点一共是26*26 这样就只需要对每种虚点进行最短路
//然后起始点到这个虚点的距离（每种虚点都枚举一下）；
void solve(){
	string s;cin>>s;
	int n=s.size();
	s=' '+s;
	
	map<pair<char,char>,vector<int>>mp;
	int m;cin>>m;
	vector<int>ans(m+1);
	vector<int>f(m+1),t(m+1);
	for(int i=1;i<=m;i++)cin>>f[i]>>t[i],ans[i]=abs(f[i]-t[i]);
	for(int i=1;i<n;i++){
		mp[{s[i],s[i+1]}].push_back(i);
	}
	for(int i=1;i<n-1;i++){
		g[i].push_back({i+1,1});
		g[i+1].push_back({i,1});
	}
	int tot=n-1;
	for(auto it:mp){
		tot++;
		for(auto x:it.second){
			g[tot].push_back({x,1});
			g[x].push_back({tot,0});
		}
	}
	vector<int>dis(tot+1,INT_MAX);
	auto bfs= [&](int x)->void{
		dis=vector<int>(tot+1,INT_MAX);
		deque<int>q;
		dis[x]=0;
		q.push_back(x);
		while(!q.empty()){
			int root=q.front();
			q.pop_front();
			for(auto &[v,w]:g[root]){
				if(dis[v]>dis[root]+w){
					dis[v]=dis[root]+w;
					if(w==0)q.push_front(v);
					else q.push_back(v);
				}
			}
		}
		return ;
	};
	int temp=n-1;
	for(auto it:mp){
		temp++;
		bfs(temp);
		vector<int>nrest(n+1);
		int l=0;
		for(auto x:it.second){
			if(l==0){
				for(int i=1;i<=x;i++)nrest[i]=x-i;
			}else{
				for(int i=l+1;i<=x;i++)nrest[i]=min(abs(i-l),abs(x-i));
			}
			l=x;
		}
		for(int i=l+1;i<n;i++)nrest[i]=i-l;
		for(int i=1;i<=m;i++)ans[i]=min(ans[i],nrest[f[i]]+dis[t[i]]);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}
