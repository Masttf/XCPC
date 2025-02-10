#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){//考虑特殊数字1等1
	int n;cin>>n;
	if(n%2==0){
		cout<<1<<' '<<n/2<<'\n';
	}else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
