#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,maxn=2e5+5;
int t[maxn];
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
	string s;cin>>s;//中位数只要这个数的个数>=另一个
	int ans=0,len=1;
	for(int i=0;i<n;i++){
		if(i&&s[i]==s[i-1]){//为后缀最长的相同的部分
			len++;
		}else len=1;
		ans=(ans+qmi(2,len-1))%mod;
	}
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
