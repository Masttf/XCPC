#include<bits/stdc++.h>
#define int long long//考虑设第一个是x则最后一个是x+n的和可以推n必须是偶数
using namespace std;
void solve(){
	int n;cin>>n;
	if(n%2!=0){
		cout<<"yes\n";
		int l=1,r=2*n;
		for(int i=1;i<=n;i++){
			cout<<l<<' '<<r<<'\n';
			l++,r-=2;
			if(r<n)r=2*n-1;
		}
	}else cout<<"no\n";
	
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
