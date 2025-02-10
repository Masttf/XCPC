#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	if(n==2&&k==0){
		cout<<"YES\n";
		cout<<1<<' '<<-1<<'\n';
	}else{
		int ans=-1;
		for(int i=1;i<=n;i++){
			if(i*(i-1)/2+(n-i)*(n-i-1)/2==k){
				ans=i;
				break;
			}
		}
		if(ans==-1)cout<<"NO\n";
		else {
			cout<<"YES\n";
			for(int i=1;i<=n;i++){
				if(i<=ans)cout<<1<<' ';
				else cout<<-1<<' ';
			}
			cout<<'\n';
		}
	}
	
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
