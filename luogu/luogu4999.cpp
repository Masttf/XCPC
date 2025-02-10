#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int f[20][10];
int qpow(int a,int b){
	int res=1%mod;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void init(){
	for(int i=0;i<=9;i++)f[1][i]=i;
	for(int i=2;i<20;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<=9;k++){
				f[i][j]+=f[i-1][k]+j*qpow(10,i-2);
				f[i][j]%=mod;
			}
		}
	}
	return ;
}
int dp(int n){
	if(!n) return 0;
	vector<int>num;
	while(n)num.push_back(n%10),n/=10;
	int res=0;
	int last=0;
	for(int i=num.size()-1;i>=0;i--){
		int x=num[i];
		for(int j=0;j<x;j++)res+=f[i+1][j]+qpow(10,i)*last,res%=mod;
		last+=x;
		if(!i)res+=last;
	}
	return res;
}
void solve(){
	int l,r;cin>>l>>r;
	cout<<(dp(r)-dp(l-1)+mod)%mod<<'\n';
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
