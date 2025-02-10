#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k,x;cin>>n>>k>>x;
	if(x!=1){
		cout<<"YES\n";
		cout<<n<<'\n';
		for(int i=1;i<=n;i++)cout<<1<<' ';
		cout<<'\n';
		return ;
	}else{
		if(k==1){
			cout<<"NO\n";
			return ;
		}else if(k==2){
			if(n%2==0){
				cout<<"YES\n";
				cout<<n/2<<'\n';
				for(int i=1;i<=n/2;i++)cout<<2<<' ';
				cout<<'\n';
				return ;
			}else{
				cout<<"NO\n";
				return ;
			}
		}else{
			if(n%2==0){
				cout<<"YES\n";
				cout<<n/2<<'\n';
				for(int i=1;i<=n/2;i++)cout<<2<<' ';
				cout<<'\n';
				return ;
			}else{
				cout<<"YES\n";
				cout<<n/2<<'\n';
				for(int i=1;i<=n/2-1;i++)cout<<2<<' ';
				cout<<3;
				cout<<'\n';
				return ;
			}
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
