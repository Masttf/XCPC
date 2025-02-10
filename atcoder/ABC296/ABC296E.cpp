#include<bits/stdc++.h>//看是不是成环就是可以
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
vector<int>g[maxn],belong[maxn];
bool instack[maxn];
int dfn[maxn],low[maxn],idx,cnt,po[maxn];
stack<int>s;
void tarjan(int u){
	dfn[u]=low[u]=++idx;
	s.push(u);
	instack[u]=1;
	for(auto v:g[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(instack[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		cnt++;
		int temp;
		do{
			temp=s.top();
			s.pop();
			instack[temp]=0;
			belong[cnt].push_back(temp);
			po[temp]=cnt;
		}while(temp!=u);
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==i)continue;
		g[i].push_back(a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==i)continue;
		if(!dfn[i])tarjan(i);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==i||belong[po[i]].size()>1)ans++;
	}
	cout<<ans;
	return 0;
}

