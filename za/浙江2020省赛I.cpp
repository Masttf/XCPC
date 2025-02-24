#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int f[maxn],sz[maxn];
int a[maxn],b[maxn];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void me(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa==fb)return ;
	f[fb]=fa;
	sz[fa]+=sz[fb];
	return ;
}
void solve(){
	unordered_map<int,int>m;
	int n;cin>>n;
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(m.count(a[i]))a[i]=m[a[i]];
		else m[a[i]]=++cnt,a[i]=cnt;
		if(m.count(b[i]))b[i]=m[b[i]];
		else m[b[i]]=++cnt,b[i]=cnt;
	}
	for(int i=1;i<=n;i++){
		me(a[i],b[i]);
	}
	int mx=1;
	for(int i=1;i<=n;i++){
		if(f[i]==i)mx=max(mx,sz[i]);
	}
	cout<<mx<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
