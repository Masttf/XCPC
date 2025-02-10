#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,maxn=2e5+5;
int f[maxn],inv[maxn];
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
	f[0]=inv[0]=1;
	for(int i=1;i<maxn;i++){
		f[i]=f[i-1]*i%mod;
		inv[i]=qmi(f[i],mod-2);
	}
	return ;
}
int c(int a,int b){
	return f[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve(){
	string s;cin>>s;
	int ans=0;
	int res=1;
	int cnt=0;
	int n=s.size();
	for(int i=0;i<n;i++){
		int j=i;
		while(j<n&&s[i]==s[j])j++;
		int len=j-i;
		i=j-1;
		ans+=len-1;
		res=res*len%mod;
		cnt+=len-1;
	}
	res=res*f[cnt]%mod;
	cout<<ans<<' '<<res<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
