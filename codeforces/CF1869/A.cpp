#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n%2==0){
		cout<<2<<'\n';
		cout<<1<<' '<<n<<'\n';
		cout<<1<<' '<<n<<'\n';
	}else{
		cout<<4<<'\n';
		cout<<1<<' '<<n-1<<'\n';
		cout<<1<<' '<<n-1<<'\n';
		cout<<n-1<<' '<<n<<'\n';
		cout<<n-1<<' '<<n<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}