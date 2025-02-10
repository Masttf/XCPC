#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
//constexpr int mod=1e9+7;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	vector<vector<int>>g(n+1); 
	int root=-1;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(!x)root=i;
		else g[x].push_back(i);
	}
	int db=131;
	vector<int>p(n+1);
	p[0]=1;
	for(int i=1;i<=n;i++)p[i]=p[i-1]*db;
	vector<int>dep(n+1);
	vector<vector<int>>f(25,vector<int>(n+1));
	vector<vector<int>>fp(25,vector<int>(n+1));
	vector<vector<int>>fs(25,vector<int>(n+1));
	auto dfs = [&](auto self,int now,int father)->void{
		dep[now]=dep[father]+1;
		f[0][now]=father;
		fp[0][now]=s[father]-'a'+1;
		fs[0][now]=s[father]-'a'+1;
		for(int i=1;(1ll<<i)<dep[now];i++){
			f[i][now]=f[i-1][f[i-1][now]];
			fp[i][now]=fp[i-1][now]*p[(1ll<<(i-1))]+fp[i-1][f[i-1][now]];
			fs[i][now]=fs[i-1][now]+fs[i-1][f[i-1][now]]*p[(1ll<<(i-1))];
		}
		for(auto v:g[now]){
			self(self,v,now);
		}
		return ;
	};
	dfs(dfs,root,0);
	
	auto lca = [&](int a,int b)->bool{
		if(dep[a]<dep[b])swap(a,b);
		int len1=1;
		int val1=s[a]-'a'+1;
		int val2=s[a]-'a'+1;
		int len2=1;
		int val3=s[b]-'a'+1;
		int val4=s[b]-'a'+1;
		//dbg(a,b,val1,val2,val3,val4);
		for(int i=20;i>=0;i--){
			if(dep[a]-(1ll<<i)>=dep[b]){
				val1=val1*p[1<<i]+fp[i][a];
				val2=fs[i][a]*p[len1]+val2;
				len1+=(1ll<<i);
				a=f[i][a];
				//dbg(val1,val2,i);
			}
		}
		if(a==b)return val1==val2;
		for(int i=20;i>=0;i--){
			if(f[i][a]!=f[i][b]){
				val1=val1*p[1<<i]+fp[i][a];
				val2=fs[i][a]*p[len1]+val2;
				len1+=(1ll<<i);
				val3=val3*p[1<<i]+fp[i][b];
				val4=fs[i][b]*p[len2]+val4;
				len2+=(1ll<<i);
				a=f[i][a];
				b=f[i][b];
				//dbg(a,b,val1,val2,val3,val4);
			}
		}
		//dbg(val1,val2,val3,val4);
		val1=val1*db+fp[0][a];
		val2=val2+fs[0][a]*p[len1];
		//dbg(val1,val2,val3,val4,len1);
		len1++;
		val1=val1*p[len2]+val4;
		val2=val2+val3*p[len1];
		//dbg(val1,val2,val3,val4);
		return val1==val2;
	};	
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		if(lca(u,v))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}