#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int ok=1;
	int ans=-1,mx=-1;
	for(int i=1;i<=n;i++){
		int a,b;cin>>a>>b;
		if(ans==-1){
			ans=a,mx=b;
		}else{
			if(a>=ans&&b>=mx)ok=0;
		}
	}
	if(ok)cout<<ans<<'\n';
	else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
