#include<bits/stdc++.h>
#define int long long
using namespace std;
int res[100];
void solve(){
	int n;cin>>n;
	int sum=1;
	for(int i=1;i<=n;i++)cin>>res[i],sum*=res[i];//乘不变
	cout<<(n-1+sum)*2022<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
