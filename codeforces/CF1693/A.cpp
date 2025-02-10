#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	int flag=1;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int last=n;
	while(last>=1&&a[last]==0)last--;
	for(int i=1;i<=last;i++){
		sum+=a[i];
		if(i!=last&&sum<=0)flag=0;
		if(flag<0)flag=0;
	}
	if(flag&&sum==0)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}