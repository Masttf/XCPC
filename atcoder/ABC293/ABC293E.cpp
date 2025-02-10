#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod;
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
int js(int a,int x){
	if(x==1)return 1;
	if(x%2==0){
		return (qmi(a,x/2)+1)*js(a,x/2)%mod;
	}else{
		return (qmi(a,x-1)+js(a,x-1))%mod;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,x;cin>>a>>x>>mod;// 分治法求等比数列和
	int ans=js(a,x);
	ans%=mod;
	cout<<(ans+mod)%mod;
	return 0;
}
