#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	if(n<6){
		cout<<"NO"<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		if(i%3==0)continue;
		for(int j=i+1;j<n-i;j++){
			if(j%3==0)continue;
			int d=n-i-j;
			if(d==i||d==j)continue;
			if(d%3==0)continue;
			cout<<"YES"<<'\n';
			cout<<i<<' '<<j<<' '<<d<<'\n';
			return ;
		}
	}
	cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}