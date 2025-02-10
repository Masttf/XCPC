#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
bool now[maxn];
void solve(){
	int n;cin>>n;
	int ans=-INT_MAX;
	for(int i=1;i<=n;i++)cin>>a[i],ans=max(ans,a[i]);
	
	for(int j=1;j<=3;j++){
		int res=0;
		int ok=0;
		for(int i=j;i<=n;i+=2){
			if(a[i]>=0)res+=a[i],ok=1;
		}
		if(ok)ans=max(ans,res);
	}
	
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
