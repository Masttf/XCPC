#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int f[maxn];
int find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
void merge(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa==fb)return ;
	f[fa]=fb;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		merge(u,v);
	}
	for(int i=1;i<=n;i++)f[i]=find(i);
	int k;cin>>k;
	map<pair<int,int>,int>res;
	int ok=1;
	for(int i=1;i<=k;i++){
		int u,v;cin>>u>>v;
		if(f[u]==f[v])ok=0;
		res[{f[u],f[v]}]=1;
		res[{f[v],f[u]}]=1;
	}
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		if(ok==0)cout<<"No\n";
		else{
			if(res.count({f[u],f[v]})||res.count({f[v],f[u]}))cout<<"No\n";
			else cout<<"Yes\n";
		}
	}
	return 0;
}
