#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	if(n==0){
		cout<<1<<'\n';
		return ;
	}
	int ans=1;
	int temp=n;
	while(temp){
		int d=temp%10;
		int res=0;
		for(int i=0;i<=d;i++){
			for(int j=0;j<=d-i;j++){
				res++;
			}
		}
		ans*=res;
		temp/=10;
	}
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