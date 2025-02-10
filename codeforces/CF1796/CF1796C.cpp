#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,maxn=1e6+5;
int two[10000];
void init(){
	two[0]=1;
	for(int i=1;i<1000;i++){
		two[i]=(two[i-1]*2)%mod;
	}
	return ;
}
int qc(int a,int b){
	int ans=0;
	int base=1;
	while(b){
		if(b&1)ans=(ans+base*a)%mod;
		b>>=1;
		base=base*2%mod;
	}
	return ans;
}
void solve(){//每次最大的长度就是i乘2乘2 乘2 ，情况最多就乘一个三
	int l,r;cin>>l>>r;
	if(l==r)cout<<1<<' '<<1<<'\n';
	else{
		int mx=0,ans=0;
		int t=l;
		while(t<=r)t*=2,mx++;
		int rr=r/two[mx-1];
		ans+=rr-l+1;
		if(mx>1){//乘2都不行还乘三
			rr=r/(two[mx-1]/2*3);
			if(rr>=l)ans=(ans+qc(mx-1,rr-l+1))%mod;
		}
		ans%=mod;
		cout<<mx<<' '<<ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	init();
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
