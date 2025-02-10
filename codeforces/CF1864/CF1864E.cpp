#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int maxn=2e5+5;
int t[maxn*20][2];
int cnt[maxn*20];
int tot=1;
int ans;
void add (int x){
	int p=1;
	for(int i=32;i>=0;i--){
		int d=(x>>i)&1;
		if(!t[p][d])t[p][d]=++tot,memset(t[tot],0,sizeof t[tot]),cnt[tot]=0;
		p=t[p][d];
		cnt[p]++;
	}
	return ;
}
void get (int x){
	int p=1;
	int ct=0;
	for(int i=32;i>=0;i--){
		int d=(x>>i)&1;
		if(d==1){
			if(ct%2==0){
				ans+=cnt[t[p][1-d]]*(ct+2);
			}else{
				ans+=cnt[t[p][1-d]]*(ct+1);
			}
		}else{
			if(ct%2==0){
				ans+=cnt[t[p][1-d]]*(ct+1);
			}else{
				ans+=cnt[t[p][1-d]]*(ct+2);
			}
		}
		if(ans>mod)ans%=mod;
		p=t[p][d];
		if(d==1)ct++;
	}
	ct++;
	ans+=cnt[p]*ct;
	if(ans>mod)ans%=mod;
};
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
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	ans=0;
	tot=1;
	memset(t[tot],0,sizeof t[tot]);
	for(int i=1;i<=n;i++)add(a[i]);
	for(int i=1;i<=n;i++){
		get(a[i]);
	}
	ans%=mod;
	//cout<<ans<<' ';
	ans=ans*qmi(n*n%mod,mod-2)%mod;
	ans=(ans+mod)%mod;
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
