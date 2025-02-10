#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7,maxn=5e5+5;
int a[maxn],cnt[65];
void solve(){//拆位算贡献，首先算这个一个数与所有数的与和expand+=(1LL<<j)%mod*cnt[j]%mod;
	for(int i=0;i<=60;i++)cnt[i]=0;
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=60;j++){
			cnt[j]+=a[i]>> j & 1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int expor=0,expand=0;
		for(int j=0;j<=60;j++){
			if(a[i]>>j&1){
				expor=(expor+(1LL<<j)%mod*n%mod)%mod;
				expand=(expand+(1LL<<j)%mod*cnt[j]%mod)%mod;
			}else expor=(expor+(1LL<<j)%mod*cnt[j]%mod)%mod;
		}
		ans=(ans+expor*expand%mod)%mod;
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
