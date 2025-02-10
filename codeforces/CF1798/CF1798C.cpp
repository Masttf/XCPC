#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200005;
int c[maxn],least[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){//贪心这个能不能跟前面凑
		int a,b;cin>>a>>b;
		c[i]=a*b;
		least[i]=b;
	}
	int ans=1;
	int last=c[1];
	int mi=least[1];
	int ll=least[1];
	for(int i=2;i<=n;i++){
		mi=max(mi,least[i]);
		last=__gcd(last,c[i]);
		ll=ll*least[i]/__gcd(ll,least[i]);
		if(last<mi||last%ll!=0){
			ans++;
			mi=least[i];
			last=c[i];
			ll=least[i];
		}
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
