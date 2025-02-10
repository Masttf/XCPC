#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int mod=998244353;
struct node{
	int u,v,w;
	node (int _u,int _v,int _w):u(_u),v(_v),w(_w){}
	bool operator <(const node&y)const{
		return w<y.w;
	}
};
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void solve(){
	long long n,s;cin>>n>>s;
	vector<node>e;
	vector<int>f(n+1);
	vector<int>sz(n+1);
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
	auto find = [&](auto find,int x)->int{
		if(f[x]==x)return x;
		else return f[x]=find(find,f[x]);
	};
	for(int i=1;i<=n-1;i++){
		long long u,v,w;cin>>u>>v>>w;
		e.push_back(node(u,v,w));
	}
	sort(e.begin(),e.end());
	int ans=1;
	for(auto [u,v,w]:e){
		int fa=find(find,u),fb=find(find,v);
		int d1=((sz[fa]-1)*(sz[fb]-1)+sz[fa]-1+sz[fb]-1);
		int d2=(s-w)%mod;
		ans*=qmi(d2+1,d1);
		ans%=mod;
		sz[fa]+=sz[fb];
		f[fb]=fa;
	}
	if(ans<0)ans+=mod;
	long long tem=ans; 
	cout<<tem<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long t;cin>>t;
	while(t--)solve();
	return 0;
}
