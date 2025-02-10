#include<bits/stdc++.h>//求最大颜色的数量即一次会改两个分块，
#define int long long//如果三条边都相同对一种方案有3种填法
using namespace std;//如果第二大和第三大一样2种填法
const int mod=998244353;//其余1
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
signed main(){//首先分配颜色 红蓝蓝 蓝红红有Cn/3/2 n/3
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	int cnt=1;
	for(int i=1;i<=n/3;i++){
		int a,b,c;cin>>a>>b>>c;
		int mx=max(c,max(a,b));
		int mi=min(c,min(a,b));
		int t=a+b+c-mx-mi;
		if(mx==mi){//说明三条边一样
			cnt*=3;
		}else if(t==mi){
			cnt*=2;
		}
		cnt%=mod;
	}
	int ans=1;
	for(int i=n/3,j=1;j<=n/6;i--,j++){
		ans=ans*i%mod;
		ans=ans*qmi(j,mod-2)%mod;
	}
	ans=ans*cnt%mod;
	cout<<(ans+mod)%mod;
	return 0;
}
