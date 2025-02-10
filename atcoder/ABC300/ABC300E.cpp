#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int p;int n;
map<int,int>m;
int dfs(){
	if(n==1)return 1;
	if(m.count(n))return m[n];
	int res=0;
	for(int i=min(n,6LL);i>=2;i--){
		if(n%i!=0)continue;
		n/=i;
		res+=dfs();
		res%=mod;
		n*=i;
	}
	res=res*p%mod;
	return m[n]=res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	p=qmi(5,mod-2);
	cout<<dfs();
	return 0;
}
