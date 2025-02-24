#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5,mod=998244353;
int f[maxn],finv[maxn];
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
	f[0]=1;finv[0]=1;
	for(int i=1;i<maxn;i++){
		f[i]=f[i-1]*i%mod;
		finv[i]=qmi(f[i],mod-2);
	}
	return ;
}
int c(int x,int y){
	if(x>y)return 0;
	return f[y]*finv[x]%mod*finv[y-x]%mod;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	init();
	int ans=0;
	//cout<<c(2,2)<<'\n';
	if(k==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i*j<k)continue;//容斥算出这个的方案数
			ans+=(c(k,i*j)-2*c(k,(i-1)*j)-2*c(k,i*(j-1))+c(k,(i-2)*j)+c(k,i*(j-2))+4*c(k,(i-1)*(j-1))-2*c(k,(i-2)*(j-1))-2*c(k,(i-1)*(j-2))+c(k,(i-2)*(j-2)))%mod*i%mod*j%mod*(n-i+1)%mod*(m-j+1)%mod;
			ans=(ans+mod)%mod;
			//cout<<c(k,i*j)<<' '<<c(k,(i-1)*j)<<' '<<
			//cout<<ans<<'\n';
		}
	}
	ans*=qmi(c(k,n*m),mod-2);
	ans%=mod;
	cout<<ans;
	return 0;
}
