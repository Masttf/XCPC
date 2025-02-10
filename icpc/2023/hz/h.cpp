#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int Max=1e18;
constexpr int maxn=5e5+5;
constexpr int mod=1e9+7;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int f[maxn],inv[maxn];
void init(){
	f[0]=inv[0]=1;
	for(int i=1;i<maxn;i++){
		f[i]=f[i-1]*i%mod;
		inv[i]=qmi(f[i],mod-2);
	}
}
int C(int n,int m){
	if(n<m||m<0)return 0;
	return f[n]*inv[m]%mod*inv[n-m]%mod;
}
void solve(){
	int n;cin>>n;
	vector<int>a(n+1),b(n+1),w(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>w[i];
	vector<int>len(n+1);
	vector dp(2,vector<int>(n+1));
	vector<vector<int>>g(n+1),g2(n+1);
	vector<int>du(n+1),du2(n+1);
	int tot=f[n];
	for(int i=1;i<=n;i++){
		int u=i,v=b[i];
		if(u==v)dp[0][i]=tot;
		else{
			g[u].push_back(v);
			du[v]++;
			g2[v].push_back(u);
			du2[u]++;
		}
	}
	auto get = [&](int x)->int{
		return f[n-x]*C(n,x)%mod;
	};
	auto bfs = [&]()->void{
		queue<int>q;
		for(int i=1;i<=n;i++){
			if(!du[i])q.push(i);
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:g[u]){
				du[v]--;
				if(du[v]==0)q.push(v);
			}
		}
	};
	bfs();
	queue<int>q;
	auto cal = [&](int x)->void{
		int cnt=0;
		int sz=0;
		int now=x;
		int start;
		do{
			if(a[now]>=a[b[now]]&&a[now]<a[b[now]]+w[b[now]])cnt++;
			else start=now;
			sz++;
			now=b[now];
			du[now]--;
		}while(now!=x);
		if(cnt==sz){
			now=x;
			do{
				len[now]=1;
				dp[0][now]=tot;
				now=b[now];
				du2[now]--;
			}while(now!=x);
		}else{
			now=start;
			len[start]=1;
			if(a[start]<a[b[start]])dp[1][start]=tot;
			else dp[0][start]=tot;
			q.push(start);
		}
	};
	for(int i=1;i<=n;i++){
		if(du[i])cal(i);
	}
	for(int i=1;i<=n;i++){
		if(!du2[i]){
			if(a[i]<a[b[i]])dp[1][i]=tot;
			else dp[0][i]=tot;
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g2[u]){
			du2[v]--;
			if(du2[v]==0)q.push(v);
			if(a[v]>=a[u]&&a[v]<a[u]+w[u]&&dp[1][u]){
				len[v]=len[u]+1;
				dp[1][v]=get(len[v]);
				dp[0][v]=(tot+mod-dp[1][v])%mod;
			}else{
				len[v]=1;
				if(a[v]<a[u])dp[1][v]=tot;
				else dp[0][v]=tot;
			}
		}
	}
	int p=inv[n];
	for(int i=1;i<=n;i++){
		int ans=a[i]*dp[0][i]%mod*p%mod+(a[i]+w[i])*dp[1][i]%mod*p%mod;
		ans%=mod;
		cout<<ans<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}