#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,maxn=105;
int f[maxn][maxn];
int n,q,r;
int pa,pb;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int dfs(int a,int b){
	
	if(b>=n)return 0;
	if(f[a][b])return f[a][b];
	if(b>a&&r!=1){//剪枝
		if(b+(b-a)/(r-1)>n)return f[a][b]=0;//注意b是后走
	}
	if(a>b&&q!=1){
		if(a+(a-b)/(q-1)>=n)return f[a][b]=1;
	}
	int res=0;
	for(int i=1;i<=r;i++){
		if(a+i>=n){
			
			res+=pa*(r-i+1)%mod;
			res%=mod;
			//if(a==4&&b==4)cout<<"pa*(r-i+1)"<<' '<<res<<'\n';
			break;
		}
		for(int j=1;j<=q;j++){
			if(b+j>=n)break;
			res=(res+pa*pb%mod*dfs(a+i,b+j)%mod)%mod;
			//if(a==4&&b==4)cout<<"pa*pb*f["<<a+i<<']'<<'['<<b+j<<']'<<' '<<res<<'\n';
		}	
	} 
	return f[a][b]=res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b;
	cin>>n>>a>>b>>r>>q;
	pa=qmi(r,mod-2);
	pb=qmi(q,mod-2);
	int ans=dfs(a,b);
//	for(int i=1;i<=14;i++){
//		for(int j=1;j<=14;j++)cout<<i<<' '<<j<<' '<<f[i][j]<<'\n';
//	}
	cout<<ans;
	return 0;
}
