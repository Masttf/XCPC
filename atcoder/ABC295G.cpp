#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int f[maxn],son[maxn];
int n;
int g[maxn];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa==fb)return ;
	int p=fa;
	while(p!=fb){
		p=find(g[fa]);//直接让他自己去找他的父节点
		f[p]=fa;//合并
		son[fa]=min(son[fa],son[p]);//更新
		g[fa]=g[p];//更新指向
	}
	return ;
}
signed main(){//每个点都只会被一个点指向
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n-1;i++){
		int u;cin>>u;
		g[i+1]=u;
	}
	for(int i=1;i<=n;i++)son[i]=i,f[i]=i;
	int q;cin>>q;
	while(q--){
		int t;cin>>t;
		if(t==1){
			int u,v;
			cin>>u>>v;
			merge(u,v);
		}else{
			int x;cin>>x;
			cout<<son[find(x)]<<'\n';
		}
	}
	return 0;
}
