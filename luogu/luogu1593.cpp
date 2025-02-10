#include<bits/stdc++.h>//需要考虑逆元为负
#define int long long
using namespace std;
const int mod=9901;
int qmi(int a,int b){
	int res=1%mod;
	a%=mod;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int js(int a,int b){
	return ((qmi(a,b)-1)*qmi(a-1,mod-2)%mod);//注意如果a与mod的余数为1则这个等式会等0;
}
int g(int n,int b){
	int ans=1;
	for(int i=2;i<=n/i;i++){
		if(n%i==0){
			int cnt=0;
			while(n%i==0)n/=i,cnt++;
			if(i%mod==1){
				ans=ans*(cnt+1)%mod;
			}else{
				ans*=js(i,b*cnt+1);
			}
			ans=(ans%mod+mod)%mod;
		}
	}
	if(n>1){
		if(n%mod==1){
			ans=ans*(n+1)%mod;
		}else{
			ans*=js(n,b+1);
		}
		ans=(ans%mod+mod)%mod;
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b;cin>>a>>b;
	cout<<g(a,b);
	return 0;
}
