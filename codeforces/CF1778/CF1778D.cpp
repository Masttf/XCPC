#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int maxn=1e6+5;
int g[maxn];//定义g[i]为i个不同走到i-1个不同需要的步数
//g[i]=i/n+(n-i)/k*(1+g[i+1]+g[i]);
//g[i]=n/i+(n-i)/i *(g[i+1])
//另一种定义g[i]为从k个不同走到0个步数
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
	int n;cin>>n;
	string a,b;cin>>a>>b;
	g[n]=1;
	for(int i=n-1;i>=1;i--){
		int t=qmi(i,mod-2);
		g[i]=n*t%mod+(n-i)*t%mod*g[i+1]%mod;
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i])cnt++;
	}
	int ans=0;
	for(int i=0;i<=cnt;i++)ans=(ans+g[i])%mod;
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
