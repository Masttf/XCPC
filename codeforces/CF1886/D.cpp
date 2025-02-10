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
void solve(){
	int n,m;cin>>n>>m;
	string s;cin>>s;
	s=' '+s;
	int ans=1;
	for(int i=2;i<=n-1;i++){
		if(s[i]=='?')ans=ans*(i-1)%mod;
	}
	auto ask = [&]()->void{
		if(s[1]=='?'){
			cout<<0<<'\n';
		}else cout<<ans<<'\n';
	};
	ask();
	for(int i=1;i<=m;i++){
		int x;char temp;
		cin>>x>>temp;
		if(x!=1&&s[x]=='?'){
			ans=ans*qmi(x-1,mod-2)%mod;
		}
		s[x]=temp;
		if(x!=1&&temp=='?'){
			ans=ans*(x-1)%mod;
		}
		ask();
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}