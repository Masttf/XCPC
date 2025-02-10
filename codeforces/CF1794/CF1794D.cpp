#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+100,N=5005,mod=998244353;
int a[M],f[N],fin[N],dp[N][N];
bool vis[M];
map<int,int>m;
vector<int>prim;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void init(){
	vis[1]=1;
	for(int i=2;i<M;i++){//预处理质数
		if(!vis[i])prim.push_back(i);
		for(int j=0;prim[j]*i<M;j++){
			vis[prim[j]*i]=1;
			if(i%prim[j]==0)break;
		}
	}
	f[0]=1;
	fin[0]=1;
	for(int i=1;i<N;i++){
		f[i]=f[i-1]*i%mod;//预处理阶乘
		fin[i]=fin[i-1]*qmi(i,mod-2)%mod;//预处理逆元
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	init();
	int n;cin>>n;
	for(int i=1;i<=n*2;i++)cin>>a[i],m[a[i]]++;
	vector<int>fv;
	int ans=f[n];
	for(auto it=m.begin();it!=m.end();it++){
		if(vis[it->first])ans=ans*fin[it->second]%mod;
		else fv.push_back(it->first);
	}
	int cnt=fv.size();
	if(cnt<n)cout<<0;
	else{
		dp[0][0]=1;
		for(int i=1;i<=cnt;i++){
			int k=m[fv[i-1]];
			dp[i][0]=dp[i-1][0]*fin[k]%mod;
			for(int j=1;j<=i;j++){
				dp[i][j]=dp[i-1][j]*fin[k]%mod+dp[i-1][j-1]*fin[k-1]%mod;
				//cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
			}
		}
		cout<<ans*dp[cnt][n]%mod;
	}
	return 0;
}
