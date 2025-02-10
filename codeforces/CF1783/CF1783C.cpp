#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int res[maxn],a[maxn];
void solve(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>res[i],a[i]=res[i];
	sort(res+1,res+1+n);
	int ans=0;
	for(int i=1;i<=n&&res[i]<=m;i++){
		m-=res[i];
		ans++;//计算出我赢的场数
	}
	if(ans!=0&&ans!=n&&m+res[ans]>=a[ans+1])ans++;//他们还没和我比
	cout<<n+1-ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
