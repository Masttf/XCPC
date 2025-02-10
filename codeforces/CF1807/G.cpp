#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];

	if(n==1){
		if(a[1]==1){
			cout<<"YES\n";
		}else cout<<"NO\n";
		return ;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1)cnt++;
	}
	if(cnt==0){
		cout<<"NO\n";
		return ;
	}
	sort(a.begin()+1,a.end());
	int sum=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]>sum){
			cout<<"NO\n";
			return ;
		}
		sum+=a[i];
	}
	cout<<"YES\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}