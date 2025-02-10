#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	vector<int>a(5);
	int sum=0;
	for(int i=1;i<=3;i++)cin>>a[i],sum+=a[i];
	for(int j=3;j<=6;j++){
		if(sum%j!=0)continue;
		int cnt=0;
		int ok=1;
		int d=sum/j;
		for(int i=1;i<=3;i++){
			if(a[i]%d!=0)ok=0;
			else cnt+=a[i]/d-1;
		}
		if(ok&&cnt<=3){
			cout<<"YES\n";
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